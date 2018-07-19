#include "viewprosinks.h"


ViewProSinks::ViewProSinks(View *ptr)
{
    ptr_View = ptr;
}

void ViewProSinks::OnPropertyChanged(const std::string &str)
{
    if(str=="SquareMatrix")
    {
        ptr_View->update();
    }
}
