#include<bits/stdc++.h>
using namespace std;

/*
You’re building a Car Simulation Game.
Thousands of cars are displayed on a map.

Each car has:
Name, Color, Brand → Intrinsic (shared)
Current position (x, y), Extrinsic (unique)

Implement a Flyweight-based system to:
Create cars efficiently
Avoid redundant model objects

Display all cars’ details using shared flyweights*/

//holds intrinsic properties
class CarType{
    protected:
    string name,color,brand; //Intrinsic Properties
    
    public:
    CarType(){};
    CarType(string name,string color,string brand){
        this->name=name;
        this->color=color;
        this->brand=brand;
    }
    
    string getCarName(){
        return name;
    }
    
    string getCarColor(){
        return color;
    }
    
    string getCarBrand(){
        return brand;
    }

};

//Flyweight manager 
class CarFactory{
    protected:
    static unordered_map<string,CarType*>map;

    public:
    //name+color+brand acts as unique id of car type
    static CarType* getCarType(string name,string color,string brand){
        if(map.find(name+color+brand)!=map.end()){
            //already exist
            return map[name+color+brand];
        }else{
            //new car type
            CarType* newCarType=new CarType(name,color,brand);   
            map[name+color+brand]=newCarType;    
            return newCarType;    
        }
    }
    static int getUniqueCarsCount(){
        return map.size();
    }
};

//global initalization of static member of class
unordered_map<string, CarType*> CarFactory::map;

//Actual car that holds extrinisic + intrinsic properties
class Car{
    protected:
    int posX,posY; //extrinsic
    CarType* carType; //intrinsic 

    public:
    //construtor
    Car(int posX,int posY,string name,string color,string brand){
        this->carType=CarFactory::getCarType(name,color,brand);
        this->posX=posX;
        this->posY=posY;
    }

    void displayCar(){
        cout<<"Car Name: "<<carType->getCarName()<<" Car Color: "<<carType->getCarColor()<<" Car Brand: "<<
        carType->getCarBrand()<<" Pos X: "<<this->posX<<" Pos Y: "<<this->posY<<endl;
    }
};

int main(){
    vector<Car>cars;
    
    for(int i=0;i<10;i++){
        Car car(i,i,"Scorpio","Black","Mahindra");
        cars.push_back(car);
    }

    for(int i=0;i<20;i++){
        Car car(i,i,"Thar","Black","Mahindra");
        cars.push_back(car);
    }

    for(auto &car:cars){
        car.displayCar();
    }

    cout<<"No. of unique cars: "<<CarFactory::getUniqueCarsCount();
    return 0;
}