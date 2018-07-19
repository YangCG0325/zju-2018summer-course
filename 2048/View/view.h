/*class view, THAT IS OUR GAMEWINDOW*/
#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include <QLabel>
#include <memory>
#include "Common/square.h"
#include "Common/etlbase.h"
#include "View/ViewSinks/viewprosinks.h"
#include "View/ViewSinks/viewsetsink.h"
#include "View/ViewSinks/directionsink.h"

class ViewProSinks;
class ViewSetSink;
class DirectionSink;

namespace Ui {
class View;
}

class View : public QMainWindow
{
    Q_OBJECT

public: 
    explicit View(QWidget *parent = 0);
    ~View();

    void keyPressEvent(QKeyEvent *e);
    void setMatrix(std::shared_ptr<SquareMatrix> spMatrix);  //connect to data
    void set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand); //connect to command ?
    void set_ptrDirection(std::shared_ptr<ICommandBase> ptrDirection);

    std::shared_ptr<IPropertyNotification> getPtrViewProSink(void); //return two command pointer ?
    std::shared_ptr<ICommandNotification> getPtrViewSetSink(void);
    std::shared_ptr<ICommandNotification> getDirectionSink(void);

    void paintEvent(QPaintEvent*);
private:
    Ui::View *ui;
    std::shared_ptr<SquareMatrix> _spMatrix;
    std::shared_ptr<ViewProSinks> _ptrViewProSink;
    std::shared_ptr<ViewSetSink> _ptrViewSetSink;
    std::shared_ptr<DirectionSink> _ptrDirectionSink;
    std::shared_ptr<ICommandBase> _ptrDirectionCommand;
    std::shared_ptr<ICommandBase> _ptrCommand;

    QLabel *score_label;    //显示当前分数
    QLabel *best_label;     //显示最高分数
    QLabel *now_score;
    QLabel *best_score;
    int get_color(int n);
};

#endif // VIEW_H
