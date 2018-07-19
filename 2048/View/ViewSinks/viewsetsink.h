#ifndef VIEWSETSINK_H
#define VIEWSETSINK_H

#include "Common/etlbase.h"
#include <qmessagebox.h>
#include "View/view.h"

class View;
class ViewSetSink : public ICommandNotification
{
public:
    ViewSetSink(View *ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);

private:
    View *ptr_View;
};

#endif // VIEWSETSINK_H
