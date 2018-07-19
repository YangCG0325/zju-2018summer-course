#include "viewmodelsink.h"
#include "../viewmodel.h"

ViewmodelSink::ViewmodelSink(Viewmodel *ptr)
{
    ptr_Viewmodel = ptr;
}

void ViewmodelSink::OnPropertyChanged(const std::string& str)
{
    ptr_Viewmodel->Fire_OnPropertyChanged(str);
}
