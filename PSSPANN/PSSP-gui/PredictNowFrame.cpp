#include "PredictNowFrame.h"
#include <vector>
#include <fstream>
#include <string>
//(*InternalHeaders(PredictNowFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(PredictNowFrame)
const long PredictNowFrame::ID_STATICLINE1 = wxNewId();
const long PredictNowFrame::ID_STATICTEXT1 = wxNewId();
const long PredictNowFrame::ID_TEXTCTRL1 = wxNewId();
const long PredictNowFrame::ID_STATICLINE2 = wxNewId();
const long PredictNowFrame::ID_STATICTEXT2 = wxNewId();
const long PredictNowFrame::ID_BUTTON1 = wxNewId();
const long PredictNowFrame::ID_STATICLINE4 = wxNewId();
const long PredictNowFrame::ID_TEXTCTRL2 = wxNewId();
const long PredictNowFrame::ID_STATICLINE5 = wxNewId();
const long PredictNowFrame::ID_TEXTCTRL3 = wxNewId();
const long PredictNowFrame::ID_STATICLINE3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PredictNowFrame,wxFrame)
	//(*EventTable(PredictNowFrame)
	//*)
	EVT_TIMER(TIMER3_ID, PredictNowFrame::OnTimer)
END_EVENT_TABLE()

PredictNowFrame::PredictNowFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size):m_pause(false),m_quit(false),m_timer(this, TIMER3_ID)
{
	//(*Initialize(PredictNowFrame)
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, wxID_ANY, _("Prediction"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	BoxSizer1->Add(StaticLine1, 0, wxALL|wxEXPAND, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Error"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlerror = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer2->Add(TextCtrlerror, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	BoxSizer1->Add(StaticLine2, 0, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Secondary Structure"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer3->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine4 = new wxStaticLine(this, ID_STATICLINE4, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE4"));
	BoxSizer1->Add(StaticLine4, 0, wxALL|wxEXPAND, 5);
	TextCtrlSS = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(500,200), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer1->Add(TextCtrlSS, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine5 = new wxStaticLine(this, ID_STATICLINE5, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE5"));
	BoxSizer1->Add(StaticLine5, 0, wxALL|wxEXPAND, 5);
	TextCtrllog = new wxTextCtrl(this, ID_TEXTCTRL3, _("log"), wxDefaultPosition, wxSize(500,50), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer1->Add(TextCtrllog, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine3 = new wxStaticLine(this, ID_STATICLINE3, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
	BoxSizer1->Add(StaticLine3, 0, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PredictNowFrame::OnQuit);
	//*)
	m_timer.Start(100);//0.1 second interval, start now!!
}

PredictNowFrame::~PredictNowFrame()
{
	//(*Destroy(PredictNowFrame)
	//*)
}

void PredictNowFrame::OnTimer(wxTimerEvent& event){
    //Do some refresh
    {
        boost::lock_guard<boost::mutex> lock(this->i_mutex);
        if(!message_1.empty()){
            TextCtrllog->AppendText(message_1.front());//!!attention, here is string not wxstring!!!
            TextCtrllog->Refresh();
            TextCtrllog->Update();
            message_1.pop();
        }
        if(!message_2.empty()){
            TextCtrlerror->SetValue(message_2.front());//!!attention, here is string not wxstring!!!
            TextCtrlerror->Refresh();
            TextCtrlerror->Update();
            message_2.pop();
        }
        if(!message_3.empty()){
            TextCtrlSS->AppendText(message_3.front());//!!attention, here is string not wxstring!!!
            TextCtrlSS->Refresh();
            TextCtrlSS->Update();
            message_3.pop();
        }
    }
}

void PredictNowFrame::OnQuit(wxCommandEvent& event)
{
    m_timer.Stop();
    Close();
}
