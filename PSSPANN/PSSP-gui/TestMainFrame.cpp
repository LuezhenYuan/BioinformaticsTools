#include "TestMainFrame.h"
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp> // boost::is_any_of
#include "try.h"
#include "PSSPANNdata.h"
#include "ANNCore.h"
#include "GUI_action.h"
#include <boost/thread.hpp>
//(*InternalHeaders(TestMainFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(TestMainFrame)
const long TestMainFrame::ID_STATICLINE1 = wxNewId();
const long TestMainFrame::ID_BUTTON1 = wxNewId();
const long TestMainFrame::ID_BUTTON2 = wxNewId();
const long TestMainFrame::ID_STATICLINE2 = wxNewId();
const long TestMainFrame::ID_BUTTON3 = wxNewId();
const long TestMainFrame::ID_STATICLINE3 = wxNewId();
const long TestMainFrame::ID_STATICTEXT2 = wxNewId();
const long TestMainFrame::ID_TEXTCTRL2 = wxNewId();
const long TestMainFrame::ID_STATICLINE4 = wxNewId();
const long TestMainFrame::ID_BUTTON4 = wxNewId();
const long TestMainFrame::ID_STATICLINE5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(TestMainFrame,wxFrame)
	//(*EventTable(TestMainFrame)
	//*)
END_EVENT_TABLE()

