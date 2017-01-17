#include "MainFrame.h"
#include "PredictionDialog.h"
#include "TrainingDialog.h"
#include "TestDialog.h"
#include <wx/wx.h>
#include <fstream>
#include <string>
#include "TrainingMainFrame.h"
#include "PredictionMainFrame.h"
#include "TestMainFrame.h"
//#include "PSSP_protoApp.h"
//#include <wx/image.h>
//(*InternalHeaders(MainFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(MainFrame)
const long MainFrame::ID_STATICTEXT1 = wxNewId();
const long MainFrame::ID_STATICTEXT2 = wxNewId();
const long MainFrame::ID_CHOICE1 = wxNewId();
const long MainFrame::ID_STATICTEXT3 = wxNewId();
const long MainFrame::ID_CHOICE2 = wxNewId();
const long MainFrame::ID_STATICTEXT4 = wxNewId();
const long MainFrame::ID_STATICTEXT7 = wxNewId();
const long MainFrame::ID_TEXTCTRL1 = wxNewId();
const long MainFrame::ID_STATICTEXT8 = wxNewId();
const long MainFrame::ID_CHOICE3 = wxNewId();
const long MainFrame::ID_STATICTEXT9 = wxNewId();
const long MainFrame::ID_TEXTCTRL2 = wxNewId();
const long MainFrame::ID_STATICTEXT10 = wxNewId();
const long MainFrame::ID_TEXTCTRL3 = wxNewId();
const long MainFrame::ID_STATICTEXT11 = wxNewId();
const long MainFrame::ID_CHOICE4 = wxNewId();
const long MainFrame::ID_BUTTON1 = wxNewId();
const long MainFrame::ID_BUTTON2 = wxNewId();
const long MainFrame::ID_STATICTEXT5 = wxNewId();
const long MainFrame::SubMenuTrain = wxNewId();
const long MainFrame::SubMenuTest = wxNewId();
const long MainFrame::SubMenuPredict = wxNewId();
//*)

BEGIN_EVENT_TABLE(MainFrame,wxFrame)
	//(*EventTable(MainFrame)
	//*)
END_EVENT_TABLE()

