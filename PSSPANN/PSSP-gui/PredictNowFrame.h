#ifndef PREDICTNOWFRAME_H
#define PREDICTNOWFRAME_H
#define TIMER3_ID 1003
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
#include <wx/timer.h>
#include <queue>
#include <map>
#include <boost/thread/shared_mutex.hpp>
//(*Headers(PredictNowFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class PredictNowFrame: public wxFrame
{
	public:

		PredictNowFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~PredictNowFrame();
        void OnTimer(wxTimerEvent& event);
		//(*Declarations(PredictNowFrame)
		wxTextCtrl* TextCtrlSS;
		wxStaticLine* StaticLine2;
		wxTextCtrl* TextCtrlerror;
		wxButton* Button1;
		wxStaticLine* StaticLine5;
		wxStaticText* StaticText1;
		wxStaticLine* StaticLine1;
		wxTextCtrl* TextCtrllog;
		wxStaticLine* StaticLine3;
		wxStaticText* StaticText2;
		wxStaticLine* StaticLine4;
		//*)
        boost::mutex i_mutex;
        boost::shared_mutex pause_mutex;
        //variables in thread
        std::queue<std::string> message_1,message_2,message_3,message_4,message_5;
        bool m_pause,m_quit;
	protected:

		//(*Identifiers(PredictNowFrame)
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICLINE2;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON1;
		static const long ID_STATICLINE4;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICLINE5;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICLINE3;
		//*)

	private:

		//(*Handlers(PredictNowFrame)
		void OnQuit(wxCommandEvent& event);
		//*)
        wxTimer m_timer;
		DECLARE_EVENT_TABLE()
};

#endif
