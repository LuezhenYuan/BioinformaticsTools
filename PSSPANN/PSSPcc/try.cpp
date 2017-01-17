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


}

