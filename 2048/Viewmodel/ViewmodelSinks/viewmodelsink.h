#ifndef VIEWMODELSINK_H
#define VIEWMODELSINK_H

#include "Common/etlbase.h"

class Viewmodel;

class ViewmodelSink : public IPropertyNotification
{
public:
    ViewmodelSink(Viewmodel *ptr);
    virtual void OnPropertyChanged(const std::string& str);

private:
    Viewmodel *ptr_Viewmodel;
};

#endif // VIEWMODELSINK_H
