/*class viewmodel*/
#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "Model/model.h"
#include "Common/etlbase.h"
#include "ViewmodelSinks/viewmodelsink.h"
#include "Command/layoutcommand.h"
#include "Command/directioncommand.h"

class Viewmodel : public Proxy_PropertyNotification<Viewmodel>, public Proxy_CommandNotification<Viewmodel> //property and command handle
{
public:
    Viewmodel();
    ~Viewmodel();
    void setModel(std::shared_ptr<Model> sp_model); //connect model
    std::shared_ptr<SquareMatrix> getMatrix();
    std::shared_ptr<ICommandBase> getLayoutCommand();
    std::shared_ptr<ICommandBase> getDirectionCommand();
    void layout_command(int mode);
    void Direction_command(int dir);
private:
    std::shared_ptr<Model> sp_model_;
    std::shared_ptr<ViewmodelSink> sp_ViewmodelSink_;
    std::shared_ptr<LayoutCommand> sp_LayoutCommand_;
    std::shared_ptr<DirectionCommand> sp_DirectionCommand;
};

#endif // VIEWMODEL_H
