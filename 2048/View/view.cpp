#include "view.h"
#include "ui_view.h"
#include <QDebug>
#include <QFont>
#include <QThread>
#include <memory>
#include <QMessageBox>

QColor colors[11]{QColor(212,212,170),QColor(166,74,0),QColor(191,111,48),QColor(255,113,0),
            QColor(255,149,64),QColor(255,177,115),QColor(255,169,0),QColor(191,143,48),
            QColor(166,110,0),QColor(255,190,64),QColor(255,207,115)};

int View::emoji=0;

View::View(QWidget *parent) :  //ctor
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowTitle(QString("2048"));
    this->setFocusPolicy(Qt::StrongFocus);

    QPalette palette(this->palette());
    palette.setColor(QPalette::Background,QColor(255,222,173));
    this->setPalette(palette);


    QFont font;
    font.setFamily("Arial");
    font.setBold(true);
    font.setPixelSize(30);

    score_label = new QLabel("SCORE",this);
    score_label->setGeometry(20,20,200,50);
    score_label->setAlignment(Qt::AlignCenter);
    score_label->setFont(font);

    best_label = new QLabel("BEST",this);
    best_label->setGeometry(240,20,200,50);
    best_label->setAlignment(Qt::AlignCenter);
    best_label->setFont(font);

    now_score = new QLabel("0",this);
    now_score->setGeometry(20,70,200,50);
    now_score->setAlignment(Qt::AlignCenter);
    now_score->setFont(font);

    best_score = new QLabel("0",this);
    best_score->setGeometry(240,70,200,50);
    best_score->setAlignment(Qt::AlignCenter);
    best_score->setFont(font);

    restart_btn = new QPushButton("RESTART",this);
    restart_btn->setGeometry(430,30,200,100);
    restart_btn->setFont(font);
    restart_btn->setStyleSheet("color:#FAF8F1;background-color:#917963");
    restart_btn->setFocusPolicy(Qt::NoFocus);
                
    emoji_btn = new QPushButton("Funny Mode",this);
    emoji_btn->setGeometry(500,200,200,100);
    emoji_btn->setFont(font);
    emoji_btn->setStyleSheet("color:#FAF8F1;background-color:#917963");
    emoji_btn->setFocusPolicy(Qt::NoFocus);
                
    emoji=0;

    int i, j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            square[4*i+j]=new QLabel(this);
            square[4*i+j]->raise();
        }

    for(i=0;i<16;i++)
    {
        anim[i] = new QPropertyAnimation(square[i],"pos");
        group.addAnimation(anim[i]);
    }
    
    for(i=0;i<16;i++)
    {
        comeup[i] = new QPropertyAnimation(square[i],"geometry");
        GroupComeUp.addAnimation(comeup[i]);
    }
    
     for(int i=0;i<11;i++)
    {
        pic[i]=new QMovie(tr("://musicgif/%1.gif").arg(i+2));
        pic[i]->setScaledSize(QSize(80,80));
     }

    connect(restart_btn,SIGNAL(clicked(bool)),this,SLOT(restart_btn_press()));
    connect(emoji_btn,SIGNAL(clicked(bool)),this,SLOT(emoji_btn_press()));

    _ptrViewProSink = std::make_shared<ViewProSinks>(ViewProSinks(this));
    _ptrViewSetSink = std::make_shared<ViewSetSink>(ViewSetSink(this));
    _ptrDirectionSink = std::make_shared<DirectionSink>(DirectionSink(this));
    setMatrix(NULL);
}

View::~View()
{
    delete ui;
}

void View::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void View::mousePressEvent(QMouseEvent *e)
{
    mousePos=e->pos();
}

void View::mouseReleaseEvent(QMouseEvent *e)
{

    float dX = (float)(e->pos().x() - mousePos.x());
    float dY = (float)(e->pos().y() - mousePos.y());
    // 确定手势方向
    if (abs(dX) > abs(dY))
    {
        if (dX < 0)//left
        {
            _ptrDirectionCommand->SetParameter(3);
            _ptrDirectionCommand->Exec();
            paint_square();
        }
        else//right
        {
            _ptrDirectionCommand->SetParameter(4);
            _ptrDirectionCommand->Exec();
            paint_square();
        }
    }
    else
    {
        if (dY < 0)//up
        {
            _ptrDirectionCommand->SetParameter(2);
            _ptrDirectionCommand->Exec();
             paint_square();
        }
        else//down
        {
            _ptrDirectionCommand->SetParameter(1);
            _ptrDirectionCommand->Exec();
            paint_square();
        }
    }
}

void View::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_S||e->key()==Qt::Key_Down)
    {
        _ptrDirectionCommand->SetParameter(1);
        _ptrDirectionCommand->Exec();
         paint_square();
    }
    if(e->key()==Qt::Key_W||e->key()==Qt::Key::Key_Up)
    {
        _ptrDirectionCommand->SetParameter(2);
        _ptrDirectionCommand->Exec();
         paint_square();
    }
    if(e->key()==Qt::Key_A||e->key()==Qt::Key::Key_Left)
    {
        _ptrDirectionCommand->SetParameter(3);
        _ptrDirectionCommand->Exec();
         paint_square();
    }
    if(e->key()==Qt::Key_D||e->key()==Qt::Key::Key_Right)
    {
        _ptrDirectionCommand->SetParameter(4);
        _ptrDirectionCommand->Exec();
         paint_square();
    }
}

