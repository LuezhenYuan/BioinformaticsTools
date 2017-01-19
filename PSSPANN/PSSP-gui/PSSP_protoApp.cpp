/***************************************************************
 * Name:      PSSP_protoApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Luezhen (lzyuan@zju.edu.cn)
 * Created:   2017-01-04
 * Copyright: Luezhen (https://github.com/LuezhenYuan)
 * License:
 **************************************************************/

#include "PSSP_protoApp.h"

//(*AppHeaders
#include "PSSP_protoMain.h"
#include "MainFrame.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(PSSP_protoApp);

bool PSSP_protoApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	PSSP_protoDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.wxsmain_frame=false;
    	Dlg.ShowModal();
    	//wxsOK = false;
        if (Dlg.wxsmain_frame){
            MainFrame* main_frm = new MainFrame(0);
            main_frm->Show(true);
            SetTopWindow(main_frm);
        }
        else{
            wxsOK = false;
        }
    }
    //*)
    return wxsOK;

}
