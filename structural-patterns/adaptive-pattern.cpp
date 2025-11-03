#include<iostream>
using namespace std;

//legacy code
class IPaymentGateway{
    public:
    virtual void  pay(string orderId,int amount)=0;
    virtual ~IPaymentGateway(){};
};

//legacy code
class PayUPaymentGateway:public IPaymentGateway{
    public:
    void pay(string orderId,int amount){
        cout<<"Payment for orderId: "<<orderId<<" Successfull"<<endl;
    }
};

//legacy code
class CheckoutService{
    private:
    IPaymentGateway* paymentGateway;
    
    public:
    CheckoutService(IPaymentGateway* paymentGateway){
        this->paymentGateway=paymentGateway;
    }
    void checkout(string orderId,int amount){
        paymentGateway->pay(orderId,amount);
    }
};

//future 3rd party integration with different functions and API calls
class RazorpayAPI{
    public:
    //differnt function
    void makePayment(string invoiceId,int invoiceAmount){
        cout<<"Razorpay Payment Initiated"<<endl;
    }
};

//to integrate with legacy code make adapater
class RazorPayAdapter:public IPaymentGateway{
    private:
    RazorpayAPI* paymentgateway=new RazorpayAPI();
    
    public:
        void pay(string orderId,int amount){
            paymentgateway->makePayment(orderId,amount);
            cout<<"Payment for orderId: "<<orderId<<" Successfull"<<endl;
    }
};

int main(){
    string orderId;
    int amount;
    cout<<"Enter orderId: ";
    cin>>orderId;
    cout<<"Enter Amount: ";
    cin>>amount;

    CheckoutService* checkoutService=new CheckoutService(new PayUPaymentGateway());
    checkoutService->checkout(orderId,amount);
    //seamless integration with 3rd pary without changing legacy code
    CheckoutService* thirdPartyCheckoutService=new CheckoutService(new RazorPayAdapter());
    checkoutService->checkout(orderId,amount);

    delete checkoutService;
    return 0;
}