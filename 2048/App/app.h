/*Class App*/
#ifndef APP_H
#define APP_H

#include "Model/model.h"
#include "Viewmodel/viewmodel.h"
#include "View/view.h"
#include "View/start.h"
#include "App/startcommand/startcommand.h"

class startCommand;

class App
{
public:
    View view;  //GameWindow
    startwindow st;  //StartPage
    std::shared_ptr<Model> model;
    std::shared_ptr<Viewmodel> viewmodel;
    std::shared_ptr<startCommand> sp_startcommand;  //pointer to command for start

public:
    App();
    ~App();
    void run();
};

#endif // APP_H
