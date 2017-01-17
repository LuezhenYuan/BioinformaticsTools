#include "ANNCore.h"
#include <random>
void MY_weight_ini(float* weight,int length){
    std::random_device rd;
    std::mt19937_64 rseed(rd());
    std::uniform_real_distribution<float> dr(0,0.1);
    for(int i=0;i<length;i++){
        weight[i]=dr(rseed);
    }
    return;
}
