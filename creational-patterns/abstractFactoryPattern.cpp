#include<iostream>
using namespace std;
/*
To implement vehicle factory which can produce 2 types of vehicle Electric|Gasoline
and each type car produce Car and Bike of that type
*/
class IVehicle{
    public:
    virtual void drive()=0;
    virtual ~IVehicle()=default;
};

class ElectricCar:public IVehicle{
    public:
        void drive()override{
            cout<<"Driving Electric Car"<<endl;
        }
};
class GasolineCar:public IVehicle{
    public:
        void drive()override{
            cout<<"Driving Gasoline Car"<<endl;
        }
};

class ElectricBike:public IVehicle{
    public:
        void  drive()override{
            cout<<"Driving Electric Bike"<<endl;
        }
};

class GasolineBike:public IVehicle{
    public:
        void drive()override{
            cout<<"Driving Gasoline Bike"<<endl;
        }
};
class IVehicleFactory{
    public:
        virtual IVehicle* produceCar()=0;
        virtual IVehicle* produceBike()=0;
        virtual ~IVehicleFactory()=default;
};

class ElectricFactory:public IVehicleFactory{
    public:
        IVehicle* produceCar(){
            return new ElectricCar();
        }
        IVehicle* produceBike(){
            return new ElectricBike();
        }
};

class GasolineFactory:public IVehicleFactory{
    public:
        IVehicle* produceCar(){
            return new GasolineCar();
        }
        IVehicle* produceBike(){
            return new GasolineBike();
        }
};

class FactoryService{
    public:
    static IVehicleFactory* getVehicleFactory(string productType){
        if(productType=="electric"){
             return new ElectricFactory();
        }else{
            return new GasolineFactory();
        }
    }
};

int main(){
    IVehicleFactory* eFactory=FactoryService::getVehicleFactory("electric");
    IVehicle* car=eFactory->produceCar();
    car->drive();
    eFactory->produceBike()->drive();

    IVehicleFactory* gFactory=FactoryService::getVehicleFactory("gasoline");
    IVehicle* gbike=gFactory->produceBike();
    gbike->drive();

    delete eFactory;
    delete gFactory;
    delete car;
    delete gbike;
    return 0;
}