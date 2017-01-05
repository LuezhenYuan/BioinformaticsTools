#include "PSSPANNdata.h"
#include <fstream>
#include "Amino_Acid_Map.h"
#include <iostream>
#include <cmath>
using namespace std;
void PSSPANNdata::read_fasta_file(string file_name){

    m_data_size=fasta_file_length(file_name)/2;

    m_data=(bool*)malloc(sizeof(bool)*22*m_data_size);
    m_output=(bool*)malloc(sizeof(bool)*2*m_data_size);
    for(int i=0;i<22*m_data_size;i++) m_data[i]=false;
    for(int i=0;i<2*m_data_size;i++) m_output[i]=false;
    m_current_sample=-1;
    m_protein_num=fasta_data_size(file_name)/2;
    m_terminal_site=(int*)malloc(sizeof(int)*m_protein_num);

    ifstream fasta_input(file_name);
    //should get a line, and then read char by char
    //use string to store line, could get a char? See cppreference
    string line;
    bool tag_is_seq=false;
    int tmp_index=0;//amino acid position in 22 sites
    char tmp_ss='C';
    int tmp_ss_position=0;//the position of this amino acid
    while(getline(fasta_input,line)){
        //get a char
        //if is '>' then data size add
        //else store to m_data or m_output
        if(line[0]=='>'){
            tag_is_seq=!tag_is_seq;//first line is sequence
            if(tag_is_seq){m_current_sample++;
            if(m_current_sample>0) m_terminal_site[m_current_sample]=m_terminal_site[m_current_sample-1];
            else m_terminal_site[0]=-1;//when site-4, the amino acid is 5

            }


        }
        else{
            if(tag_is_seq)
            {
                for(int i=0;i<line.size();i++){
                    if(Amino_Acid_map.find(line[i])==Amino_Acid_map.end()){tmp_index=20;}
                    else{tmp_index=Amino_Acid_map.find(line[i])->second;}

                    m_data[m_terminal_site[m_current_sample]*22+22
                    +i*22+tmp_index]=true;

                }
                m_terminal_site[m_current_sample]+=line.size();
            }
            else{
                for(int i=0;i<line.size();i++){
                    if(Amino_Acid_SS_8to3_map.find(line[i])==Amino_Acid_SS_8to3_map.end()){tmp_ss='C';}
                    else{tmp_ss=Amino_Acid_SS_8to3_map.find(line[i])->second;}

                    if(tmp_ss=='H') m_output[tmp_ss_position*2+i*2]=true;
                    else if(tmp_ss=='E') m_output[tmp_ss_position*2+i*2+1]=true;
                }
                tmp_ss_position+=line.size();
            }
        }


    }
    fasta_input.close();
    //test
    //for(int i=0;i<m_protein_num;i++){
    //    cout<<m_terminal_site[i]<<endl;
    //}
    //end test
}

int fasta_file_length(string file_name){
    ifstream fasta_input(file_name);
    string line;
    int length=0;
    while(getline(fasta_input,line)){
        if(line[0]!='>') length+=line.size();
    }
    cout<<"fasta_file_length"<<length<<endl;
    fasta_input.close();
    return length;
}

int fasta_data_size(string file_name){
    ifstream fasta_input(file_name);
    string line;
    int length=0;
    while(getline(fasta_input,line)){
        if(line[0]=='>') length++;
    }
    cout<<"data_size"<<length<<endl;
    fasta_input.close();
    return length;
}

void PSSPANNdata::read_fasta_prediction_file(string file_name){
    m_data_size=fasta_file_length(file_name);

    m_data=(bool*)malloc(sizeof(bool)*22*m_data_size);
    for(int i=0;i<22*m_data_size;i++) m_data[i]=false;

    m_current_sample=-1;
    m_protein_num=fasta_data_size(file_name);
    m_terminal_site=(int*)malloc(sizeof(int)*m_protein_num);

    ifstream fasta_input(file_name);
    //should get a line, and then read char by char
    //use string to store line, could get a char? See cppreference
    string line;
    //bool tag_is_seq=false;
    int tmp_index=0;//amino acid position in 22 sites
    //char tmp_ss='C';
    //int tmp_ss_position=0;//the position of this amino acid
    while(getline(fasta_input,line)){
        //get a char
        //if is '>' then data size add
        //else store to m_data or m_output
        if(line[0]=='>'){
            //tag_is_seq=!tag_is_seq;//first line is sequence
            m_current_sample++;
            if(m_current_sample>0) m_terminal_site[m_current_sample]=m_terminal_site[m_current_sample-1];
            else m_terminal_site[0]=-1;//when site-4, the amino acid is 5
        }
        else{
            for(int i=0;i<line.size();i++){
                if(Amino_Acid_map.find(line[i])==Amino_Acid_map.end()){tmp_index=20;}
                else{tmp_index=Amino_Acid_map.find(line[i])->second;}

                m_data[m_terminal_site[m_current_sample]*22+22
                +i*22+tmp_index]=true;

            }
            m_terminal_site[m_current_sample]+=line.size();
        }
    }
    fasta_input.close();
}

