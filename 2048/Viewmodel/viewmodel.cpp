#include "viewmodel.h"

Viewmodel::Viewmodel()
{
    sp_ViewmodelSink_ = std::make_shared<ViewmodelSink>(this);
    sp_LayoutCommand_ = std::make_shared<LayoutCommand>(this);
    sp_DirectionCommand = std::make_shared<DirectionCommand>(this);
}

Viewmodel::~Viewmodel(){}

void Viewmodel::setModel(std::shared_ptr<Model> sp_model)
{
    sp_model_ = sp_model;
    sp_model_->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(sp_ViewmodelSink_));
}

std::shared_ptr<SquareMatrix> Viewmodel::getMatrix()  //get data
{
    return sp_model_->getMatrix();
}

std::shared_ptr<ICommandBase> Viewmodel::getDirectionCommand()
{
    return std::static_pointer_cast<ICommandBase>(sp_DirectionCommand);
}

std::shared_ptr<ICommandBase> Viewmodel::getLayoutCommand()
{
    return std::static_pointer_cast<ICommandBase>(sp_LayoutCommand_);
}

void Viewmodel::layout(int mode)  //change mode
{
    sp_model_->newLayout(mode);
}

void Viewmodel::Direction(int dir)
{
    sp_model_->DirectionChange(dir);
}
