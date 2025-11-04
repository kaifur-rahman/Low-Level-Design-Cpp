#include<bits/stdc++.h>
using namespace std;

/*
Implement a Payment System for an e-commerce app that supports multiple payment strategies (like Credit Card, PayPal, and UPI).
The system should allow the user to choose a payment method at runtime and process the payment using that method.
*/

//strategy interface
class IPaymentStrategy{
    public:
    virtual void pay(int amount)=0;
};

//concrete strategies
class PayViaCreditcard:public IPaymentStrategy{
    public:
    void pay(int amount){
        cout<<"Paying "<<amount<<" via credit card"<<endl;
    }
};

class PayViaPaypal:public IPaymentStrategy{
    public:
    void pay(int amount){
        cout<<"Paying "<<amount<<" via Paypal"<<endl;
    }
};

class PayViaUPI:public IPaymentStrategy{
    public:
    void pay(int amount){
        cout<<"Paying "<<amount<<" via UPI"<<endl;
    }
};

//service

class PaymentService{
    protected:
    IPaymentStrategy* paymentStrategy=nullptr;
    
    public:
    
    PaymentService(IPaymentStrategy* paymentStrategy){
        this->paymentStrategy=paymentStrategy;
    }

    void pay(int amount){
        paymentStrategy->pay(amount);
    }

    void updatePaymentStrategy(IPaymentStrategy* paymentStrategy){
        this->paymentStrategy=paymentStrategy;
    }

};


int main(){
    //create payment service
    PaymentService* paymentService=new PaymentService(new PayViaCreditcard);
    paymentService->pay(1000);
    //changed strategy at runtime
    paymentService->updatePaymentStrategy(new PayViaUPI);
    paymentService->pay(2000);

    return 0;
}