void View::setMatrix(std::shared_ptr<SquareMatrix> spMatrix)  //connect data to this
{
    this->_spMatrix = spMatrix;
}

void View::set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand)  //connect command to this
{
    _ptrCommand = ptrCommand;
}

void View::set_ptrDirection(std::shared_ptr<ICommandBase> ptrDirection)
{
    _ptrDirectionCommand = ptrDirection;
}

std::shared_ptr<IPropertyNotification> View::getPtrViewProSink(void)  //return property notification
{
    return std::static_pointer_cast<IPropertyNotification>(_ptrViewProSink);
}

std::shared_ptr<ICommandNotification> View::getPtrViewSetSink(void)  //return command notifycation
{

    return std::static_pointer_cast<ICommandNotification>(_ptrViewSetSink);
}

std::shared_ptr<ICommandNotification> View::getDirectionSink(void)
{
    return std::static_pointer_cast<ICommandNotification>(_ptrDirectionSink);
}


void View::paint_square()
{
    QFont font;
    font.setFamily("Consolas");
    font.setBold(true);
    font.setPixelSize(35);

    QPalette palette;

    int i, j;
    for(i=0;i<16;i++)
    {
        anim[i]->setDuration(150);
        anim[i]->setStartValue(QPoint(100+90*(i%4),200+90*(i/4)));
        anim[i]->setEndValue(QPoint(100+90*(_spMatrix->getPos(i)%4),200+90*(_spMatrix->getPos(i)/4)));
    }
    group.start();

    sleep(200);

    now_score->setText(QString::number(_spMatrix->getScore()));
    best_score->setText(QString::number(_spMatrix->getBest()));

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            if(emoji==0)
            {
                if(this->_spMatrix->getChildNumber(i,j) == 0)
                     square[4*i+j]->hide();
                else
                {
                     square[4*i+j]->setGeometry((100+(90*j)),(200+(90*i)),80,80);
                     square[4*i+j]->setText(QString::number(std::abs(this->_spMatrix->getChildNumber(i,j))));
                     palette.setColor(QPalette::Background,colors[get_color(std::abs(this->_spMatrix->getChildNumber(i,j)))]);
                     square[4*i+j]->setAutoFillBackground(true);
                     square[4*i+j]->setAlignment(Qt::AlignCenter);
                     square[4*i+j]->setPalette(palette);
                     square[4*i+j]->setFont(font);
                     square[4*i+j]->show();
                     if(_spMatrix->getChildNumber(i,j)<0)
                     {
                         comeup[4*i+j]->setDuration(200);
                         comeup[4*i+j]->setStartValue(QRect((100+(90*j))-10,(200+(90*i))-10,100,100));
                         comeup[4*i+j]->setEndValue(QRect((100+(90*j)),(200+(90*i)),80,80));
                      }
                      else
                      {
                         comeup[4*i+j]->setDuration(200);
                         comeup[4*i+j]->setStartValue(QRect((100+(90*j)),(200+(90*i)),80,80));
                         comeup[4*i+j]->setEndValue(QRect((100+(90*j)),(200+(90*i)),80,80));
                      }
                }
            }
            else if(emoji==1)
            {
                if(this->_spMatrix->getChildNumber(i,j) == 0)
                   square[4*i+j]->hide();
               else
               {
                   square[4*i+j]->setGeometry((100+(90*j)),(200+(90*i)),80,80);
                   square[4*i+j]->setMovie(pic[get_color(std::abs(this->_spMatrix->getChildNumber(i,j)))]);

                   pic[get_color(std::abs(this->_spMatrix->getChildNumber(i,j)))]->start();
                   square[4*i+j]->show();
               }
            }  
        }
    GroupComeUp.start();
    if(_spMatrix->LoseSignal()==1)
    {
        QMessageBox MSG;
        MSG.setText("You Lose!");
        MSG.exec();
    }
    if(_spMatrix->WinSignal()==1)
    {
        QMessageBox MSG;
        MSG.setText("You Win!");
        MSG.exec();
    }
}

void View::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev);
    int i,j;
    QPainter painter(this);
    QBrush brush(QColor(124,99,84));
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRect(90,190,370,370);
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            painter.setPen(Qt::NoPen);
            brush.setColor(QColor(193,160,117));
            painter.setBrush(brush);
            painter.drawRoundedRect((100+(90*j)),(200+(90*i)),80,80,4,4);
         }
}

int View::get_color(int n)
{
    int i=-1;
    n/=2;
    while(n!=0){
        i++;
        n/=2;
    }
    return i;
}

void View::restart_btn_press()
{
    _ptrCommand->SetParameter(1);
    _ptrCommand->Exec();
    paint_square();
}
void View::emoji_btn_press()
{
    emoji=1;
    _ptrCommand->SetParameter(1);
    _ptrCommand->Exec();
    paint_square();
}
