#include <QApplication>
#include "app.h"

App::App(){}

App::~App(){}

void App::run()
{
    model=std::make_shared<Model>();  //generate three shared_ptr
    viewmodel=std::make_shared<Viewmodel>();
    sp_startcommand = std::make_shared<startCommand>(this);

    viewmodel->setModel(model);  //connect viewmodel and model

    view.set_ptrCommand(viewmodel->getLayoutCommand());  //connnect command and view?
    view.setMatrix(viewmodel->getMatrix());  //connect view and data matrix
    view.set_ptrDirection(viewmodel->getDirectionCommand());

    viewmodel->Exec_layout_command(1);  //set game mode
    viewmodel->AddPropertyNotification(view.getPtrViewProSink());  //property change ?
    viewmodel->AddCommandNotification(view.getPtrViewSetSink());  //command ?
    viewmodel->AddCommandNotification(view.getDirectionSink());
    view.paint_square();
    st.set_ptrCommand(std::static_pointer_cast<ICommandBase>(this->sp_startcommand)); //connect App and StartPage' s command?
    st.show();
}
