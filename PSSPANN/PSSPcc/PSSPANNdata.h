#ifndef PSSPANNDATA_H_INCLUDED
#define PSSPANNDATA_H_INCLUDED
/*
>101M:A:sequence
MVLSEGEWQLVLHVWAKVEADVAGHGQDILIRLFKSHPETLEKFDRVKHLKTEAEMKASEDLKKHGVTVLTALGA
ILKKKGHHEAELKPLAQSHATKHKIPIKYLEFISEAIIHVLHSRHPGNFGADAQGAMNKALELFRKDIAAKYKEL
GYQG
>101M:A:secstr
    HHHHHHHHHHHHHHGGGHHHHHHHHHHHHHHH GGGGGG TTTTT  SHHHHHH HHHHHHHHHHHHHHHH
HHTTTT  HHHHHHHHHHHHHTS   HHHHHHHHHHHHHHHHHH GGG SHHHHHHHHHHHHHHHHHHHHHHHHT
T

8-class to 3-class mapping:
H:H,G,I
E:E,B
C:T,S,C(blank)

H:10
E:01
C:00
output step is 2
input step is 22

Amino acid 20+1+1
A
R
N
D
C
E
Q
G
H
I
L
K
M
F
P
S
T
W
Y
V

X others
blank
*/
#include <string>
using namespace std;
class PSSPANNdata{
private:
    bool* m_data;
    bool* m_output;
    int m_data_size;
    int m_current_sample;//start from 0
    int* m_terminal_site;//terminal site in the data, from 0
    int m_protein_num;
    void read_fasta_file(string file_name);
    void read_fasta_prediction_file(string file_name);
    int locate_protein(int pos) const;
public:
    PSSPANNdata(string training_file,bool has_ss=true);//if has ss, then ss stored in m_output, else, nothing in m_output
    //PSSPANNdata(string prediction_file,bool prediction);
    int data_size() const;
    void clear();
    bool isend() const;
    bool* getsample(int num_aa) const;
    bool* getsample_output() const;
    void nextsample();
    bool* getall_output() const;
    int* get_terminal_site() const;
    float Q3(bool*) const;//compared to m_output, Q3 value
    float* CC(bool*) const;//compared to m_output, correlation coefficient
    float* PSS_HEC() const;//show the percent of H/E/C in this sample
    friend bool* PSSP_from_output_to_result(const float*,float,const PSSPANNdata* const);//need m_terminal_site
};
int fasta_file_length(string file_name);
int fasta_data_size(string file_name);
float PSSP_threshold_calculator(const PSSPANNdata* const,const float*);
bool* PSSP_from_output_to_result(const float*,float,const PSSPANNdata* const);
void print_ss(const bool*,int length,string file="");

#endif // PSSPANNDATA_H_INCLUDED
