#ifndef TRY_H_INCLUDED
#define TRY_H_INCLUDED
#include <string>
#include <fstream>
#include "PSSPANNdata.h"
#include "ANNCore.h"
using namespace std;
namespace try_cpp{
void print_bool_array(const bool* data,int length);
void try_PSSPANNdata(string file_name);
void test_aa_coding(const bool* data,int length);


template <typename T>
void print_array(T* t,int length){
    for(int i=0;i<length;i++) cout<<t[i]<<endl;
}


template <typename T>
void print_array_file(T t,int length,string file){
    ofstream out(file);
    for(int i=0;i<length;i++) out<<t[i]<<endl;
    out.close();
}

void read_file_in_float(float*& array,string file,int length);

}
#endif // TRY_H_INCLUDED
