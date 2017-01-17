#ifndef TESTNOWFRAME_H
#define TESTNOWFRAME_H
#define TIMER2_ID 1002
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
#include <wx/timer.h>
#include <queue>
#include <map>
#include <boost/thread/shared_mutex.hpp>
//(*Headers(TestNowFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class TestNowFrame: public wxFrame
{
	public:

		TestNowFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~TestNowFrame();
		void OnTimer(wxTimerEvent& event);

		//(*Declarations(TestNowFrame)
		wxTextCtrl* TextCtrlSS;
		wxStaticLine* StaticLine6;
		wxStaticLine* StaticLine2;
		wxTextCtrl* TextCtrlQ3;
		wxTextCtrl* TextCtrlerror;
		wxButton* Button1;
		wxStaticLine* StaticLine5;
		wxTextCtrl* TextCtrlCC_E;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxStaticLine* StaticLine1;
		wxTextCtrl* TextCtrlCC_H;
		wxTextCtrl* TextCtrllog;
		wxStaticLine* StaticLine3;
		wxTextCtrl* TextCtrlCC_C;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText2;
		wxStaticText* StaticText6;
		wxStaticLine* StaticLine4;
		//*)
        boost::mutex i_mutex;
        boost::shared_mutex pause_mutex;//not use
        //variables in thread
        std::queue<std::string> message_1,message_2,message_3,message_4,message_5,message_6,message_7;
        bool m_pause,m_quit;
	protected:

		//(*Identifiers(TestNowFrame)
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICLINE2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL5;
		static const long ID_STATICLINE3;
		static const long ID_STATICTEXT6;
		static const long ID_BUTTON1;
		static const long ID_STATICLINE6;
		static const long ID_TEXTCTRL6;
		static const long ID_STATICLINE4;
		static const long ID_TEXTCTRL7;
		static const long ID_STATICLINE5;
		//*)

	private:
        wxTimer m_timer;
		//(*Handlers(TestNowFrame)
		void OnQuit(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
