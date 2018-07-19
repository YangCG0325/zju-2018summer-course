#ifndef VIEWPROSINKS_H
#define VIEWPROSINKS_H

#include "Common/etlbase.h"
#include "View/view.h"

class View;

class ViewProSinks : public IPropertyNotification
{
public:
    ViewProSinks(View *ptr);
    virtual void OnPropertyChanged(const std::string& str);

private:
    View *ptr_View;
};

#endif // VIEWPROSINKS_H
