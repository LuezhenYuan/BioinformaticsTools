#include "TrainingMainFrame.h"
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp> // boost::is_any_of
#include "try.h"
#include "PSSPANNdata.h"
#include "ANNCore.h"
#include "GUI_action.h"
#include <boost/thread.hpp>
//(*InternalHeaders(TrainingMainFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(TrainingMainFrame)
const long TrainingMainFrame::ID_STATICLINE1 = wxNewId();
const long TrainingMainFrame::ID_BUTTON1 = wxNewId();
const long TrainingMainFrame::ID_BUTTON2 = wxNewId();
const long TrainingMainFrame::ID_STATICLINE3 = wxNewId();
const long TrainingMainFrame::ID_BUTTON3 = wxNewId();
const long TrainingMainFrame::ID_BUTTON4 = wxNewId();
const long TrainingMainFrame::ID_STATICLINE4 = wxNewId();
const long TrainingMainFrame::ID_STATICTEXT1 = wxNewId();
const long TrainingMainFrame::ID_TEXTCTRL1 = wxNewId();
const long TrainingMainFrame::ID_STATICLINE5 = wxNewId();
const long TrainingMainFrame::ID_BUTTON5 = wxNewId();
const long TrainingMainFrame::ID_STATICLINE2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(TrainingMainFrame,wxFrame)
	//(*EventTable(TrainingMainFrame)
	//*)
END_EVENT_TABLE()

