/*StartPage, no more change*/
#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include "View/view.h"

namespace Ui {
class startwindow;
}

class startwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit startwindow(QWidget *parent = 0);
   void set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand);
    ~startwindow();
private slots:
    void start_btn_press();
    void exit_btn_press();

private:
    Ui::startwindow *ui;
    QLabel *logo_label;
    QPushButton * start_btn;
    QPushButton *exit_btn;
    View *game;
    std::shared_ptr<ICommandBase> _ptrCommand;
};

#endif // STARTWINDOW_H
