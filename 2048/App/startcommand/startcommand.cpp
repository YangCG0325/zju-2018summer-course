#include "startcommand.h"


startCommand::startCommand(App *ptr_App)
{
    ptrApp = ptr_App;
}

startCommand::~startCommand(){}

void startCommand::SetParameter(const int &param){}

void startCommand::Exec()
{
    ptrApp->st.close();
    ptrApp->view.show();
}