PSSPANNdata::PSSPANNdata(string training_file,bool has_ss):m_data(NULL),m_output(NULL),
m_data_size(0),m_current_sample(0),m_terminal_site(NULL),m_protein_num(0){
    if(has_ss)
        read_fasta_file(training_file);
    else
        read_fasta_prediction_file(training_file);
}

int PSSPANNdata::data_size() const{
    return m_data_size;
}

void PSSPANNdata::clear(){
    m_current_sample=0;
}
bool PSSPANNdata::isend() const{
    return m_current_sample==m_data_size;
}

bool* PSSPANNdata::getsample(int num) const{
    bool* result;result=NULL;
    int protein;
    protein=locate_protein(m_current_sample);//protein: m_terminal_site m_current_sample
    result=(bool*)malloc(sizeof(bool)*num);
    int front_blank;
    if(protein>0) front_blank=num/44-m_current_sample+m_terminal_site[protein-1]+1;
    else front_blank=num/44-m_current_sample;
    front_blank=front_blank>0?front_blank:0;
    int end_blank;
    end_blank=num/44+m_current_sample-m_terminal_site[protein];

    end_blank=end_blank>0?end_blank:-1;
    //Add front half
    for(int i=0;i<num/44;i++){
        if(front_blank>0){
            for(int j=0;j<21;j++) result[i*22+j]=false;
            result[i*22+21]=true;
            front_blank--;
        }
        else{
            for(int j=0;j<22;j++) result[i*22+j]=m_data[(m_current_sample-num/44+i)*22+j];
        }
    }
    for(int j=0;j<22;j++) result[(num/44)*22+j]=m_data[(m_current_sample)*22+j];
    //Add end half
    for(int i=0;i<num/44;i++){
        if(i+end_blank==num/44&&end_blank>0){
            for(int j=0;j<21;j++) result[(num/44)*22+22+i*22+j]=false;
            result[(num/44)*22+22+i*22+21]=true;
            end_blank--;
        }
        else{
            for(int j=0;j<22;j++) result[(num/44)*22+22+i*22+j]=m_data[(m_current_sample+1+i)*22+j];
        }
    }
    return result;
}

bool* PSSPANNdata::getsample_output() const{
    bool* result;result=NULL;
    result=(bool*)malloc(sizeof(bool)*2);
    result[0]=m_output[m_current_sample*2];
    result[1]=m_output[m_current_sample*2+1];
    return result;
}

void PSSPANNdata::nextsample(){
    m_current_sample++;
}
bool* PSSPANNdata::getall_output() const{
    int length=m_data_size*2;
    bool* result=NULL;
    result=(bool*)malloc(sizeof(bool)*length);
    for(int i=0;i<length;i++) result[i]=m_output[i];
    return result;
}

int* PSSPANNdata::get_terminal_site() const{
    int* result;
    result=(int*)malloc(sizeof(int)*m_protein_num);
    for(int i=0;i<m_protein_num;i++) result[i]=m_terminal_site[i];
    return result;
}

float PSSP_threshold_calculator(const PSSPANNdata* const ptdata,const float* ANNoutput){
    //Three steps:
    //1. float* to bool* use a threshold
    //2. Adjust the result
    //3. Calculate Q_3 (write a function!!)
    float t=0;


    bool* current_output;

    current_output=NULL;


    float highest_Q3=0,current_Q3;float highest_t_Q3=0.01;
    for(t=0.01;t<1;t+=0.01){
        current_output=PSSP_from_output_to_result(ANNoutput,t,ptdata);
        //3. Calculate Q_3 (write a function!!)
        current_Q3=ptdata->Q3(current_output);
        if(highest_Q3<current_Q3){
            highest_t_Q3=t;
            highest_Q3=current_Q3;
        }
        free(current_output);
    }
    return highest_t_Q3;
}

int PSSPANNdata::locate_protein(int pos) const{
    int protein;//protein: m_terminal_site m_current_sample
    for(int i=0;i<m_protein_num;i++){
        if(pos<=m_terminal_site[i]){
            protein=i;
            break;
        }
    }
    return protein;
}

float PSSPANNdata::Q3(bool* prediction) const{
    float Q3;
    Q3=0;
    for(int i=0;i<m_data_size;i++){
        if(prediction[2*i]==m_output[2*i] && prediction[2*i+1]==m_output[2*i+1])
            Q3++;
    }
    return 1.0*Q3/m_data_size;
}

