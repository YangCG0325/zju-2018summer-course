#include "start.h"
#include "ui_start.h"
#include <QFont>

startwindow::startwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::startwindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:#FAF8F1");
    QFont font;
    font.setFamily("Arial");
    font.setBold(true);
    font.setPixelSize(65);

    logo_label=new QLabel("2048",this);
   // logo_label->setPixmap(QPixmap("./logo.png"));
    logo_label->setGeometry(0,0,400,150);
    logo_label->setFont(font);
    logo_label->setAlignment(Qt::AlignCenter);
    logo_label->setStyleSheet("color:#746D65");

    font.setPixelSize(26);
    start_btn=new QPushButton("START",this);
    start_btn->setGeometry(50,160,100,60);
    start_btn->setFont(font);
    start_btn->setStyleSheet("color:#FAF8F1;background-color:#917963");


    exit_btn=new QPushButton("EXIT",this);
    exit_btn->setGeometry(250,160,100,60);
    exit_btn->setFont(font);

    exit_btn->setStyleSheet("color:#FAF8F1;background-color:#917963");

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
