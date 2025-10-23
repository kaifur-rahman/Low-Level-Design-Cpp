#include<iostream>
using namespace std;

//base product interface
class IBasePizza{
    public:
    virtual string getDescription()=0;
    virtual int getCost()=0;
    virtual ~IBasePizza(){};
};

//concrete product type
class Maghreta:public IBasePizza{
    public:
    string getDescription ()override{
      return "Maghreata pizza";
    }
    int getCost()override{
        return 100;
    }
};

//concrete product type
class PannerDelight:public IBasePizza{
    public:
    string getDescription ()override{
        return "Panner Delight pizza";
    }
    int getCost()override{
        return 130;
    }
};

//decorator abstract class
class PizzaDecorator:public IBasePizza{
    protected:
    IBasePizza* pizza;
    public:
    PizzaDecorator(){};
    PizzaDecorator(IBasePizza* pizza){
        this->pizza=pizza;
    }
};

//decorator layer
class ExtraCheese:public PizzaDecorator{
    public:
    ExtraCheese(IBasePizza* pizza){
        this->pizza=pizza;
    }

    string getDescription()override{
        return pizza->getDescription()+" with extra cheese";
    }
    int getCost()override{
        return pizza->getCost()+20;
    }
};

//decorator layer
class ExtraSausage:public PizzaDecorator{
    public:
    ExtraSausage(IBasePizza* pizza){
        this->pizza=pizza;
    }
    string getDescription()override{
        return pizza->getDescription()+" with extra sausage";
    }
    int getCost()override{
        return pizza->getCost()+10;
    }
};

int main(){
    //Adding feature layer by layer on top of base feature
   IBasePizza* mPizza=new Maghreta();
   cout<<mPizza->getDescription()<<endl;
   cout<<mPizza->getCost()<<endl;
   IBasePizza* mcPizza=new ExtraCheese(mPizza);
   cout<<mcPizza->getDescription()<<endl;
   cout<<mcPizza->getCost()<<endl;
   IBasePizza* mcsPizza=new ExtraSausage(mcPizza);
   cout<<mcsPizza->getDescription()<<endl;
   cout<<mcsPizza->getCost()<<endl;
   //try another combination
   IBasePizza* pannerWithSausage=new ExtraSausage(new PannerDelight());
   cout<<pannerWithSausage->getDescription()<<endl;
   cout<<pannerWithSausage->getCost()<<endl;

   delete mPizza;
   delete mcPizza;
   delete mcsPizza;
   delete pannerWithSausage;
    return 0;
}