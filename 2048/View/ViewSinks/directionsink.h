#ifndef DIRECTIONSINK_H
#define DIRECTIONSINK_H

#include "Common/etlbase.h"
#include <qmessagebox.h>
#include "View/view.h"

class View;

class DirectionSink : public ICommandNotification
{
public:
    DirectionSink(View *ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);

private:
    View *ptr_View;
};

#endif // DIRECTIONSINK_H
