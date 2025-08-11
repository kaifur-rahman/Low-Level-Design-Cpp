#include<iostream>
using namespace std;

class House{
    private:
        //mandatory fields
        int floors;
        int rooms;
        //optional fields
        bool swimmingPool;
        bool garden;
        bool parking;

        //private constructor so avoid direct intialization
        House(int floors,bool swimmingPool,bool garden,int rooms,bool parking){
            this->floors=floors;
            this->swimmingPool=swimmingPool;
            this->garden=garden;
            this->rooms=rooms;
            this->parking=parking;
        }

        //friend class to get access of private constructor 
        friend class HouseBuilder;
    public:
    void showHouse(){
        cout<<"Floors: "<<floors<<endl<<"Rooms: "<<rooms<<endl<<"Swimming Pool: "<<swimmingPool<<endl<<"Garden: "<<garden<<endl<<"Parking: "<<parking<<endl;
    }
};
class HouseBuilder{
    private:
        //mandatory fields
        int floors;
        int rooms;
        //optional fields by default false
        bool swimmingPool=false;
        bool garden=false;
        bool parking=false;
    public:
        //public constructor
        HouseBuilder(int floors,int rooms){
            this->floors=floors;
            this->rooms=rooms;
        }
        //functions to add optional fields
        HouseBuilder* addSwimmingPool(bool swimmingPool){
            this->swimmingPool=swimmingPool;
            return this;//return to make method chaining possible
        }
        HouseBuilder* addGarden(bool garden){
            this->garden=garden;
            return this;
        }
        HouseBuilder* addParking(bool parking){
            this->parking=parking;
            return this;
        }
        //builder function to buil finally
        House build(){
            return House(floors,swimmingPool,garden,rooms,parking);
        }
};

int main(){
    House newHouse=HouseBuilder(2,4).addSwimmingPool(true)->addGarden(true)->build();
    newHouse.showHouse();
    return 0;
}