#include "layoutcommand.h"
#include "Viewmodel/viewmodel.h"

LayoutCommand::LayoutCommand(Viewmodel *ptr_Viewmodel)  //get a pointer to viewmodel
{
    ptr_Viewmodel_ = ptr_Viewmodel;
}

void LayoutCommand::SetParameter(const int &param)  //simply assign
{
    mode = param;
}

void LayoutCommand::Exec()
{
    ptr_Viewmodel_->layout_command(mode);  //change mode
    ptr_Viewmodel_->Fire_OnCommandComplete("layoutcommand", true); //execute successfully
}
