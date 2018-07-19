#include "viewsetsink.h"
#include <QString>

ViewSetSink::ViewSetSink(View *ptr)
{
    ptr_View = ptr;
}

void ViewSetSink::OnCommandComplete(const std::string &str, bool bOK)
{
    if(str=="layoutCommand")
    {
        if(bOK==false)
        {
            QMessageBox MSG;
            MSG.setWindowTitle(QString("Error!"));
            MSG.exec();
        }
    }
}
