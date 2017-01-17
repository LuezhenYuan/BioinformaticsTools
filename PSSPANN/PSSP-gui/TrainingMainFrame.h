#ifndef TRAININGMAINFRAME_H
#define TRAININGMAINFRAME_H
#include "TrainNowFrame.h"
#include <string>
#include <map>
//(*Headers(TrainingMainFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/statline.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)
class TrainingMainFrame;
void start_Training(TrainingMainFrame*,TrainNowFrame*);
class TrainingMainFrame: public wxFrame
{
	public:

		TrainingMainFrame(wxWindow* parent);
		virtual ~TrainingMainFrame();
		std::map<std::string,std::string> vm;
		std::map<wxString,wxString> DataSettings;
		std::map<wxString,wxString> ANNTopology;
		std::map<wxString,wxString> Training;
		friend void start_Training(TrainingMainFrame*,TrainNowFrame*);
		//(*Declarations(TrainingMainFrame)
		wxStaticLine* StaticLine2;
		wxButton* Button4;
		wxButton* Button1;
		wxButton* Button2;
		wxStaticLine* StaticLine5;
		wxButton* Button3;
		wxStaticText* StaticText1;
		wxStaticLine* StaticLine1;
		wxButton* Button5;
		wxFileDialog* FileDialog4;
		wxFileDialog* FileDialog1;
		wxStaticLine* StaticLine3;
		wxFileDialog* FileDialog2;
		wxTextCtrl* TextCtrl1;
		wxFileDialog* FileDialog3;
		wxStaticLine* StaticLine4;
		//*)

	protected:

		//(*Identifiers(TrainingMainFrame)
		static const long ID_STATICLINE1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICLINE3;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_STATICLINE4;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICLINE5;
		static const long ID_BUTTON5;
		static const long ID_STATICLINE2;
		//*)

	private:

		//(*Handlers(TrainingMainFrame)
		void OnTrainfileButton(wxCommandEvent& event);
		void OnvalidatefileButton(wxCommandEvent& event);
		void OnweightfileButton(wxCommandEvent& event);
		void OnbiasfileButton(wxCommandEvent& event);
		void OnStart(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
