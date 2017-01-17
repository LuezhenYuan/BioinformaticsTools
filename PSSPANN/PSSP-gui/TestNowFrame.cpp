#include "TestNowFrame.h"
#include <vector>
#include <fstream>
#include <string>
//(*InternalHeaders(TestNowFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(TestNowFrame)
const long TestNowFrame::ID_STATICLINE1 = wxNewId();
const long TestNowFrame::ID_STATICTEXT1 = wxNewId();
const long TestNowFrame::ID_TEXTCTRL1 = wxNewId();
const long TestNowFrame::ID_STATICTEXT2 = wxNewId();
const long TestNowFrame::ID_TEXTCTRL2 = wxNewId();
const long TestNowFrame::ID_STATICLINE2 = wxNewId();
const long TestNowFrame::ID_STATICTEXT3 = wxNewId();
const long TestNowFrame::ID_TEXTCTRL3 = wxNewId();
const long TestNowFrame::ID_STATICTEXT4 = wxNewId();
const long TestNowFrame::ID_TEXTCTRL4 = wxNewId();
const long TestNowFrame::ID_STATICTEXT5 = wxNewId();
const long TestNowFrame::ID_TEXTCTRL5 = wxNewId();
const long TestNowFrame::ID_STATICLINE3 = wxNewId();
const long TestNowFrame::ID_STATICTEXT6 = wxNewId();
const long TestNowFrame::ID_BUTTON1 = wxNewId();
const long TestNowFrame::ID_STATICLINE6 = wxNewId();
const long TestNowFrame::ID_TEXTCTRL6 = wxNewId();
const long TestNowFrame::ID_STATICLINE4 = wxNewId();
const long TestNowFrame::ID_TEXTCTRL7 = wxNewId();
const long TestNowFrame::ID_STATICLINE5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(TestNowFrame,wxFrame)
	//(*EventTable(TestNowFrame)
	//*)
	EVT_TIMER(TIMER2_ID, TestNowFrame::OnTimer)
END_EVENT_TABLE()

TestNowFrame::TestNowFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size):m_pause(false),m_quit(false),m_timer(this, TIMER2_ID)
{
	//(*Initialize(TestNowFrame)
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, _("Testing"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	BoxSizer1->Add(StaticLine1, 0, wxALL|wxEXPAND, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Error"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlerror = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer2->Add(TextCtrlerror, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Q3"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer2->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlQ3 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer2->Add(TextCtrlQ3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	BoxSizer1->Add(StaticLine2, 0, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("CC_H"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer3->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlCC_H = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer3->Add(TextCtrlCC_H, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("CC_E"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer3->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlCC_E = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	BoxSizer3->Add(TextCtrlCC_E, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("CC_C"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer3->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlCC_C = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	BoxSizer3->Add(TextCtrlCC_C, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine3 = new wxStaticLine(this, ID_STATICLINE3, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
	BoxSizer1->Add(StaticLine3, 0, wxALL|wxEXPAND, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Secondary Structure"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer4->Add(StaticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer4->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine6 = new wxStaticLine(this, ID_STATICLINE6, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE6"));
	BoxSizer1->Add(StaticLine6, 0, wxALL|wxEXPAND, 5);
	TextCtrlSS = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxSize(500,200), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	BoxSizer1->Add(TextCtrlSS, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine4 = new wxStaticLine(this, ID_STATICLINE4, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE4"));
	BoxSizer1->Add(StaticLine4, 0, wxALL|wxEXPAND, 5);
	TextCtrllog = new wxTextCtrl(this, ID_TEXTCTRL7, _("log"), wxDefaultPosition, wxSize(500,50), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	BoxSizer1->Add(TextCtrllog, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine5 = new wxStaticLine(this, ID_STATICLINE5, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE5"));
	BoxSizer1->Add(StaticLine5, 0, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TestNowFrame::OnQuit);
	//*)
	m_timer.Start(100);//0.1 second interval, start now!!
}

TestNowFrame::~TestNowFrame()
{
	//(*Destroy(TestNowFrame)
	//*)
}

void TestNowFrame::OnTimer(wxTimerEvent& event){
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
            TextCtrlQ3->SetValue(message_3.front());//!!attention, here is string not wxstring!!!
            TextCtrlQ3->Refresh();
            TextCtrlQ3->Update();
            message_3.pop();
        }
        if(!message_4.empty()){
            TextCtrlCC_H->SetValue(message_4.front());//!!attention, here is string not wxstring!!!
            TextCtrlCC_H->Refresh();
            TextCtrlCC_H->Update();
            message_4.pop();
        }
        if(!message_5.empty()){
            TextCtrlCC_E->SetValue(message_5.front());//!!attention, here is string not wxstring!!!
            TextCtrlCC_E->Refresh();
            TextCtrlCC_E->Update();
            message_5.pop();
        }
        if(!message_6.empty()){
            TextCtrlCC_C->SetValue(message_6.front());//!!attention, here is string not wxstring!!!
            TextCtrlCC_C->Refresh();
            TextCtrlCC_C->Update();
            message_6.pop();
        }
        if(!message_7.empty()){
            TextCtrlSS->AppendText(message_7.front()+"\n");//!!attention, here is string not wxstring!!!
            TextCtrlSS->Refresh();
            TextCtrlSS->Update();
            message_7.pop();
        }
    }
}

void TestNowFrame::OnQuit(wxCommandEvent& event)
{
    m_timer.Stop();
    Close();
}
