#ifndef TRAINNOWFRAME_H
#define TRAINNOWFRAME_H
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
#define TIMER_ID 1000
#include <wx/timer.h>
#include <queue>
#include <map>
#include <boost/thread/shared_mutex.hpp>
//(*Headers(TrainNowFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/statline.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class TrainNowFrame: public wxFrame
{
	public:

		TrainNowFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        void OnTimer(wxTimerEvent& event);

		virtual ~TrainNowFrame();

		//(*Declarations(TrainNowFrame)
		wxStaticLine* StaticLine6;
		wxStaticLine* StaticLine2;
		wxTextCtrl* TextCtrliteration;
		wxTextCtrl* TextCtrlerror;
		wxButton* Button4;
		wxButton* Button1;
		wxButton* Button2;
		wxStaticLine* StaticLine5;
		wxButton* Button3;
		wxTextCtrl* TextCtrlthreshold;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxTextCtrl* Textvderror;
		wxStaticLine* StaticLine1;
		wxTextCtrl* TextCtrllog;
		wxFileDialog* FileDialog1;
		wxStaticLine* StaticLine3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText2;
		wxStaticLine* StaticLine4;
		//*)
        boost::mutex i_mutex;
        boost::shared_mutex pause_mutex;
        //variables in thread
        std::queue<std::string> message_1,message_2,message_3,message_4,message_5;
        bool m_pause,m_quit;

	protected:

		//(*Identifiers(TrainNowFrame)
		static const long ID_STATICLINE2;
		static const long ID_STATICLINE5;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICLINE6;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL5;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICLINE4;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICLINE3;
		//*)

	private:

	    //Message store for multithread usage

	    wxTimer m_timer;
		//(*Handlers(TrainNowFrame)
		void OnPause(wxCommandEvent& event);
		void OnStop(wxCommandEvent& event);
		void OnSave_log(wxCommandEvent& event);
		void OnClear_log(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
