#include "directionsink.h"
#include <QString>
#include "View/view.h"

DirectionSink::DirectionSink(View *ptr)
{
    ptr_View = ptr;
}

void DirectionSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="Direction")
    {
        if(bOK==false)
        {
            QMessageBox MSG;
            MSG.setWindowTitle(QString("Error!"));
            MSG.exec();
        }
    }
}
