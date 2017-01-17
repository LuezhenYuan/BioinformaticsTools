/*This header contains the core algorithm for ANN training
   It should achieve the following steps:
   1. ANN data structure implemented (based on network topology)
   2. ANN weights initialize (random or given)
   3. For a certain iterations, or stop until error reach below a threshold value:
    3.1 Start one iteration, clear something
    3.2 Get a sample from data
    3.3 Map sample to input neural nodes
    3.4 Calculate the output values
        (OPTIOINAL) bias weight
    3.5 Calculate error value
    3.6 Calculate weight changes
    3.7 Store something
    3.8 Back to 3.1 until finished all samples
    3.9 Change weights, calculate error for all samples
    3.10 (OPTIONAL) when validation set is available, calculate vd_error!!
         Store the minimum error's weight
    3.11 Last iteration: No need for changing weight
         Training: All output values should be stored(used to calculate threshold t)
         Prediction/test: All output values should be stored(used to map to prediction)
         Validate: Just error should be stored, and then return!!
   4. Training: Calculate threshold t, used to map output node to prediction (threshold_calculator)
     Then return!!
   5. Prediction/test: Map output values to prediction (from_output_to_result)
     Then return!!


  Cases:
   When use this function for training:
   1. Input bool prediction==false && max_iteration>1, validate=true || false
   2. Return weight, and weight_bias, threshold t
   When use this function for prediction/test:
   1. Input weight, weight_bias,threshold t, bool prediction==true && max_iteration==1
   2. Output prediction result
   When use this function for validation:
   1. Input weight, weight_bias, bool prediction==false && max_iteration==1 && validate==false
   2. Output error
  TODO:
   1. See whether template could recurse.

   2. Consider the learning rate issue:
     http://blog.datumbox.com/tuning-the-learning-rate-in-gradient-descent/
  For node index and weight index:
   o     |0
   o  o  |1  4
   o  o  |2  5
   o     |3
   0-4:0,0-5:1,1-4:2,1-5:3,2-4:4,2-5:5,3-4:6,3-5:7
  Some data structure needed:
   1. MLdata: divide all data into training data, and test data.

  Author: Luezhen Yuan (lzyuan@zju.edu.cn)
  Begin date: Dec 24 2016
  Last update: Dec 27 2016
*/
#ifndef ANNCORE_H_INCLUDED
#define ANNCORE_H_INCLUDED
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>
using namespace std;
void MY_weight_ini(float*,int);
template <typename T1, typename T2>
T2 NoActionInput(T1 t){cout<<"if input type != output type, please write your function"<<endl;return t;}

template <typename T>
T NoActionInput(T t){return t;}

template <typename T>
void DoNothing(T t){return;}

template <typename T>
void FreePointer(T t){free(t);return;}