MainFrame::MainFrame(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(MainFrame)
	wxBoxSizer* BoxSizer3;
	wxGridSizer* GridSizer2;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, wxID_ANY, _("PSSP-gui"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("DataSettings"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
	GridSizer1 = new wxGridSizer(2, 2, 0, 0);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("dataformat"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridSizer1->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->SetSelection( Choice1->Append(_("fasta")) );
	Choice1->SetToolTip(_("format"));
	GridSizer1->Add(Choice1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("SecondarayStructureInData"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	GridSizer1->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice2 = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	Choice2->SetSelection( Choice2->Append(_("true")) );
	Choice2->Append(_("false"));
	GridSizer1->Add(Choice2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(GridSizer1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("ANNTopology"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer1->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	GridSizer2 = new wxGridSizer(2, 4, 0, 0);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("InputLayerNode"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	GridSizer2->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("17"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	GridSizer2->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("biasNode"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	GridSizer2->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice3 = new wxChoice(this, ID_CHOICE3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	Choice3->SetSelection( Choice3->Append(_("true")) );
	Choice3->Append(_("false"));
	Choice3->SetToolTip(_("bias"));
	GridSizer2->Add(Choice3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("HiddenLayerNumber"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	GridSizer2->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	GridSizer2->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("HiddenLayerNode"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	GridSizer2->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("2,2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	GridSizer2->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(GridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Analysis"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	BoxSizer2->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice4 = new wxChoice(this, ID_CHOICE4, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
	Choice4->SetSelection( Choice4->Append(_("Training")) );
	Choice4->Append(_("Test"));
	Choice4->Append(_("Prediction"));
	BoxSizer2->Add(Choice4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("Next"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Luezhen Yuan (lzyuan@zju.edu.cn)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer1->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	MenuBar1 = new wxMenuBar();
	Menu2 = new wxMenu();
	MenuItem2 = new wxMenuItem(Menu2, SubMenuTrain, _("ANNMethod"), wxEmptyString, wxITEM_NORMAL);
	Menu2->Append(MenuItem2);
	MenuBar1->Append(Menu2, _("Training"));
	Menu3 = new wxMenu();
	MenuItem3 = new wxMenuItem(Menu3, SubMenuTest, _("ANNMethod"), wxEmptyString, wxITEM_NORMAL);
	Menu3->Append(MenuItem3);
	MenuBar1->Append(Menu3, _("Test"));
	Menu1 = new wxMenu();
	MenuItem1 = new wxMenuItem(Menu1, SubMenuPredict, _("ANNMethod"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuItem1);
	MenuBar1->Append(Menu1, _("Prediction"));
	SetMenuBar(MenuBar1);
	DirDialog1 = new wxDirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnNextButton);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnQuitButton);
	Connect(SubMenuTrain,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainFrame::OnSubMenuTrainSelected);
	Connect(SubMenuTest,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainFrame::OnSubMenuTestSelected);
	Connect(SubMenuPredict,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainFrame::OnSubMenuPredictionSelected);
	//*)
}

MainFrame::~MainFrame()
{
	//(*Destroy(MainFrame)
	//*)
}


void MainFrame::OnSubMenuPredictionSelected(wxCommandEvent& event)
{
    PredictionDialog* pred_dlg = new PredictionDialog(this);
    pred_dlg->ShowModal();
    Prediction["Prediction"]=wxT("true");
    Prediction["WeightAvailable"]=pred_dlg->Choice1->GetString(pred_dlg->Choice1->GetSelection());
    Prediction["WeightbiasAvailable"]=pred_dlg->Choice2->GetString(pred_dlg->Choice2->GetSelection());
    Prediction["threshold"]=pred_dlg->TextCtrl1->GetValue();
}

void MainFrame::OnSubMenuTrainSelected(wxCommandEvent& event)
{
    TrainingDialog* train_dlg = new TrainingDialog(this);
    train_dlg->ShowModal();
    Training["Training"]=wxT("true");
    Training["WeightAvailable"]=train_dlg->Choice1->GetString(train_dlg->Choice1->GetSelection());
    Training["WeightbiasAvailable"]=train_dlg->Choice2->GetString(train_dlg->Choice2->GetSelection());
    Training["Error"]=train_dlg->TextCtrl2->GetValue();
    Training["MaxIteration"]=train_dlg->TextCtrl1->GetValue();
    Training["Validation"]=train_dlg->Choice5->GetString(train_dlg->Choice5->GetSelection());
}

void MainFrame::OnSubMenuTestSelected(wxCommandEvent& event)
{
    TestDialog* test_dlg = new TestDialog(this);
    test_dlg->ShowModal();
    Test["Test"]=wxT("true");
    Test["WeightAvailable"]=test_dlg->Choice1->GetString(test_dlg->Choice1->GetSelection());
    Test["WeightbiasAvailable"]=test_dlg->Choice2->GetString(test_dlg->Choice2->GetSelection());
    Test["threshold"]=test_dlg->TextCtrl1->GetValue();
}

void MainFrame::OnSaveButton(wxCommandEvent& event)
{
    wxFileDialog* openFileDialog = new wxFileDialog(this,wxT("Save settings for PSSPcc"),
                                                    wxT(""),wxT(""),
                                                    wxT("PSSP settings(*.pssp)|*.pssp|All(*.*)|*.*"),
                                                    wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if(openFileDialog->ShowModal()==wxID_CANCEL)
        return;

    wxString result;
    result.append("# PSSPinfo\nversion\t1.0\n");
    wxString file_tmp = openFileDialog->GetPath();
    std::string fileName(file_tmp.fn_str());
    //std::string fileName3(file_tmp.ToUTF8());
    //tc->LoadFile(fileName);
    //text1->SaveFile(wxT("dummy.cpp"));
    //DataSettings
    result.append("# DataSettings\n");
    DataSettings["dataformat"]=Choice1->GetString(Choice1->GetSelection());
    DataSettings["SecondarayStructureInData"]=Choice2->GetString(Choice2->GetSelection());

    ANNTopology["InputLayerNode"]=wxString(std::to_string(std::stoi(TextCtrl1->GetValue().ToStdString()) *22));
    ANNTopology["biasNode"]=Choice3->GetString(Choice1->GetSelection());
    ANNTopology["HiddenLayerNumber"]=TextCtrl2->GetValue();
    ANNTopology["HiddenLayerNode"]=TextCtrl3->GetValue();
    for(auto it = DataSettings.cbegin(); it!=DataSettings.cend();it++){
        result.append(it->first);
        result.append("\t");
        result.append(it->second);
        result.append("\n");
    }
    result.append("# ANNTopology\n");
    for(auto it = ANNTopology.cbegin(); it!=ANNTopology.cend();it++){
        result.append(it->first);
        result.append("\t");
        result.append(it->second);
        result.append("\n");
    }
    wxString analysis = Choice4->GetString(Choice4->GetSelection());
    if(analysis == "Training"){
        result.append("# Training\n");
        for(auto it = Training.cbegin(); it!=Training.cend();it++){
            result.append(it->first);
            result.append("\t");
            result.append(it->second);
            result.append("\n");
        }
    }
    else if(analysis == "Test"){
        result.append("# Test\n");
        for(auto it = Test.cbegin(); it!=Test.cend();it++){
            result.append(it->first);
            result.append("\t");
            result.append(it->second);
            result.append("\n");
        }
    }
    else if(analysis == "Prediction"){
        result.append("# Prediction\n");
        for(auto it = Prediction.cbegin(); it!=Prediction.cend();it++){
            result.append(it->first);
            result.append("\t");
            result.append(it->second);
            result.append("\n");
        }
    }
    std::ofstream out(fileName);

    out<<result.ToStdString();
    out.close();

}

void MainFrame::OnQuitButton(wxCommandEvent& event)
{
    Close();
}

void MainFrame::OnNextButton(wxCommandEvent& event)
{
    DataSettings["dataformat"]=Choice1->GetString(Choice1->GetSelection());
    DataSettings["SecondarayStructureInData"]=Choice2->GetString(Choice2->GetSelection());
    ANNTopology["InputLayerNode"]=wxString(std::to_string(std::stoi(TextCtrl1->GetValue().ToStdString()) *22));
    ANNTopology["biasNode"]=Choice3->GetString(Choice1->GetSelection());
    ANNTopology["HiddenLayerNumber"]=TextCtrl2->GetValue();
    ANNTopology["HiddenLayerNode"]=TextCtrl3->GetValue();
    if(Choice4->GetString(Choice4->GetSelection()) == "Training"){
        TrainingMainFrame* training_main_frm = new TrainingMainFrame(this);
        std::string see_tmp;
        for(auto it = DataSettings.cbegin(); it!=DataSettings.cend();it++){
            (training_main_frm->DataSettings)[it->first]=it->second;
        }
        for(auto it = ANNTopology.cbegin(); it!=ANNTopology.cend();it++){
            (training_main_frm->ANNTopology)[it->first]=it->second;
            see_tmp=(it->second).ToStdString();
        }
        for(auto it = Training.cbegin(); it!=Training.cend();it++){
            (training_main_frm->Training)[it->first]=it->second;
        }
        //training_main_frm->Show(true);
        //training_main_frm->Button2->Show();

        training_main_frm->Show(true);

        //According to the settings
        if(Training["Validation"]=="true")
            training_main_frm->Button2->Show();
        if(Training["WeightAvailable"]=="true")
            training_main_frm->Button3->Show();
        if(Training["WeightbiasAvailable"]=="true")
            training_main_frm->Button4->Show();
        training_main_frm->Fit();
        //SetTopWindow(training_main_frm);
    }
    else if(Choice4->GetString(Choice4->GetSelection()) == "Prediction"){
        PredictionMainFrame* prediction_main_frm = new PredictionMainFrame(this);
        std::string see_tmp;
        for(auto it = DataSettings.cbegin(); it!=DataSettings.cend();it++){
            (prediction_main_frm->DataSettings)[it->first]=it->second;
        }
        for(auto it = ANNTopology.cbegin(); it!=ANNTopology.cend();it++){
            (prediction_main_frm->ANNTopology)[it->first]=it->second;
            see_tmp=(it->second).ToStdString();
        }
        for(auto it = Prediction.cbegin(); it!=Prediction.cend();it++){
            (prediction_main_frm->Prediction)[it->first]=it->second;
        }
        //training_main_frm->Show(true);
        //training_main_frm->Button2->Show();

        prediction_main_frm->Show(true);

        //According to the settings
        if(Prediction["WeightbiasAvailable"]=="true")
            prediction_main_frm->Button2->Show();
        prediction_main_frm->Fit();
    }
    else if(Choice4->GetString(Choice4->GetSelection()) == "Test"){
        TestMainFrame* test_main_frm = new TestMainFrame(this);
        std::string see_tmp;
        for(auto it = DataSettings.cbegin(); it!=DataSettings.cend();it++){
            (test_main_frm->DataSettings)[it->first]=it->second;
        }
        for(auto it = ANNTopology.cbegin(); it!=ANNTopology.cend();it++){
            (test_main_frm->ANNTopology)[it->first]=it->second;
            see_tmp=(it->second).ToStdString();
        }
        for(auto it = Test.cbegin(); it!=Test.cend();it++){
            (test_main_frm->Test)[it->first]=it->second;
        }
        //training_main_frm->Show(true);
        //training_main_frm->Button2->Show();

        test_main_frm->Show(true);

        //According to the settings
        if(Test["WeightbiasAvailable"]=="true")
            test_main_frm->Button2->Show();
        test_main_frm->Fit();
    }

}
