/***************************************************************
 * Name:      PSSP_protoMain.h
 * Purpose:   Defines Application Frame
 * Author:    Luezhen (lzyuan@zju.edu.cn)
 * Created:   2017-01-04
 * Copyright: Luezhen (https://github.com/LuezhenYuan)
 * License:
 **************************************************************/

#ifndef PSSP_PROTOMAIN_H
#define PSSP_PROTOMAIN_H

//(*Headers(PSSP_protoDialog)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

class PSSP_protoDialog: public wxDialog
{
    public:

        PSSP_protoDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~PSSP_protoDialog();
        bool wxsmain_frame;
    private:

        //(*Handlers(PSSP_protoDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnLogin(wxCommandEvent& event);
        //*)

        //(*Identifiers(PSSP_protoDialog)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON3;
        static const long ID_STATICLINE2;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(PSSP_protoDialog)
        wxStaticLine* StaticLine2;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxBoxSizer* BoxSizer2;
        wxStaticText* StaticText1;
        wxStaticLine* StaticLine1;
        wxBoxSizer* BoxSizer1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PSSP_PROTOMAIN_H
