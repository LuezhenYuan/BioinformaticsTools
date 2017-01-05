#ifndef TRAININGDIALOG_H
#define TRAININGDIALOG_H

//(*Headers(TrainingDialog)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
//*)

class TrainingDialog: public wxDialog
{
	public:

		TrainingDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~TrainingDialog();

		//(*Declarations(TrainingDialog)
		wxButton* Button1;
		wxChoice* Choice2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxChoice* Choice5;
		wxChoice* Choice1;
		wxTextCtrl* TextCtrl1;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrl2;
		//*)

	protected:

		//(*Identifiers(TrainingDialog)
		static const long ID_STATICTEXT1;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT5;
		static const long ID_CHOICE5;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(TrainingDialog)
		void OnQuit(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif

