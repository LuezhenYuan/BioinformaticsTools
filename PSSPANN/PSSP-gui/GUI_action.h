#ifndef GUI_ACTION_H_INCLUDED
#define GUI_ACTION_H_INCLUDED
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
#include "TestNowFrame.h"
#include "PredictNowFrame.h"
//#include <time.h>
/*
    Requirement for void Act_GUI(GUI*,string,int):
        int action  VariableName
        1   log TextCtrllog
        2   error   TextCtrlerror
        3   iteration   TextCtrliteration
        4   validate error  Textvderror
        5   threshold   TextCtrlthreshold
*/
template <typename GUI>
void Act_GUI(GUI* m_gui,string str,int step){
    //To avoid gui window die, allow change for every one second, but the last iteration ???
    //time_t tt = time(NULL);
    //tm* t= localtime(&tt);
    //static int t_tmp=t->tm_min;
    //if(t->tm_min>t_tmp){
        //t_tmp=t->tm_min;
    //In multithread, gui could only refresh in main thread. So I will push all the message
    // to a member elements in m_gui
    {
        boost::lock_guard<boost::mutex> lock(m_gui->i_mutex);
        if(step==1){
            m_gui->message_1.push(str);
        }
        else if(step==2){
            m_gui->message_2.push(str);
        }
        else if(step==3){
            m_gui->message_3.push(str);
        }
        else if(step==4){
            m_gui->message_4.push(str);
        }
        else if(step==5){
            m_gui->message_5.push(str);
        }
    }
    /*
        if(step==1){
            m_gui->TextCtrllog->AppendText(str);//!!attention, here is string not wxstring!!!
            m_gui->TextCtrllog->Refresh();
            m_gui->TextCtrllog->Update();
        }
        else if(step==2){
            m_gui->TextCtrlerror->SetValue(str);//!!attention, here is string not wxstring!!!
            m_gui->TextCtrlerror->Refresh();
            m_gui->TextCtrlerror->Update();
        }
        else if(step==3){
            m_gui->TextCtrliteration->SetValue(str);//!!attention, here is string not wxstring!!!
            m_gui->TextCtrliteration->Refresh();
            m_gui->TextCtrliteration->Update();
        }
        else if(step==4){
            m_gui->Textvderror->SetValue(str);//!!attention, here is string not wxstring!!!
            m_gui->Textvderror->Refresh();
            m_gui->Textvderror->Update();
        }
        else if{step==5}{
            m_gui->TextCtrlthreshold->SetValue(str);//!!attention, here is string not wxstring!!!
            m_gui->TextCtrlthreshold->Refresh();
            m_gui->TextCtrlthreshold->Update();
        }
    //}
    */
}

/*
    Requirement for void Act_GUI(GUI*,string,int):
        int action  VariableName
        1   log TextCtrllog
        2   error   TextCtrlerror
        3   Q3  TextCtrlQ3
        4   CC_H  TextCtrlCC_H
        5   CC_E   TextCtrlCC_E
        6   CC_C   TextCtrlCC_C
        7   SS  TextCtrlSS
*/
template <>
inline void Act_GUI<TestNowFrame>(TestNowFrame* m_gui,string str,int step){

    {
        boost::lock_guard<boost::mutex> lock(m_gui->i_mutex);
        if(step==1){
            m_gui->message_1.push(str);
        }
        else if(step==2){
            m_gui->message_2.push(str);
        }
        else if(step==3){
            m_gui->message_3.push(str);
        }
        else if(step==4){
            m_gui->message_4.push(str);
        }
        else if(step==5){
            m_gui->message_5.push(str);
        }
        else if(step==6){
            m_gui->message_6.push(str);
        }
        else if(step==7){
            m_gui->message_7.push(str);
        }
    }
}

/*
    Requirement for void Act_GUI(GUI*,string,int):
        int action  VariableName
        1   log TextCtrllog
        2   error   TextCtrlerror
        3   SS  TextCtrlSS
*/
template <>
inline void Act_GUI<PredictNowFrame>(PredictNowFrame* m_gui,string str,int step){

    {
        boost::lock_guard<boost::mutex> lock(m_gui->i_mutex);
        if(step==1){
            m_gui->message_1.push(str);
        }
        else if(step==2){
            m_gui->message_2.push(str);
        }
        else if(step==3){
            m_gui->message_3.push(str);
        }
    }
}
#endif // GUI_ACTION_H_INCLUDED
