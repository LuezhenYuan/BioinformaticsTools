/***************************************************************
 * Name:      PSSP_protoMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Luezhen (lzyuan@zju.edu.cn)
 * Created:   2017-01-04
 * Copyright: Luezhen (https://github.com/LuezhenYuan)
 * License:
 **************************************************************/

#include "PSSP_protoMain.h"
#include <wx/msgdlg.h>
#include "MainFrame.h"
//#include <wx/app.h>
//(*InternalHeaders(PSSP_protoDialog)
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(PSSP_protoDialog)
const long PSSP_protoDialog::ID_STATICTEXT1 = wxNewId();
const long PSSP_protoDialog::ID_BUTTON1 = wxNewId();
const long PSSP_protoDialog::ID_STATICLINE1 = wxNewId();
const long PSSP_protoDialog::ID_BUTTON3 = wxNewId();
const long PSSP_protoDialog::ID_STATICLINE2 = wxNewId();
const long PSSP_protoDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PSSP_protoDialog,wxDialog)
    //(*EventTable(PSSP_protoDialog)
    //*)
END_EVENT_TABLE()

PSSP_protoDialog::PSSP_protoDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(PSSP_protoDialog)
    Create(parent, wxID_ANY, _("PSSP-gui"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Welcome to\nPSSP-gui"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !StaticText1Font.Ok() ) StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText1Font.SetPointSize(20);
    StaticText1->SetFont(StaticText1Font);
    BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    Button1 = new wxButton(this, ID_BUTTON1, _("About"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer2->Add(StaticLine1, 0, wxALL|wxEXPAND, 4);
    Button3 = new wxButton(this, ID_BUTTON3, _("LogIn"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer2->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    BoxSizer2->Add(StaticLine2, 0, wxALL|wxEXPAND, 4);
    Button2 = new wxButton(this, ID_BUTTON2, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PSSP_protoDialog::OnAbout);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PSSP_protoDialog::OnLogin);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PSSP_protoDialog::OnQuit);
    //*)
}

PSSP_protoDialog::~PSSP_protoDialog()
{
    //(*Destroy(PSSP_protoDialog)
    //*)
}

void PSSP_protoDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void PSSP_protoDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    msg.append("\nPSSP-gui is a GUI version for protein secondary structure prediction.");
    wxMessageBox(msg, _("Welcome to..."));
}

void PSSP_protoDialog::OnLogin(wxCommandEvent& event)
{
    //MainFrame* main_frm = new MainFrame(this);
    //SetTopWindow(main_frm);
    //windowList->Append(main_frm);
    //main_frm->Show(true);
    wxsmain_frame = true;
    Close();
    //...waiting for new frame
}
