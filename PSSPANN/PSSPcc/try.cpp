#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "try.h"
#include "Amino_Acid_Map.h"
using namespace std;
namespace try_cpp{


void print_bool_array(const bool* data,int length){
    //int length=sizeof(data)/sizeof(bool);
    cout<<"length"<<length<<endl;
    for(int i=0;i<length;i++){
        if(data[i]==true) cout<<1;
        else cout<<0;
    }
    cout<<endl;
    data=NULL;
    return;
}
void try_PSSPANNdata(string file_name){
    PSSPANNdata training(file_name);
    cout<<"data_size()"<<training.data_size()<<endl;
    training.clear();
    if(!training.isend()) cout<<"YES"<<endl;
    bool* tmp_sample;
    bool* tmp_output;
    tmp_sample=NULL;tmp_output=NULL;
    int length=11;
    int sample_id=0;
    while(!training.isend()){
        //cout<<"sample:"<<sample_id<<endl;
        tmp_sample=training.getsample(length*22);
        tmp_output=training.getsample_output();
        //if(sample_id%1000==0){
            cout<<"sample:"<<sample_id<<endl;
            test_aa_coding(tmp_sample,length*22);
            print_bool_array(tmp_sample,length*22);
            print_bool_array(tmp_output,2);


        //}
        //print_bool_array(tmp_sample,length*22);
        //print_bool_array(tmp_output,2);
        free(tmp_sample);free(tmp_output);
        tmp_sample=NULL;tmp_output=NULL;
        training.nextsample();
        sample_id++;
    }
}
void test_aa_coding(const bool* data,int length){
    for(int i=0;i<length;i++){
        if(data[i]==true){
            cout<<ID2Amino_Acid[i%22];
        }
    }
    cout<<endl;
}

void test_ANNCore_Training(string file_name,float speed,int iteration){

    int m_topology[]={242,2,2};
    float* weight;float* weight_bias;bool* result_store;
    float threshold;
    string out_weight;cout<<"out_weight:";cin>>out_weight;
    string out_weight_bias;cout<<"out_weight_bias:";cin>>out_weight_bias;
    PSSPANNdata training(file_name);
    threshold=ANN_Training_bool<PSSPANNdata>(&training,m_topology,3,
                                   PSSP_threshold_calculator,
                                   PSSP_from_output_to_result,
                                   weight,weight_bias,result_store,
                                   0.1,iteration,
                                   false,
                                   false,NULL,
                                   0.1,true,speed,
                                   0,0,
                                   MY_weight_ini
                                   );
    cout<<"threshold"<<threshold<<endl;
    print_array_file<float*>(weight,242*2+2*2,out_weight);
    print_array_file<float*>(weight_bias,2+2,out_weight_bias);
}
void test_ANNCore_Training_Validation(string file1,string file2,float speed,int iteration){

    int m_topology[]={242,2,2};
    float* weight;float* weight_bias;bool* result_store;
    float threshold;
    string out_weight;cout<<"out_weight:";cin>>out_weight;
    string out_weight_bias;cout<<"out_weight_bias:";cin>>out_weight_bias;
    PSSPANNdata training(file1);
    PSSPANNdata validate(file2);
    threshold=ANN_Training_bool<PSSPANNdata>(&training,m_topology,3,
                                   PSSP_threshold_calculator,
                                   PSSP_from_output_to_result,
                                   weight,weight_bias,result_store,
                                   0.1,iteration,
                                   false,
                                   true,&validate,
                                   0.1,true,speed,
                                   0,0,
                                   MY_weight_ini
                                   );
    cout<<"threshold"<<threshold<<endl;
    print_array_file<float*>(weight,242*2+2*2,out_weight);
    print_array_file<float*>(weight_bias,2+2,out_weight_bias);
}
void test_ANNCore_Prediction(string file,int threshold){

    int m_topology[]={242,2,2};
    float* weight;float* weight_bias;bool* result_store;
    string out_weight;cout<<"weight:";cin>>out_weight;
    string out_weight_bias;cout<<"weight_bias:";cin>>out_weight_bias;
    string out_prediction;cout<<"out_prediction:";cin>>out_prediction;
    PSSPANNdata prediction(file);
    read_file_in_float(weight,out_weight,242*2+2*2);
    read_file_in_float(weight_bias,out_weight_bias,2+2);
    ANN_Training_bool<PSSPANNdata>(&prediction,m_topology,3,
                                   PSSP_threshold_calculator,
                                   PSSP_from_output_to_result,
                                   weight,weight_bias,result_store,
                                   threshold,1,
                                   true,
                                   false,NULL,
                                   0.1,true,0,
                                   242*2+2*2,2+2
                                   );
    //print_array_file<bool*>(result_store,prediction.data_size()*2,"out_predict_see.txt");
    cout<<"Q3:"<<prediction.Q3(result_store)<<endl;
    float* CC;
    CC=prediction.CC(result_store);
    printf("CC_H:%.6f\n",CC[0]);printf("CC_E:%.6f\n",CC[1]);printf("CC_C:%.6f\n",CC[2]);
    print_ss(result_store,prediction.data_size()*2,out_prediction);
    free(CC);free(weight);free(weight_bias);free(result_store);

}

void read_file_in_float(float*& array,string file,int length){
    ifstream in(file);
    array=(float*)malloc(sizeof(float)*length);
    string line;
    for(int i=0;i<length;i++){
        getline(in,line);
        if(line[0]!='#'){
            array[i]=stof(line);
        }
    }
    in.close();
}

void version_1(){
    float speed=0.3;
    float threshold=0.9;
    int tag=0;
    string file1;
    cout<<"Training[0] OR Prediction[1]:";cin>>tag;
    cout<<"Fasta file:";cin>>file1;
    int iteration=1000;
    string file2;
    if(tag==0){
        cout<<"Speed:";cin>>speed;
        cout<<"Iteration:";cin>>iteration;

        cout<<"Validation(If no, [no]):";cin>>file2;
        if(file2=="no")
            try_cpp::test_ANNCore_Training(file1,speed,iteration);
        else
            try_cpp::test_ANNCore_Training_Validation(file1,file2,speed,iteration);
    }
    else if(tag==1){
        cout<<"threshold:";cin>>threshold;
        try_cpp::test_ANNCore_Prediction(file1,threshold);
    }
}
}