TrainingMainFrame::TrainingMainFrame(wxWindow* parent)
{
	//(*Initialize(TrainingMainFrame)
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer1;

	Create(parent, wxID_ANY, _("Training Frame"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	BoxSizer1->Add(StaticLine1, 0, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("Training file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("Validate file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->Hide();
	BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine3 = new wxStaticLine(this, ID_STATICLINE3, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
	BoxSizer1->Add(StaticLine3, 0, wxALL|wxEXPAND, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button3 = new wxButton(this, ID_BUTTON3, _("Weight file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button3->Hide();
	BoxSizer2->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button4 = new wxButton(this, ID_BUTTON4, _("Bias file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Button4->Hide();
	BoxSizer2->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine4 = new wxStaticLine(this, ID_STATICLINE4, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE4"));
	BoxSizer1->Add(StaticLine4, 0, wxALL|wxEXPAND, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("output prefix"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer4->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Train01"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer4->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine5 = new wxStaticLine(this, ID_STATICLINE5, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE5"));
	BoxSizer1->Add(StaticLine5, 0, wxALL|wxEXPAND, 5);
	Button5 = new wxButton(this, ID_BUTTON5, _("Start"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizer1->Add(Button5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	BoxSizer1->Add(StaticLine2, 0, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	FileDialog1 = new wxFileDialog(this, _("Select training file"), wxEmptyString, wxEmptyString, _("txt(*.txt)|*.txt|All(*.*)|*.*"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	FileDialog2 = new wxFileDialog(this, _("Select validate file"), wxEmptyString, wxEmptyString, _("txt(*.txt)|*.txt|All(*.*)|*.*"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	FileDialog3 = new wxFileDialog(this, _("Select weight file"), wxEmptyString, wxEmptyString, _("txt(*.txt)|*.txt|All(*.*)|*.*"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	FileDialog4 = new wxFileDialog(this, _("Select bias file"), wxEmptyString, wxEmptyString, _("txt(*.txt)|*.txt|All(*.*)|*.*"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TrainingMainFrame::OnTrainfileButton);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TrainingMainFrame::OnvalidatefileButton);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TrainingMainFrame::OnweightfileButton);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TrainingMainFrame::OnbiasfileButton);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TrainingMainFrame::OnStart);
	//*)
}

TrainingMainFrame::~TrainingMainFrame()
{
	//(*Destroy(TrainingMainFrame)
	//*)
}


void TrainingMainFrame::OnTrainfileButton(wxCommandEvent& event)
{

    if(FileDialog1->ShowModal()==wxID_CANCEL)
        return;
    vm["trainfile"]=(FileDialog1->GetPath()).fn_str();
}

void TrainingMainFrame::OnvalidatefileButton(wxCommandEvent& event)
{
    if(FileDialog2->ShowModal()==wxID_CANCEL)
        return;
    vm["validatefile"]=(FileDialog2->GetPath()).fn_str();
}

void TrainingMainFrame::OnweightfileButton(wxCommandEvent& event)
{
    if(FileDialog3->ShowModal()==wxID_CANCEL)
        return;
    vm["weightfile"]=(FileDialog3->GetPath()).fn_str();
}

void TrainingMainFrame::OnbiasfileButton(wxCommandEvent& event)
{
    if(FileDialog4->ShowModal()==wxID_CANCEL)
        return;
    vm["weightbiasfile"]=(FileDialog4->GetPath()).fn_str();
}

void TrainingMainFrame::OnStart(wxCommandEvent& event)
{
    vm["outputprefix"]=(TextCtrl1->GetValue()).ToStdString();
    TrainNowFrame* trainnow_frm = new TrainNowFrame(0);
    trainnow_frm->Show(true);
    trainnow_frm->TextCtrllog->AppendText("\nTraining...\n");
    //start_Training(trainnow_frm);

    boost::thread(boost::bind(
        &(start_Training),
        this,
        trainnow_frm
        )).detach();
}

void start_Training(TrainingMainFrame* main_frm,TrainNowFrame* trainnow_frm){
    //Do all the things as PSSPccmain
    //Some common things
    int* topology;
    std::vector<std::string> vec_store;
    vec_store.clear();
    string tmp_here;
    tmp_here=(main_frm->ANNTopology["HiddenLayerNode"]).ToStdString();
    boost::split(vec_store, tmp_here,boost::is_any_of(","));
    int HiddenLayerNumber=stoi(main_frm->ANNTopology["HiddenLayerNumber"].ToStdString());
    topology=(int*)malloc(sizeof(int)*(2+HiddenLayerNumber));
    int weight_length=0;int weight_bias_length=0;

    for(int i=1;i<HiddenLayerNumber+1;i++) topology[i]=stoi(vec_store[i-1]);
    topology[0]=stoi(main_frm->ANNTopology["InputLayerNode"].ToStdString());
    topology[HiddenLayerNumber+1]=2;
    bool biasNode=false;
    if(main_frm->ANNTopology["biasNode"]=="true") biasNode=true;
    float* weight;float* weight_bias;bool* result_store;
    weight=NULL;weight_bias=NULL;result_store=NULL;
    if(main_frm->Training["WeightAvailable"]=="true"){
        for(int i=1;i<HiddenLayerNumber+2;i++){
            weight_length+=topology[i]*topology[i-1];
        }
        try{
            try_cpp::read_file_in_float(weight,main_frm->vm["weightfile"],weight_length);
        }
        catch(...){
            Act_GUI(trainnow_frm,"Error in load weight file\n",1);
            //trainnow_frm->TextCtrllog->AppendText("Error in load weight file\n");
            return ;
        }
    }
    if(main_frm->Training["WeightbiasAvailable"]=="true"){
        for(int i=1;i<HiddenLayerNumber+2;i++){
            weight_bias_length+=topology[i];
        }
        try{
            try_cpp::read_file_in_float(weight_bias,main_frm->vm["weightbiasfile"],weight_bias_length);
        }
        catch(...){
            Act_GUI(trainnow_frm,"Error in load weight bias file\n",1);
            //trainnow_frm->TextCtrllog->AppendText("Error in load weight bias file\n");
            return;
        }
    }
    float threshold=0.3;
    //if(settings.find("threshold")!=settings.end()){threshold = stof(settings["threshold"]);}
    bool has_ss=true;
    //if(settings["SecondarayStructureInData"]=="false") has_ss=false;
    if(main_frm->vm.find("outputprefix")==main_frm->vm.end()){
        Act_GUI(trainnow_frm,"Error! Need outputprefix\n",1);
        //trainnow_frm->TextCtrllog->AppendText("Error! Need outputprefix\n");
        return;
    }

    //Only for training

        PSSPANNdata* training;
        PSSPANNdata* validate;

        if(main_frm->vm.find("trainfile")==main_frm->vm.end()){
            Act_GUI(trainnow_frm,"Error! Need correct trainfile input\n",1);
            //trainnow_frm->TextCtrllog->AppendText("Error! Need correct trainfile input\n");
            return;
        }
        try{
            training = new PSSPANNdata(main_frm->vm["trainfile"]);
        }
        catch(...){
            Act_GUI(trainnow_frm,"Error! Need correct trainfile input\n",1);
            //trainnow_frm->TextCtrllog->AppendText("Error! Need correct trainfile input\n");
            return;
        }
        bool Validation=false;

        if(main_frm->Button2->IsShown()){//settings["Validation"]=="true"
            Validation=true;
            if(main_frm->vm.find("validatefile")==main_frm->vm.end()){
                Act_GUI(trainnow_frm,"Error! Need correct validatefile input\n",1);
                //trainnow_frm->TextCtrllog->AppendText("Error! Need correct validatefile input\n");
                return;
            }
            try{
                validate = new PSSPANNdata(main_frm->vm["validatefile"]);
            }
            catch(...){
                Act_GUI(trainnow_frm,"Error! Need correct validatefile input\n",1);
                //trainnow_frm->TextCtrllog->AppendText("Error! Need correct validatefile input\n");
                return;
            }
        }

        threshold=ANN_Training_bool<PSSPANNdata,TrainNowFrame>(trainnow_frm,Act_GUI<TrainNowFrame>,training,topology,2+HiddenLayerNumber,
                                       PSSP_threshold_calculator,
                                       PSSP_from_output_to_result,
                                       weight,weight_bias,result_store,
                                       threshold,stoi(main_frm->Training["MaxIteration"].ToStdString()),
                                       false,
                                       Validation,validate,
                                       stof(main_frm->Training["Error"].ToStdString()),biasNode,20,
                                       weight_length,weight_bias_length
                                       );

    //*(trainnow_frm->TextCtrllog)<<"threshold"<<threshold<<"\n";
    Act_GUI(trainnow_frm,"threshold:"+to_string(threshold)+"\n",1);
    //trainnow_frm->TextCtrlthreshold->SetValue(to_string(threshold));
    Act_GUI(trainnow_frm,to_string(threshold),5);
    weight_length=0;weight_bias_length=0;
    for(int i=1;i<HiddenLayerNumber+2;i++){
        weight_length+=topology[i]*topology[i-1];
    }
    for(int i=1;i<HiddenLayerNumber+2;i++){
        weight_bias_length+=topology[i];
    }
    try_cpp::print_array_file<float*>(weight,weight_length,main_frm->vm["outputprefix"] + "_weight.txt");
    try_cpp::print_array_file<float*>(weight_bias,weight_bias_length,main_frm->vm["outputprefix"] + "_weight_bias.txt");
    delete training;
    if(Validation) delete validate;
    free(topology);
    free(weight);free(weight_bias);free(result_store);
    //trainnow_frm->Refresh();
    //trainnow_frm->Update();
    //trainnow_frm->AddPendingEvent()
}
