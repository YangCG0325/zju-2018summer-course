#ifndef DIRECTIONCOMMAND_H
#define DIRECTIONCOMMAND_H

#include "Common/etlbase.h"

class Viewmodel;

class DirectionCommand : public ICommandBase
{
public:
    DirectionCommand(Viewmodel *ptr_viewmodel);
    virtual void SetParameter(const int& param);
    virtual void Exec();

private:
    Viewmodel *ptr_Viewmodel_;
    int dir;
};

#endif // DIRECTIONCOMMAND_H
