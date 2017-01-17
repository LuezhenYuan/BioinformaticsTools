#ifndef AMINO_ACID_MAP_H_INCLUDED
#define AMINO_ACID_MAP_H_INCLUDED
/*
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

  Author: Luezhen Yuan (lzyuan@zju.edu.cn)
  Begin date: Dec 26 2016
  Last update: Dec 26 2016
*/
#include <map>
const
std::map<char,int> Amino_Acid_map {
    {'A',0},
    {'R',1},
    {'N',2},
    {'D',3},
    {'C',4},
    {'E',5},
    {'Q',6},
    {'G',7},
    {'H',8},
    {'I',9},
    {'L',10},
    {'K',11},
    {'M',12},
    {'F',13},
    {'P',14},
    {'S',15},
    {'T',16},
    {'W',17},
    {'Y',18},
    {'V',19},
    {'X',20},
};//please use find. Amino_Acid_map.find('R')->second
//if not in this map, Amino_Acid_map.find()==Amino_Acid_map.end()
static const char ID2Amino_Acid[]={'A','R','N','D','C','E','Q','G','H','I','L','K','M','F','P','S','T','W','Y','V','X','-'};
/*
8-class to 3-class mapping:
H:H,G,I
E:E,B
C:T,S,C(blank)
*/
const std::map<char,char> Amino_Acid_SS_8to3_map {
    {'H','H'},
    {'G','H'},
    {'I','H'},
    {'E','E'},
    {'B','E'},
    {'T','C'},
    {'S','C'},
    {'C','C'},
    {'-','C'},
    {' ','C'},
};
#endif // AMINO_ACID_MAP_H_INCLUDED
