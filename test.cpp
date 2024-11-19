#include <wx/wx.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit() override
    {
        wxFrame *frame = new wxFrame(nullptr, wxID_ANY, "Hello wxWidgets");
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);