#include<bits/stdc++.h>
using namespace std;

/*
Implement a Stock Price Tracker where multiple Investor objects (Observers) 
subscribe to a Stock (Subject).
When the stock price changes, all investors get notified.
*/

//interfaces
class IInvestor{
    public:
    string name;
    string email;
    string phone;
    string mode;
    string notificationAddress;//internal user convienence
    
    virtual void notify()=0;
};

class IStock{
    public:
    
    string name;
    int price;
    
    vector<IInvestor*>investors; //list of it observers

    virtual void addInvestor(IInvestor* investor)=0;
    virtual void updatePrice(int price)=0;
};

class INotification{
    public:

    virtual void notify(string address)=0;;
};

//concrete implementations
class EmailNotification:public INotification{
    public:
    
    void notify(string address){
        cout<<"Notified via email: "<<address<<endl;
    }
};

class WhatsAppNotification:public INotification{
    public:

    void notify(string address){
        cout<<"Notified via whatsapp: "<<address<<endl;
    }
};

class Investor:public IInvestor{
    private:
    INotification* notificationService=nullptr;
    
    public:
    Investor(string name,string email,string phone,string mode){
        this->name=name;
        this->email=email;
        this->phone=phone;
        this->mode=mode;

        if(mode=="email"){
            this->notificationAddress=email;
            notificationService=new EmailNotification();
        }else if (mode=="phone"){
            this->notificationAddress=phone;
            notificationService=new WhatsAppNotification();
        }
    }

    void notify(){
        notificationService->notify(notificationAddress);
    }
};

class Stock:public IStock{
    protected:
    //this does not care how investors get notified hence decoupled with notification service
    void notifyInvestors(){
        for(auto investor:investors){
            investor->notify();
        }
    }

    public:
    //constructor
    Stock(string name,int price){
        this->name=name;
        this->price=price;
    }

    void addInvestor(IInvestor* newInvestor){
        this->investors.push_back(newInvestor);
    }

    void updatePrice(int price){
        this->price=price;
        cout<<this->name<<" Stock Price Updated: Notifying its investors..."<<endl;
        //notify observers
        notifyInvestors();
    }
};

int main(){
    //step 1 create investors
    IInvestor* investor1=new Investor("Raj","raj@gmail.com","999999999","phone");
    IInvestor* investor2=new Investor("Aditya","aditya@gmail.com","8888888888","email");
    IInvestor* investor3=new Investor("Ankita","ankita@gmail.com","7777777777","phone");
    IInvestor* investor4=new Investor("Sowmya","sowmya@gmail.com","7676767676","email");

    //Step 2: Create stocks
    IStock* infosys=new Stock("INFY",1200);
    IStock* hdfc=new Stock("HDFC",1400);

    infosys->addInvestor(investor1);
    infosys->addInvestor(investor3);

    hdfc->addInvestor(investor2);
    hdfc->addInvestor(investor3);
    hdfc->addInvestor(investor4);

    // price update
    hdfc->updatePrice(1225);

    infosys->updatePrice(1300);

    
    return 0;
}