#include "start.h"
#include "ui_start.h"
#include <QFont>

startwindow::startwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::startwindow)
{
    ui->setupUi(this);
    QFont font;
    font.setFamily("Consolas");
    font.setBold(true);
    font.setPixelSize(30);

    logo_label=new QLabel("2 0 4 8",this);
   // logo_label->setPixmap(QPixmap("./logo.png"));
    logo_label->setGeometry(20,20,200,100);
    logo_label->setFont(font);
    logo_label->setAlignment(Qt::AlignCenter);

    start_btn=new QPushButton("START",this);
    start_btn->setGeometry(30,160,100,60);
    start_btn->setFont(font);


    exit_btn=new QPushButton("EXIT",this);
    exit_btn->setGeometry(160,160,100,60);
    exit_btn->setFont(font);

    connect(start_btn,SIGNAL(clicked()),this,SLOT(start_btn_press()));
    connect(exit_btn,SIGNAL(clicked()),this,SLOT(exit_btn_press()));


}

startwindow::~startwindow()
{
    delete ui;
}
void startwindow::set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand)
{
    _ptrCommand=ptrCommand;
}

void startwindow::start_btn_press()
{
    _ptrCommand->Exec();
//    this->close();
//    game=new gamewindow(this);
//    game->show();
}
void startwindow::exit_btn_press()
{
    qApp->exit(0);
//    this->close();
}
