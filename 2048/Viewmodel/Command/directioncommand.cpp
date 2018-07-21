#include "directioncommand.h"
#include "Viewmodel/viewmodel.h"

DirectionCommand::DirectionCommand(Viewmodel *ptr_Viewmodel)
{
    ptr_Viewmodel_ = ptr_Viewmodel;
}

void DirectionCommand::SetParameter(const int &param)
{
    dir = param;
}

void DirectionCommand::Exec()
{
    ptr_Viewmodel_->Direction(dir);
    ptr_Viewmodel_->Fire_OnCommandComplete("Direction", true);
}
