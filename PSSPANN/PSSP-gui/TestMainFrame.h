#ifndef TESTMAINFRAME_H
#define TESTMAINFRAME_H
#include "TestNowFrame.h"
//(*Headers(TestMainFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/statline.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)
class TestMainFrame;
void start_Test(TestMainFrame*,TestNowFrame*);
class TestMainFrame: public wxFrame
{
	public:

		TestMainFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~TestMainFrame();
		std::map<std::string,std::string> vm;
		std::map<wxString,wxString> DataSettings;
		std::map<wxString,wxString> ANNTopology;
		std::map<wxString,wxString> Test;
		friend void start_Test(TestMainFrame*,TestNowFrame*);
		//(*Declarations(TestMainFrame)
		wxStaticLine* StaticLine2;
		wxButton* Button4;
		wxButton* Button1;
		wxButton* Button2;
		wxStaticLine* StaticLine5;
		wxButton* Button3;
		wxStaticLine* StaticLine1;
		wxFileDialog* FileDialog1;
		wxStaticLine* StaticLine3;
		wxFileDialog* FileDialog2;
		wxTextCtrl* TextCtrl1;
		wxFileDialog* FileDialog3;
		wxStaticText* StaticText2;
		wxStaticLine* StaticLine4;
		//*)

	protected:

		//(*Identifiers(TestMainFrame)
		static const long ID_STATICLINE1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICLINE2;
		static const long ID_BUTTON3;
		static const long ID_STATICLINE3;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICLINE4;
		static const long ID_BUTTON4;
		static const long ID_STATICLINE5;
		//*)

	private:

		//(*Handlers(TestMainFrame)
		void OnStart(wxCommandEvent& event);
		void OnWeightfile(wxCommandEvent& event);
		void OnBiasfile(wxCommandEvent& event);
		void OnTestfile(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
