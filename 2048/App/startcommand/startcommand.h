/*Command for StartPage, no more change*/
#ifndef STARTCOMMAND_H
#define STARTCOMMAND_H

#include "Common/etlbase.h"
#include "App/app.h"

class App;

class startCommand : public ICommandBase
{
private:
    App *ptrApp;
public:
    startCommand(App *ptr_App);
    ~startCommand();
    virtual void SetParameter(const int& param);
    virtual void Exec();
};

#endif // STARTCOMMAND_H
