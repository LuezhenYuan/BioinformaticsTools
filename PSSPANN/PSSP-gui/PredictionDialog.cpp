#include "PredictionDialog.h"

//(*InternalHeaders(PredictionDialog)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(PredictionDialog)
const long PredictionDialog::ID_STATICTEXT1 = wxNewId();
const long PredictionDialog::ID_CHOICE1 = wxNewId();
const long PredictionDialog::ID_STATICTEXT2 = wxNewId();
const long PredictionDialog::ID_CHOICE2 = wxNewId();
const long PredictionDialog::ID_STATICTEXT3 = wxNewId();
const long PredictionDialog::ID_TEXTCTRL1 = wxNewId();
const long PredictionDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PredictionDialog,wxDialog)
	//(*EventTable(PredictionDialog)
	//*)
END_EVENT_TABLE()

PredictionDialog::PredictionDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(PredictionDialog)
	wxGridSizer* GridSizer1;

	Create(parent, wxID_ANY, _("Prediction"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	GridSizer1 = new wxGridSizer(4, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("WeightAvailable"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	GridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->SetSelection( Choice1->Append(_("true")) );
	GridSizer1->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("WeightbiasAvailable"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice2 = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	Choice2->SetSelection( Choice2->Append(_("true")) );
	Choice2->Append(_("false"));
	GridSizer1->Add(Choice2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("threshold"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	GridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("0.3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	GridSizer1->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	GridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(GridSizer1);
	GridSizer1->Fit(this);
	GridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PredictionDialog::OnQuit);
	//*)
}

PredictionDialog::~PredictionDialog()
{
	//(*Destroy(PredictionDialog)
	//*)
}


void PredictionDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}