template <typename MLdata, typename SampleType, typename InputType, typename OutputType, typename GUI>
float ANN_Training(GUI* m_gui,void Act_GUI(GUI*,string,int), MLdata* ptdata,const int* const topology, int topology_array_length,
             float threshold_calculator(const MLdata* const,const float*),
             OutputType from_output_to_result(const float*,float,const MLdata* const),
             float*& weight,float*& weight_bias,OutputType& result_store,
             float threshold=0.37,
             int max_iteration=1000,bool prediction=false,
             bool validate=false,MLdata* ptvalidata=NULL, float error_thre=0.1, bool bias=false,float speed=0.3,
             int weight_array_length=0,int weight_bias_array_length=0,
             void weight_ini(float*,int)=MY_weight_ini,
             InputType sample_to_input(SampleType)=NoActionInput<SampleType,InputType>,
             void user_clear_input(InputType)=DoNothing<InputType>,
             void user_clear_output(OutputType)=DoNothing<OutputType>
             ){
    //Data need to free
    /*
    All
    if(bias) d_weight_bias
    node
    delta_node
    d_weight

    Prediction if(prediction)
    output


    Training if(max_iteration>1)
    output
    if(bias) weight_bias
    if(validate) weight_store
    if(validate) weight_bias_store
    weight

    Validate if(max_iteration==1&&prediction==false)

    Requirement for void Act_GUI(GUI*,string,int):
        int action
        1   log
        2   error
        3   iteration
        4   validate error
    */
    //Attentions: the first element of topology is the number of nodes
    // in the input layer, not the number of amino acid input.
    string tmp_output;
    int num_layer=topology_array_length;
    InputType input_sample;
    OutputType output_sample;
    int k=0;//for current layer
    int l_k=0;//for former layer
    int n_k=0;//used for back propagate, next layer
    int former_k_index=0;//the former layer node index
    int current_k_index=0;//the current layer node index
    int current_weight_index=0;//the first weight for calculating current layer

    float node_add=0;
    float error_bp_add=0;//used for calculate back propagate error
    float* output;
    int store_output_sample_index=0;

    if(prediction || max_iteration>1){
        //prediction or training need to store output
        output=(float*) malloc(sizeof(float)*topology[num_layer-1]*ptdata->data_size());
    }
    //1. ANN data structure _float* weight_ implemented (based on network topology)
    float* weight_store;//for validation
    float* weight_bias_store;//for validation
    bool tag_store_output=true;

    float* d_weight;//store changes of weight
    float* delta_node;//store delta_lk for calculating changes of weight
    float* node;
    int length=0,last_num=0,edges=0;

    float* d_weight_bias;//store changes of weight bias

    for(int i=0;i<num_layer;i++){
        length+=topology[i];
        edges=edges+last_num*topology[i];
        last_num=topology[i];
    }
    //cout<<"nodes-edges:"<<length<<"--"<<edges<<endl;

    if(bias){
        if(validate) weight_bias_store= (float*) malloc(sizeof(float)*(length-topology[0]));
        if(weight_bias_array_length!=length-topology[0]){
           if(max_iteration==1) Act_GUI(m_gui,"ERROR: wrong input weight\n",1);
           weight_bias= (float*) malloc(sizeof(float)*(length-topology[0]));//OPTIONAL bias
           weight_ini(weight_bias,length-topology[0]);
        }
        d_weight_bias= (float*) malloc(sizeof(float)*(length-topology[0]));//OPTIONAL bias
    }
    node = (float*) malloc(sizeof(float)*length);
    delta_node = (float*) malloc(sizeof(float)*length);
    if(validate) weight_store = (float*) malloc(sizeof(float)*edges);
    if(weight_array_length!=edges){
        if(max_iteration==1) Act_GUI(m_gui,"ERROR: wrong input weight\n",1);
        weight = (float*) malloc(sizeof(float)*edges);
        //2. ANN weights initialize (random or given)
        weight_ini(weight,edges);
    }

    d_weight = (float*) malloc(sizeof(float)*edges);

    //3. For a certain iterations, or stop until error reach below a threshold value:
    float error=100000,vd_error=100000,vd_error_tmp=0;

    for(int i=0;i<max_iteration;i++){
        {
            boost::shared_lock<boost::shared_mutex> lock(m_gui->pause_mutex);
            if(m_gui->m_quit==true){i=max_iteration-1;}
            else if(m_gui->m_pause==true){i--;continue;}
        }
        //3.1 Start one iteration, clear something
        ptdata->clear();//there should be a member variable to store the current state of sample read

        error=0;
        store_output_sample_index=0;
        //clear d_weight,d_weight_bias;
        for(int j=0;j<edges;j++){d_weight[j]=0;}
        if(bias){ for(int j=0;j<length-topology[0];j++){d_weight_bias[j]=0;}}
        //3.10 (OPTIONAL) when validation set is available, calculate vd_error!!
        if(validate){//!!Take care!!!! Output should store!!!
            vd_error_tmp=ANN_Training<MLdata,SampleType,InputType,OutputType,GUI>
            (m_gui,Act_GUI,ptvalidata,topology,num_layer,
             threshold_calculator,
             from_output_to_result,weight,weight_bias,result_store,
             threshold,
             1,false,
             false,NULL, error_thre,bias,speed,
             edges,(length-topology[0]),
             weight_ini,
             sample_to_input,user_clear_input,user_clear_output
             );
             if(vd_error_tmp<vd_error){
                if(bias) for(int j=0;j<length-topology[0];j++){weight_bias_store[j]=weight_bias[j];}
                for(int j=0;j<edges;j++){weight_store[j]=weight[j];}
                vd_error=vd_error_tmp;
                tag_store_output=true;
             }
             else{tag_store_output=false;}

        }
        //3.2 Get a sample from data
        while(ptdata->isend()!=true){
            //3.3 Map sample to input neural nodes
            input_sample=sample_to_input(ptdata->getsample(topology[0]));
            output_sample=ptdata->getsample_output();
            ptdata->nextsample();
            for(int j=0;j<topology[0];j++){
                node[j]=input_sample[j];
            }
            k=0;//for current layer
            l_k=0;//for former layer
            former_k_index=0;//the former layer node index
            current_weight_index=0;//the first weight for calculating current layer

            node_add=0;
            //3.4 Calculate the output values
            for(int j=1;j<num_layer;j++){
                //for layer j
                for(k=0;k<topology[j];k++){
                    //for node[former_k_index+topology[j-1]+k]
                    node_add=0;
                    for(l_k=0;l_k<topology[j-1];l_k++){
                        //from l_k to k, weight is current_weight_index+topology[j]*l_k + k
                        node_add+=node[former_k_index+l_k]*weight[current_weight_index+topology[j]*l_k + k];
                    }
                    //from bias to node[former_k_index+topology[j-1]+k]
                    // weight is former_k_index+topology[j-1]-topology[0]+k
                    if(bias) node_add+=weight_bias[former_k_index+topology[j-1]-topology[0]+k];//OPTIONAL bias
                    node[former_k_index+topology[j-1]+k]=1.0/(1+exp(-node_add));
                    //sigmoid function: 1.0/(1+exp(-node_add))
                }
                current_weight_index+=topology[j-1]*topology[j];
                former_k_index+=topology[j-1];
            }
            //3.5 Calculate error value
            for(k=0;k<topology[num_layer-1];k++){
                error+=pow((output_sample[k]-node[former_k_index+k]),2);
            }
            //3.6 Calculate weight changes
            if(i<max_iteration-1){
                //error
                current_weight_index=edges;
                current_k_index=length;
                for(int j=num_layer-1;j>0;j--){
                    //for layer j
                    current_weight_index-=topology[j-1]*topology[j];
                    current_k_index-=topology[j];
                    for(k=0;k<topology[j];k++){
                        //for node[current_k_index+k]
                        if(j==num_layer-1){
                            delta_node[current_k_index+k]=node[current_k_index+k]*
                              (1-node[current_k_index+k])*
                              (output_sample[k]-node[current_k_index+k]);

                        }
                        else{
                            error_bp_add=0;
                            for(n_k=0;n_k<topology[j+1];n_k++){
                                //for node[current_k_index+k] and
                                //    node[current_k_index+topology[j]+n_k];
                                //for weight current_weight_index+topology[j]*topology[j-1]
                                //+topology[j+1]*k + n_k
                                error_bp_add+=weight[current_weight_index+topology[j]*topology[j-1]
                                  +topology[j+1]*k + n_k]*delta_node[current_k_index+
                                  topology[j]+n_k];
                            }
                            delta_node[current_k_index+k]=node[current_k_index+k]*
                              (1-node[current_k_index+k])*error_bp_add;
                        }

                        for(l_k=0;l_k<topology[j-1];l_k++){
                            //from l_k to k, weight is current_weight_index+topology[j]*l_k + k
                            d_weight[current_weight_index+topology[j]*l_k + k]+=speed*
                              node[current_k_index-topology[j-1]+l_k]*
                              delta_node[current_k_index+k];

                        }

                        if(bias) d_weight_bias[current_k_index-topology[0]+k]+=speed*delta_node[current_k_index+k];//OPTIONAL bias

                    }
                }


            }
            //3.11 Last iteration
            if(prediction || max_iteration>1){//For prediction and training
                if((!validate && (i==max_iteration-1))//here error couldn't less than error_thre
                   ||(validate && tag_store_output==true)){
                    //Training: All output values should be stored(used to calculate threshold t)
                    //Prediction/test: All output values should be stored(used to map to prediction)
                    for(int j=topology[num_layer-1];j>0;j--){
                        output[store_output_sample_index*2+topology[num_layer-1]-j] = node[length-j];
                    }
                    store_output_sample_index++;
                }

            }
            user_clear_output(output_sample);
            user_clear_input(input_sample);
        }

        //3.9 Change weights, calculate error for all samples
        error/=ptdata->data_size();

        //test
        if(max_iteration>1){
            tmp_output="";
            tmp_output="error:" + to_string(error) +"\tIteration:"+to_string(i)+"\tValidate:"+to_string(vd_error_tmp)+"\n";
            Act_GUI(m_gui,tmp_output,1);
            Act_GUI(m_gui,to_string(error),2);
            Act_GUI(m_gui,to_string(i),3);
            Act_GUI(m_gui,to_string(vd_error_tmp),4);
        }
        //for(int w_i=424;w_i<428;w_i++){
            //cout<<"d_weight"<<d_weight[424]<<endl;
            //cout<<"weight"<<weight[424]<<endl;
            //cout<<"delta_node"<<delta_node[424]<<endl;
        //}
        //end test
        for(int j=0;j<edges;j++){
            weight[j]+=d_weight[j]/ptdata->data_size();
            //weight[j]+=d_weight[j];
        }
        if(bias){
            for(int j=0;j<length-topology[0];j++){
                weight_bias[j]+=d_weight_bias[j]/ptdata->data_size();
                //weight_bias[j]+=d_weight_bias[j];
            }
        }
        if(i!=max_iteration-1 && error<error_thre) i=max_iteration-2;//run another iteration to store output
        speed*=0.999;
    }
    //3.11 Last iteration
    if(prediction==false && max_iteration==1){
        //For validation
        //Validate: Just error should be stored, and then return!!
        free(node);free(delta_node);free(d_weight);
        if(bias) free(d_weight_bias);
        return error;
    }
    else if(prediction==false && max_iteration>1){
        //4. Training: Calculate threshold t, used to map output node to prediction (threshold_calculator)
        //Take care of the validation
        if(validate && vd_error<vd_error_tmp){
            //weight, weight_bias change
            if(bias) for(int j=0;j<length-topology[0];j++){weight_bias[j]=weight_bias_store[j];}
            for(int j=0;j<edges;j++){weight[j]=weight_store[j];}
            tmp_output="";
            tmp_output="Used validate error:"+to_string(vd_error)+"\n";
            Act_GUI(m_gui,to_string(vd_error),4);
        }
        threshold=threshold_calculator(ptdata,output);

        free(node);free(delta_node);free(d_weight);
        if(bias) free(d_weight_bias);
        free(output);
        if(validate){free(weight_store);free(weight_bias_store);}
        //!!!return weight, weight_bias, maybe don't do this, just use the parameter putted in
        //cout<<endl;
        tmp_output="";
        tmp_output="Final error:"+to_string(error)+"\n";
        Act_GUI(m_gui,to_string(error),2);
        //printf("Final error:%.6f\n",error);
        return threshold;
    }
    else if(prediction==true && max_iteration==1){
        //5. Prediction/test: Map output values to prediction (from_output_to_result)

        result_store= from_output_to_result(output,threshold,ptdata);
        free(node);free(delta_node);free(d_weight);
        if(bias) free(d_weight_bias);
        free(output);
        tmp_output="";
        tmp_output="Final error:"+to_string(error)+"\n";
        Act_GUI(m_gui,to_string(error),2);
        //printf("Final error:%.6f\n",error);

        return 0;
        //return result_store;
    }
    Act_GUI(m_gui,"Something Error\n",1);
    //cout<<"Something Error"<<endl;
    return 0;
}

