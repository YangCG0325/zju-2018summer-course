/*mode set*/
#ifndef LAYOUTCOMMAND_H
#define LAYOUTCOMMAND_H

#include "Common/etlbase.h"

class Viewmodel;

class LayoutCommand : public ICommandBase
{
public:
    LayoutCommand(Viewmodel *ptr_Viewmodel);  //connect this function and viewmodel
    virtual void SetParameter(const int& param); //param is new mode number
    virtual void Exec();  //change mode

private:
    Viewmodel *ptr_Viewmodel_;
    int mode;
};

#endif // LAYOUTCOMMAND_H
