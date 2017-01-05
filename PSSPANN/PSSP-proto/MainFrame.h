#ifndef MAINFRAME_H
#define MAINFRAME_H
#include <map>
#include <string>
//(*Headers(MainFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/dirdlg.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
//*)

class MainFrame: public wxFrame
{
	public:

		MainFrame(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~MainFrame();
		std::map<wxString,wxString> DataSettings;
		std::map<wxString,wxString> ANNTopology;
		std::map<wxString,wxString> Training;
		std::map<wxString,wxString> Prediction;
		std::map<wxString,wxString> Test;
		//(*Declarations(MainFrame)
		wxMenuItem* MenuItem2;
		wxMenuItem* MenuItem1;
		wxGridSizer* GridSizer1;
		wxTextCtrl* TextCtrl3;
		wxMenu* Menu1;
		wxChoice* Choice3;
		wxMenu* Menu3;
		wxButton* Button1;
		wxButton* Button2;
		wxChoice* Choice2;
		wxDirDialog* DirDialog1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText10;
		wxChoice* Choice4;
		wxStaticText* StaticText3;
		wxMenuItem* MenuItem3;
		wxChoice* Choice1;
		wxStaticText* StaticText8;
		wxStaticText* StaticText7;
		wxTextCtrl* TextCtrl1;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxMenuBar* MenuBar1;
		wxStaticText* StaticText2;
		wxMenu* Menu2;
		wxStaticText* StaticText9;
		wxTextCtrl* TextCtrl2;
		wxStaticText* StaticText11;
		//*)

	protected:

		//(*Identifiers(MainFrame)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT3;
		static const long ID_CHOICE2;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT8;
		static const long ID_CHOICE3;
		static const long ID_STATICTEXT9;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT10;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT11;
		static const long ID_CHOICE4;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICTEXT5;
		static const long SubMenuTrain;
		static const long SubMenuTest;
		static const long SubMenuPredict;
		//*)

	private:

		//(*Handlers(MainFrame)
		void OnSubMenuPredictionSelected(wxCommandEvent& event);
		void OnSubMenuTrainSelected(wxCommandEvent& event);
		void OnSubMenuTestSelected(wxCommandEvent& event);
		void OnSaveButton(wxCommandEvent& event);
		void OnQuitButton(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