template <typename MLdata, typename GUI>
float ANN_Training_bool(GUI* m_gui,void Act_GUI(GUI*,string,int),MLdata* ptdata,const int* const topology, int topology_array_length,
             float threshold_calculator(const MLdata* const,const float*),
             bool* from_output_to_result(const float*,float,const MLdata* const),
             float*& weight,float*& weight_bias,bool*& result_store,
             float threshold=0.37,
             int max_iteration=1000,bool prediction=false,
             bool validate=false,MLdata* ptvalidata=NULL, float error_thre=0.1, bool bias=false,float speed=0.3,
             int weight_array_length=0,int weight_bias_array_length=0,
             void weight_ini(float*,int)=MY_weight_ini
             )
    {
        return ANN_Training<MLdata,bool*,bool*,bool*,GUI>(m_gui,Act_GUI,ptdata,topology,topology_array_length,
             threshold_calculator,
             from_output_to_result,weight,weight_bias,result_store,
             threshold,
             max_iteration,prediction,
             validate,ptvalidata,error_thre,bias,speed,
             weight_array_length,weight_bias_array_length,
             weight_ini,
             NoActionInput<bool*>,
             FreePointer<bool*>,
             FreePointer<bool*>
             );
}


#endif // ANNCORE_H_INCLUDED