bool* PSSP_from_output_to_result(const float* ANNoutput,float t,const PSSPANNdata* const ptdata){
    int length=ptdata->m_data_size*2;

    bool* current_output;

    current_output=(bool*)malloc(sizeof(bool)*length);
    int protein=0;//locate protein
    //1. float* to bool* use a threshold
    for(int j=0;j<length/2;j++){
        if(ANNoutput[2*j]-t>=ANNoutput[2*j+1]){
            current_output[2*j]=true;
            current_output[2*j+1]=false;
        }
        else if(ANNoutput[2*j+1]-t>=ANNoutput[2*j]){
            current_output[2*j+1]=true;
            current_output[2*j]=false;
        }
        else{
            current_output[2*j+1]=false;
            current_output[2*j]=false;
        }
    }
    //2. Adjust the result
    int pro_start,pro_end;
    int contiguous;//contiguous 10 or 01 site
    for(int j=0;j<length/2;j++){
        //locate the protein
        protein=ptdata->locate_protein(j);
        pro_start=(protein>0)?ptdata->m_terminal_site[protein-1]+1:0;
        pro_end=ptdata->m_terminal_site[protein];
        //if j site is 10
        if(current_output[2*j]==true){
            if(j+3<=pro_end && current_output[2*j+2]==true &&
               current_output[2*j+4]==true &&
               current_output[2*j+6]==true){
                //OK for this site and the following contiguous 10 site
                contiguous=4;
                for(contiguous=4;contiguous+j<=pro_end&&current_output[2*j+contiguous*2]==true;contiguous++)
                    {;}
                //then leave these contiguous 1- sites
                j=j+contiguous-1;
            }
            else{
                //change to 00
                current_output[2*j]=false;
            }
        }
        //if j site is 01
        else if(current_output[2*j+1]==true){
            if(j+1<=pro_end && current_output[2*j+3]==true){
                //OK for this site and the following contiguous 01 site
                contiguous=2;
                for(contiguous=2;contiguous+j<=pro_end&&current_output[2*j+contiguous*2+1]==true;contiguous++)
                    {;}
                //then leave these contiguous 1- sites
                j=j+contiguous-1;
            }
            else{
                //change to 00
                current_output[2*j+1]=false;
            }
        }
        else{;}
    }
    return current_output;
}

void print_ss(const bool* protein,int length,string file){
    if(file=="")
    {
        for(int i=0;i<length/2;i++){
            if(protein[2*i]==true) cout<<"H";
            else if(protein[2*i+1]==true) cout<<"E";
            else cout<<"C";
        }
        cout<<endl;
    }
    else{
        ofstream out(file);
        for(int i=0;i<length/2;i++){
            if(protein[2*i]==true) out<<"H";
            else if(protein[2*i+1]==true) out<<"E";
            else out<<"C";
        }
        out<<endl;
        out.close();
    }
}

float* PSSPANNdata::CC(bool* prediction) const{
    float* result;
    result=(float*)malloc(sizeof(float)*3);
    int H[4]={0,0,0,0};//p,u,o,n
    int E[4]={0,0,0,0};
    int C[4]={0,0,0,0};

    for(int i=0;i<m_data_size;i++){
        if(prediction[2*i]==true && m_output[2*i]==true){//HH
            H[0]++;E[3]++;C[3]++;
        }
        else if(prediction[2*i]==true && m_output[2*i+1]==true){//HE
            H[2]++;E[1]++;C[3]++;
        }
        else if(prediction[2*i]==true){//HC
            H[2]++;E[3]++;C[1]++;
        }
        else if(prediction[2*i+1]==true && m_output[2*i]==true){//EH
            H[1]++;E[2]++;C[3]++;
        }
        else if(prediction[2*i+1]==true && m_output[2*i+1]==true){//EE
            H[3]++;E[0]++;C[3]++;
        }
        else if(prediction[2*i+1]==true){//EC
            H[3]++;E[2]++;C[1]++;
        }
        else if(m_output[2*i]==true){//CH
            H[1]++;E[3]++;C[2]++;
        }
        else if(m_output[2*i+1]==true){//CE
            H[3]++;E[1]++;C[2]++;
        }
        else{//CC
            H[3]++;E[3]++;C[0]++;
        }
    }
    result[0]=1.0*(H[0]*H[3]-H[1]*H[2])/sqrt(1.0*(H[3]+H[1])*(H[3]+H[2])*(H[0]+H[1])*(H[0]+H[2]));
    result[1]=1.0*(E[0]*E[3]-E[1]*E[2])/sqrt(1.0*(E[3]+E[1])*(E[3]+E[2])*(E[0]+E[1])*(E[0]+E[2]));
    result[2]=1.0*(C[0]*C[3]-C[1]*C[2])/sqrt(1.0*(C[3]+C[1])*(C[3]+C[2])*(C[0]+C[1])*(C[0]+C[2]));
    return result;
}

float* PSSPANNdata::PSS_HEC() const{
    float* result;
    result=(float*)malloc(sizeof(float)*3);
    result[0]=0;result[1]=0;result[2]=0;
    for(int i=0;i<m_data_size;i++){
        if(m_output[2*i]==true) result[0]++;
        else if(m_output[2*i+1]==true) result[1]++;
        else result[2]++;
    }
    result[0]/=m_data_size*1.0;result[1]/=m_data_size*1.0;result[2]/=m_data_size*1.0;
    return result;
}
