#include<iostream>
using namespace std;

//independent sub service
class PaymentService{
    public:
    void makePayment(string orderId,int amount){
        cout<<"Payment for orderId: "<<orderId<<" Amount: "<<amount<<" Successfull"<<endl;
    }
};

//independent sub service
class NotificationService{
    public:
    void notifyBooking(string email,string orderId){
        cout<<"User: "<<email<<" Notified for orderId: "<<orderId<<endl;
    }
};

//independent sub service
class LoyaltyService{
    public:
    void grantLoyaltyPoint(string email,string orderId){
        cout<<"Reward point: 100 for user: "<<email<<" for orderId: "<<orderId<<" added successfully"<<endl;
    }
};

//Facade pattern putting related subsystems under one class (Exposing simplified api instead of handling everything clien side)
class BookingFaced{
    private:
    PaymentService paymentService;
    NotificationService notificationService;
    LoyaltyService loyaltyService;

    public:
    void makeBooking(string email,string orderId,int amount){
        paymentService.makePayment(orderId,amount);
        notificationService.notifyBooking(email,orderId);
        loyaltyService.grantLoyaltyPoint(email,orderId);
    }
};

int main(){
    BookingFaced bookingService;
    bookingService.makeBooking("rahmankaifur8@gmail.com","OID1290",990);
    return 0;
}