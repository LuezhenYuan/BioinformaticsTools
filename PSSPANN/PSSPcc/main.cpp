#include <iostream>
#include <map>
#include <boost/program_options.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp> // boost::is_any_of
#include "try.h"
#include "PSSPANNdata.h"
#include "ANNCore.h"
//#include "try.h"
using namespace std;
namespace opt = boost::program_options;

int main(int argc,char* argv[])
{
    //parameters
    opt::options_description desc("ALL options");
    desc.add_options()
        ("settings,s", opt::value<std::string>(), "the .pssp setting file")
        ("trainfile,t", opt::value<std::string>(), "the training file for training")
        ("validatefile,v", opt::value<std::string>(), "the validate file for training")
        ("weightfile,w", opt::value<std::string>(), "the weight file")
        ("weightbiasfile,b", opt::value<std::string>(), "the weight bias file")
        ("testfile,e", opt::value<std::string>(), "the test file for testing")
        ("predictfile,p", opt::value<std::string>(), "the predict file for prediction")
        ("outputprefix,o", opt::value<std::string>(), "the prefix for output")
        ("help,h", "this help")
        ;
    opt::variables_map vm;
    opt::store(opt::parse_command_line(argc,argv,desc),vm);
    opt::notify(vm);
    if(vm.count("help")){
        std::cout<<desc<<"\n";
        return 1;
    }
    //read options
    ifstream settings_file;
    try{
        settings_file.open(vm["settings"].as<std::string>());
    }
    catch(...){
        cout<<"Need the .pssp setting file\n";
        return 0;
    }
    //read file to map
    std::map<std::string,std::string> settings;
    std::string line;
    std::vector<std::string> vec_store;
    while(getline(settings_file,line)){
        if(line[0]=='#') continue;
        boost::split(vec_store, line,boost::is_any_of("\t"));
        settings[vec_store[0]]=vec_store[1];
        vec_store.clear();
    }


    cout << "PSSPANNcc" << endl;
    //Some common process
    int* topology;
    vec_store.clear();
    boost::split(vec_store, settings["HiddenLayerNode"],boost::is_any_of(","));
    int HiddenLayerNumber=stoi(settings["HiddenLayerNumber"]);
    topology=(int*)malloc(sizeof(int)*(2+HiddenLayerNumber));
    int weight_length=0;int weight_bias_length=0;

    for(int i=1;i<HiddenLayerNumber+1;i++) topology[i]=stoi(vec_store[i-1]);
    topology[0]=stoi(settings["InputLayerNode"]);
    topology[HiddenLayerNumber+1]=2;
    bool biasNode=false;
    if(settings["biasNode"]=="true") biasNode=true;
    float* weight;float* weight_bias;bool* result_store;
    if(settings["WeightAvailable"]=="true"){
        for(int i=1;i<HiddenLayerNumber+2;i++){
            weight_length+=topology[i]*topology[i-1];
        }
        try{
            try_cpp::read_file_in_float(weight,vm["weightfile"].as<std::string>(),weight_length);
        }
        catch(...){
            cout<<"Error in load weight file\n";
            return 0;
        }
    }
    if(settings["WeightbiasAvailable"]=="true"){
        for(int i=1;i<HiddenLayerNumber+2;i++){
            weight_bias_length+=topology[i];
        }
        try{
            try_cpp::read_file_in_float(weight_bias,vm["weightbiasfile"].as<std::string>(),weight_bias_length);
        }
        catch(...){
            cout<<"Error in load weight bias file\n";
            return 0;
        }
    }
    float threshold=0.3;
    if(settings.find("threshold")!=settings.end()){threshold = stof(settings["threshold"]);}
    bool has_ss=true;
    if(settings["SecondarayStructureInData"]=="false") has_ss=false;
    if(vm.find("outputprefix")==vm.end()){
        cout<<"Error! Need outputprefix\n";
        return 0;
    }
    //try_cpp::test_ANNCore_Prediction("../data/50_ss.txt");
    if(settings.find("Training")!=settings.end()){
        //training
        if(has_ss==false){
            cout<<"Error! For test, SecondarayStructureInData should be true\n";
            return 0;
        }
        PSSPANNdata* training;
        PSSPANNdata* validate;

        if(vm.find("trainfile")==vm.end()){
            cout<<"Error! Need correct trainfile input\n";
            return 0;
        }
        try{
            training = new PSSPANNdata(vm["trainfile"].as<std::string>());
        }
        catch(...){
            cout<<"Error! Need correct trainfile input\n";
            return 0;
        }
        bool Validation=false;

        if(settings["Validation"]=="true"){
            Validation=true;
            if(vm.find("validatefile")==vm.end()){
                cout<<"Error! Need correct validatefile input\n";
                return 0;
            }
            try{
                validate = new PSSPANNdata(vm["validatefile"].as<std::string>());
            }
            catch(...){
                cout<<"Error! Need correct validatefile input\n";
                return 0;
            }

        }
        threshold=ANN_Training_bool<PSSPANNdata>(training,topology,2+HiddenLayerNumber,
                                       PSSP_threshold_calculator,
                                       PSSP_from_output_to_result,
                                       weight,weight_bias,result_store,
                                       threshold,stoi(settings["MaxIteration"]),
                                       false,
                                       Validation,validate,
                                       stof(settings["Error"]),biasNode,20,
                                       weight_length,weight_bias_length
                                       );

    cout<<"threshold"<<threshold<<endl;
    weight_length=0;weight_bias_length=0;
    for(int i=1;i<HiddenLayerNumber+2;i++){
        weight_length+=topology[i]*topology[i-1];
    }
    for(int i=1;i<HiddenLayerNumber+2;i++){
        weight_bias_length+=topology[i];
    }
    try_cpp::print_array_file<float*>(weight,weight_length,vm["outputprefix"].as<std::string>() + "_weight");
    try_cpp::print_array_file<float*>(weight_bias,weight_bias_length,vm["outputprefix"].as<std::string>() + "_weight_bias");
    delete training;
    if(Validation) delete validate;
    }
    else if(settings.find("Prediction")!=settings.end()){
        //prediction
        if(vm.find("predictfile")==vm.end()){
            cout<<"Error! Need correct predictfile input\n";
            return 0;
        }
        PSSPANNdata prediction(vm["predictfile"].as<std::string>(),has_ss);
        ANN_Training_bool<PSSPANNdata>(&prediction,topology,2+HiddenLayerNumber,
                                       PSSP_threshold_calculator,
                                       PSSP_from_output_to_result,
                                       weight,weight_bias,result_store,
                                       threshold,1,
                                       true,
                                       false,NULL,
                                       0.1,biasNode,0,
                                       weight_length,weight_bias_length
                                       );
        print_ss(&prediction,result_store,prediction.data_size()*2,vm["outputprefix"].as<std::string>() + "_prediction");
    }
    else if(settings.find("Test")!=settings.end()){
        //test
        if(vm.find("testfile")==vm.end()){
            cout<<"Error! Need correct testfile input\n";
            return 0;
        }
        PSSPANNdata test(vm["testfile"].as<std::string>());
        if(has_ss==false){
            cout<<"Error! For test, SecondarayStructureInData should be true\n";
            return 0;
        }
        ANN_Training_bool<PSSPANNdata>(&test,topology,2+HiddenLayerNumber,
                                       PSSP_threshold_calculator,
                                       PSSP_from_output_to_result,
                                       weight,weight_bias,result_store,
                                       threshold,1,
                                       true,
                                       false,NULL,
                                       0.1,biasNode,0,
                                       weight_length,weight_bias_length
                                       );
        cout<<"Q3:"<<test.Q3(result_store)<<endl;
        float* CC;
        CC=test.CC(result_store);
        printf("CC_H:%.6f\n",CC[0]);printf("CC_E:%.6f\n",CC[1]);printf("CC_C:%.6f\n",CC[2]);
        print_ss(&test,result_store,test.data_size()*2,vm["outputprefix"].as<std::string>() + "_test");
        free(CC);free(weight);free(weight_bias);free(result_store);
    }
    else{
        cout<<"Wrong setting file\n";
    }
    return 0;
}

