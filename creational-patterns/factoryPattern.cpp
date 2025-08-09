#include<iostream>
using namespace std;
/*
Factory Pattern
Logistic Service
*/

//Abstract Class: Interface like in java
class ILogistic{
    public:
    virtual void send()=0;
    //for better cleanup
    virtual ~ILogistic(){};
};

//Concerete class implementing the interace/abstract class
class AirMode:public ILogistic{
    public:
    void send() override{
        cout<<"Logisitc sent by air"<<endl;
    }
};

//Concerete class implementing the interace/abstract class
class RoadMode:public ILogistic{
    public:
    void send()override{
        cout<<"Logisitc sent by road"<<endl;
    }
};

//this follows SRP easy to now extend
class LogisticFactory{
    public:
    static ILogistic* createMode(const string &mode){
        if(mode=="Air"){
            return new AirMode();
        }else if(mode=="Road"){
            return new RoadMode();
        }else {
            cout<<"Mode match not found "<<endl;
            return nullptr;
        }
    }
};

//client exposed class (it does not need to worry about object creation logic)
class LogisticService{
    public:
    void sendLogistic(const string &mode){
        ILogistic* logisticMode=LogisticFactory::createMode(mode);
        if(logisticMode!=nullptr){
            logisticMode->send();
            delete logisticMode;
        }else{
            cout<<"Error: In Logistic Mode Creation"<<endl;
        }
    }
};
//Logistic Service without factory pattern
//Problem: Open for modifcation (Breaks OCP & SRP creation + send)
// class LogisticService{
//     void sendLogistic(string mode){
//         if(mode=="Air"){
//             ILogistic* airLog=new Air();
//             airLog->send();
//         }else if(mode=="Road"){
//             ILogistic* roadLog=new Road();
//             roadLog->send();
//         }
//     }
// };

int main(){
    LogisticService* logisticService=new LogisticService();
    logisticService->sendLogistic("Air");
    logisticService->sendLogistic("Road");
    logisticService->sendLogistic("Sea");

    delete logisticService;
    
    return 0;
}