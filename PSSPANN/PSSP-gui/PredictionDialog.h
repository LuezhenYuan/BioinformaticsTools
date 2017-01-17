#ifndef PREDICTIONDIALOG_H
#define PREDICTIONDIALOG_H

//(*Headers(PredictionDialog)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
//*)

class PredictionDialog: public wxDialog
{
	public:

		PredictionDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~PredictionDialog();

		//(*Declarations(PredictionDialog)
		wxButton* Button1;
		wxChoice* Choice2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxChoice* Choice1;
		wxTextCtrl* TextCtrl1;
		wxStaticText* StaticText2;
		//*)

	protected:

		//(*Identifiers(PredictionDialog)
		static const long ID_STATICTEXT1;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(PredictionDialog)
		void OnQuit(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
