#include "view.h"
#include "ui_view.h"
#include <QDebug>


View::View(QWidget *parent) :  //ctor
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);

    _ptrViewProSink = std::make_shared<ViewProSinks>(ViewProSinks(this));
    _ptrViewSetSink = std::make_shared<ViewSetSink>(ViewSetSink(this));
    _ptrDirectionSink = std::make_shared<DirectionSink>(DirectionSink(this));
    setMatrix(NULL);
}

View::~View()
{
    delete ui;
}

void View::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_S||e->key()==Qt::Key_Down)
    {
        _ptrDirectionCommand->SetParameter(1);
        _ptrDirectionCommand->Exec();
        View::update();
    }
    if(e->key()==Qt::Key_W||e->key()==Qt::Key::Key_Up)
    {
        _ptrDirectionCommand->SetParameter(2);
        _ptrDirectionCommand->Exec();
        View::update();
    }
    if(e->key()==Qt::Key_A||e->key()==Qt::Key::Key_Left)
    {
        _ptrDirectionCommand->SetParameter(3);
        _ptrDirectionCommand->Exec();
        View::update();
    }
    if(e->key()==Qt::Key_D||e->key()==Qt::Key::Key_Right)
    {
        _ptrDirectionCommand->SetParameter(4);
        _ptrDirectionCommand->Exec();
        View::update();
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
/*
void View::paintEvent(QPaintEvent *)  //paint
{
    QPainter painter(this);
    painter.setBrush(Qt::gray);
    painter.drawRect(this->rect());

    int i, j;
    this->resize(100+80*4,100+80*5);
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            std::string color = this->_spMatrix->getChildColor(i,j);

            if(color=="0")
            {
                QPen pen;
                pen.setWidth(7);
                pen.setBrush(Qt::black);
                painter.setPen(pen);
                painter.setBrush(Qt::white);
                painter.drawEllipse(40+80*j,40+80*i,40,40);
            }
            else if(color=="2")
            {
                QPen pen;
                pen.setWidth(7);
                pen.setBrush(Qt::white);
                painter.setPen(pen);
                painter.setBrush(Qt::black);
                painter.drawEllipse(40+80*j,40+80*i,40,40);
            }
            else
            {
                QPen pen;
                pen.setWidth(7);
                pen.setBrush(Qt::blue);
                painter.setPen(pen);
                painter.setBrush(Qt::red);
                painter.drawEllipse(40+80*j,40+80*i,40,40);
            }

        }

}
*/

void View::paintEvent(QPaintEvent *ev)
{
    int i,j;
    QPainter painter(this);
    QBrush brush(QColor(255,182,193));
    //brush.setColor();
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRect(90,190,370,370);

    for(i=0;i<4;i++)
        for(j=0;j<4;j++){
            if(this->_spMatrix->getChildNumber(i,j) == 0){
                brush.setColor(QColor(139,155,85));
                painter.setBrush(brush);
                painter.drawRoundedRect((100+(90*j)),(200+(90*i)),80,80,4,4);

            }
            else {
                brush.setColor(QColor(173,216,230));
                painter.setBrush(brush);
                painter.setBrush(brush);
                painter.drawRoundedRect((100+(90*j)),(200+(90*i)),80,80,4,4);
                painter.setPen(QColor(0,0,0));
                painter.drawText((100+(90*j)),(200+(90*i)),80,80,Qt::AlignCenter,QString::number(this->_spMatrix->getChildNumber(i,j),10));//(100+(90*i)),(200+(90*j)),80,80,Qt::AlignCenter,QString::number[i][j]);

            }


        }

}
