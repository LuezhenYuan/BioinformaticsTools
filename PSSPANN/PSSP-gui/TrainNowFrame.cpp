#include "TrainNowFrame.h"
#include <vector>
#include <fstream>
#include <string>
//(*InternalHeaders(TrainNowFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(TrainNowFrame)
const long TrainNowFrame::ID_STATICLINE2 = wxNewId();
const long TrainNowFrame::ID_STATICLINE5 = wxNewId();
const long TrainNowFrame::ID_STATICTEXT2 = wxNewId();
const long TrainNowFrame::ID_TEXTCTRL2 = wxNewId();
const long TrainNowFrame::ID_STATICTEXT3 = wxNewId();
const long TrainNowFrame::ID_TEXTCTRL3 = wxNewId();
const long TrainNowFrame::ID_STATICTEXT4 = wxNewId();
const long TrainNowFrame::ID_TEXTCTRL4 = wxNewId();
const long TrainNowFrame::ID_STATICLINE6 = wxNewId();
const long TrainNowFrame::ID_STATICTEXT5 = wxNewId();
const long TrainNowFrame::ID_TEXTCTRL5 = wxNewId();
const long TrainNowFrame::ID_STATICLINE1 = wxNewId();
const long TrainNowFrame::ID_STATICTEXT1 = wxNewId();
const long TrainNowFrame::ID_BUTTON1 = wxNewId();
const long TrainNowFrame::ID_BUTTON2 = wxNewId();
const long TrainNowFrame::ID_STATICLINE4 = wxNewId();
const long TrainNowFrame::ID_BUTTON3 = wxNewId();
const long TrainNowFrame::ID_BUTTON4 = wxNewId();
const long TrainNowFrame::ID_TEXTCTRL1 = wxNewId();
const long TrainNowFrame::ID_STATICLINE3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(TrainNowFrame,wxFrame)
	//(*EventTable(TrainNowFrame)
	//*)
	EVT_TIMER(TIMER_ID, TrainNowFrame::OnTimer)
END_EVENT_TABLE()

TrainNowFrame::TrainNowFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size):m_pause(false),m_quit(false),m_timer(this, TIMER_ID)
{
	//(*Initialize(TrainNowFrame)
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer1;

	Create(parent, wxID_ANY, _("Training"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	BoxSizer1->Add(StaticLine2, 0, wxALL|wxEXPAND, 5);
	StaticLine5 = new wxStaticLine(this, ID_STATICLINE5, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE5"));
	BoxSizer1->Add(StaticLine5, 0, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Cycle:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer3->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrliteration = new wxTextCtrl(this, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer3->Add(TextCtrliteration, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Error:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer3->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlerror = new wxTextCtrl(this, ID_TEXTCTRL3, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer3->Add(TextCtrlerror, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Threshold:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer3->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlthreshold = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	BoxSizer3->Add(TextCtrlthreshold, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine6 = new wxStaticLine(this, ID_STATICLINE6, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE6"));
	BoxSizer1->Add(StaticLine6, 0, wxALL|wxEXPAND, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Validate error"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer4->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Textvderror = new wxTextCtrl(this, ID_TEXTCTRL5, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	BoxSizer4->Add(Textvderror, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	BoxSizer1->Add(StaticLine1, 0, wxALL|wxEXPAND, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Log:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("Save log"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("Clear log"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine4 = new wxStaticLine(this, ID_STATICLINE4, wxDefaultPosition, wxSize(10,-1), wxLI_VERTICAL, _T("ID_STATICLINE4"));
	BoxSizer2->Add(StaticLine4, 0, wxALL|wxEXPAND, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("Pause"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(Button3, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button4 = new wxButton(this, ID_BUTTON4, _("Stop"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer2->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL, 5);
	TextCtrllog = new wxTextCtrl(this, ID_TEXTCTRL1, _("Log"), wxDefaultPosition, wxSize(500,50), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer1->Add(TextCtrllog, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
	StaticLine3 = new wxStaticLine(this, ID_STATICLINE3, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
	BoxSizer1->Add(StaticLine3, 0, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	FileDialog1 = new wxFileDialog(this, _("Save log file"), wxEmptyString, wxEmptyString, _("txt(*.txt)|*.txt|all(*.*)|*.*"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TrainNowFrame::OnSave_log);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TrainNowFrame::OnClear_log);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TrainNowFrame::OnPause);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TrainNowFrame::OnStop);
	//*)
	//try for mathplot
	/*
	std::vector<double> xs,ys;
	xs.push_back(1);xs.push_back(2);xs.push_back(3);
	ys.push_back(2);ys.push_back(1);ys.push_back(3);
	mpFXYVector* data_layer=new mpFXYVector();
	MathPlot1->AddLayer(data_layer);
	data_layer->SetData(xs,ys);
	MathPlot1->Fit();
	*/
	m_timer.Start(100);//0.1 second interval, start now!!
}

TrainNowFrame::~TrainNowFrame()
{
	//(*Destroy(TrainNowFrame)
	//*)
}

void TrainNowFrame::OnTimer(wxTimerEvent& event){
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
            TextCtrliteration->SetValue(message_3.front());//!!attention, here is string not wxstring!!!
            TextCtrliteration->Refresh();
            TextCtrliteration->Update();
            message_3.pop();
        }
        if(!message_4.empty()){
            Textvderror->SetValue(message_4.front());//!!attention, here is string not wxstring!!!
            Textvderror->Refresh();
            Textvderror->Update();
            message_4.pop();
        }
        if(!message_5.empty()){
            TextCtrlthreshold->SetValue(message_5.front());//!!attention, here is string not wxstring!!!
            TextCtrlthreshold->Refresh();
            TextCtrlthreshold->Update();
            message_5.pop();
            //change the ui
            Button3->Hide();
            Button4->SetLabel("Quit");
        }
    }
}

void TrainNowFrame::OnPause(wxCommandEvent& event)
{
    {
        boost::lock_guard<boost::shared_mutex> lock(this->pause_mutex);
        if(m_pause==false){m_pause=true;Button3->SetLabel("Continue");}
        else{m_pause=false;Button3->SetLabel("Pause");}
    }
}

void TrainNowFrame::OnStop(wxCommandEvent& event)
{
    if(Button4->GetLabel()=="Stop")
    {
        boost::lock_guard<boost::shared_mutex> lock(this->pause_mutex);
        m_pause=true;
        Button3->Hide();
        m_quit=true;
        Button4->SetLabel("Quit");
        //this->Fit();
    }
    else{
        //quit
        m_timer.Stop();
        Close();
    }
}

void TrainNowFrame::OnSave_log(wxCommandEvent& event)
{
    if(FileDialog1->ShowModal()==wxID_CANCEL)
        return;
    wxString file_tmp = FileDialog1->GetPath();
    std::string fileName(file_tmp.fn_str());
    std::ofstream out(fileName);
    out<<TextCtrllog->GetValue().ToStdString();
    out<<"\n";
    out.close();
}

void TrainNowFrame::OnClear_log(wxCommandEvent& event)
{
    TextCtrllog->SetValue("");
}