TestMainFrame::TestMainFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(TestMainFrame)
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, _("Test Frame"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	BoxSizer1->Add(StaticLine1, 0, wxALL|wxEXPAND, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("Weight file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("Bias file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->Hide();
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	BoxSizer1->Add(StaticLine2, 0, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button3 = new wxButton(this, ID_BUTTON3, _("Test file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer3->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine3 = new wxStaticLine(this, ID_STATICLINE3, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
	BoxSizer1->Add(StaticLine3, 0, wxALL|wxEXPAND, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("output prefix"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer4->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Test01"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer4->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine4 = new wxStaticLine(this, ID_STATICLINE4, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE4"));
	BoxSizer1->Add(StaticLine4, 0, wxALL|wxEXPAND, 5);
	Button4 = new wxButton(this, ID_BUTTON4, _("Start"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer1->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine5 = new wxStaticLine(this, ID_STATICLINE5, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE5"));
	BoxSizer1->Add(StaticLine5, 0, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	FileDialog1 = new wxFileDialog(this, _("Select weight file"), wxEmptyString, wxEmptyString, _("txt(*.txt)|*.txt|All(*.*)|*.*"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	FileDialog2 = new wxFileDialog(this, _("Select bias file"), wxEmptyString, wxEmptyString, _("txt(*.txt)|*.txt|All(*.*)|*.*"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	FileDialog3 = new wxFileDialog(this, _("Select test file"), wxEmptyString, wxEmptyString, _("txt(*.txt)|*.txt|All(*.*)|*.*"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TestMainFrame::OnWeightfile);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TestMainFrame::OnBiasfile);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TestMainFrame::OnTestfile);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TestMainFrame::OnStart);
	//*)
}

TestMainFrame::~TestMainFrame()
{
	//(*Destroy(TestMainFrame)
	//*)
}


void TestMainFrame::OnStart(wxCommandEvent& event)
{
    vm["outputprefix"]=(TextCtrl1->GetValue()).ToStdString();
    TestNowFrame* testnow_frm = new TestNowFrame(0);
    testnow_frm->Show(true);
    testnow_frm->TextCtrllog->AppendText("\nTesting...\n");
    //start_Training(testnow_frm);

    boost::thread(boost::bind(
        &(start_Test),
        this,
        testnow_frm
        )).detach();
}

void start_Test(TestMainFrame* main_frm,TestNowFrame* testnow_frm){
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
    if(main_frm->Test["WeightAvailable"]=="true"){
        for(int i=1;i<HiddenLayerNumber+2;i++){
            weight_length+=topology[i]*topology[i-1];
        }
        try{
            try_cpp::read_file_in_float(weight,main_frm->vm["weightfile"],weight_length);
        }
        catch(...){
            Act_GUI(testnow_frm,"Error in load weight file\n",1);
            //testnow_frm->TextCtrllog->AppendText("Error in load weight file\n");
            return ;
        }
    }
    if(main_frm->Test["WeightbiasAvailable"]=="true"){
        for(int i=1;i<HiddenLayerNumber+2;i++){
            weight_bias_length+=topology[i];
        }
        try{
            try_cpp::read_file_in_float(weight_bias,main_frm->vm["weightbiasfile"],weight_bias_length);
        }
        catch(...){
            Act_GUI(testnow_frm,"Error in load weight bias file\n",1);
            //testnow_frm->TextCtrllog->AppendText("Error in load weight bias file\n");
            return;
        }
    }
    float threshold=0.3;
    threshold=stof(main_frm->Test["threshold"].ToStdString());
    //if(settings.find("threshold")!=settings.end()){threshold = stof(settings["threshold"]);}
    bool has_ss=true;
    if(main_frm->DataSettings["SecondarayStructureInData"]=="false") has_ss=false;
    if(main_frm->vm.find("outputprefix")==main_frm->vm.end()){
        Act_GUI(testnow_frm,"Error! Need outputprefix\n",1);
        //testnow_frm->TextCtrllog->AppendText("Error! Need outputprefix\n");
        return;
    }

    //Only for test
        if(main_frm->vm.find("testfile")==main_frm->vm.end()){
            Act_GUI(testnow_frm,"Error! Need correct testfile input\n",1);
            //cout<<"Error! Need correct testfile input\n";
            return;
        }
        PSSPANNdata test(main_frm->vm["testfile"]);
        if(has_ss==false){
            Act_GUI(testnow_frm,"Error! For test, SecondarayStructureInData should be true\n",1);
            //cout<<"Error! For test, SecondarayStructureInData should be true\n";
            return;
        }
        ANN_Training_bool<PSSPANNdata,TestNowFrame>(testnow_frm,Act_GUI<TestNowFrame>,&test,topology,2+HiddenLayerNumber,
                                       PSSP_threshold_calculator,
                                       PSSP_from_output_to_result,
                                       weight,weight_bias,result_store,
                                       threshold,1,
                                       true,
                                       false,NULL,
                                       0.1,biasNode,0,
                                       weight_length,weight_bias_length
                                       );
        //cout<<"Q3:"<<test.Q3(result_store)<<endl;
        Act_GUI(testnow_frm,"Q3:"+to_string(test.Q3(result_store))+"\n",1);
        Act_GUI(testnow_frm,to_string(test.Q3(result_store)),3);//!!See here
        float* CC;
        CC=test.CC(result_store);
        //printf("CC_H:%.6f\n",CC[0]);printf("CC_E:%.6f\n",CC[1]);printf("CC_C:%.6f\n",CC[2]);
        Act_GUI(testnow_frm,to_string(CC[0]),4);
        Act_GUI(testnow_frm,to_string(CC[1]),5);
        Act_GUI(testnow_frm,to_string(CC[2]),6);
        print_ss(&test,result_store,test.data_size()*2,main_frm->vm["outputprefix"] + "_test.txt");
        std::ifstream in(main_frm->vm["outputprefix"] + "_test.txt");
        string line;
        while(getline(in,line)){
            Act_GUI(testnow_frm,line,7);
        }
        free(CC);free(weight);free(weight_bias);free(result_store);
}

void TestMainFrame::OnWeightfile(wxCommandEvent& event)
{
    if(FileDialog1->ShowModal()==wxID_CANCEL)
        return;
    vm["weightfile"]=(FileDialog1->GetPath()).fn_str();
}

void TestMainFrame::OnBiasfile(wxCommandEvent& event)
{
    if(FileDialog2->ShowModal()==wxID_CANCEL)
        return;
    vm["weightbiasfile"]=(FileDialog2->GetPath()).fn_str();
}

void TestMainFrame::OnTestfile(wxCommandEvent& event)
{
    if(FileDialog3->ShowModal()==wxID_CANCEL)
        return;
    vm["testfile"]=(FileDialog3->GetPath()).fn_str();
}
