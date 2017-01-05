#include "TrainingDialog.h"

//(*InternalHeaders(TrainingDialog)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(TrainingDialog)
const long TrainingDialog::ID_STATICTEXT1 = wxNewId();
const long TrainingDialog::ID_CHOICE1 = wxNewId();
const long TrainingDialog::ID_STATICTEXT2 = wxNewId();
const long TrainingDialog::ID_CHOICE2 = wxNewId();
const long TrainingDialog::ID_STATICTEXT3 = wxNewId();
const long TrainingDialog::ID_TEXTCTRL2 = wxNewId();
const long TrainingDialog::ID_STATICTEXT4 = wxNewId();
const long TrainingDialog::ID_TEXTCTRL1 = wxNewId();
const long TrainingDialog::ID_STATICTEXT5 = wxNewId();
const long TrainingDialog::ID_CHOICE5 = wxNewId();
const long TrainingDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(TrainingDialog,wxDialog)
	//(*EventTable(TrainingDialog)
	//*)
END_EVENT_TABLE()

TrainingDialog::TrainingDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(TrainingDialog)
	wxGridSizer* GridSizer1;

	Create(parent, wxID_ANY, _("Training"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	GridSizer1 = new wxGridSizer(6, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("WeightAvailable"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	GridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->SetSelection( Choice1->Append(_("true")) );
	Choice1->Append(_("false"));
	GridSizer1->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("WeightbiasAvailable"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice2 = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	Choice2->SetSelection( Choice2->Append(_("true")) );
	Choice2->Append(_("false"));
	GridSizer1->Add(Choice2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Error"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	GridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("0.1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	GridSizer1->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("MaxIteration"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	GridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("1000"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	GridSizer1->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Validation"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	GridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice5 = new wxChoice(this, ID_CHOICE5, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
	Choice5->SetSelection( Choice5->Append(_("true")) );
	Choice5->Append(_("false"));
	GridSizer1->Add(Choice5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	GridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(GridSizer1);
	GridSizer1->Fit(this);
	GridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TrainingDialog::OnQuit);
	//*)
}

TrainingDialog::~TrainingDialog()
{
	//(*Destroy(TrainingDialog)
	//*)
}


void TrainingDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}
