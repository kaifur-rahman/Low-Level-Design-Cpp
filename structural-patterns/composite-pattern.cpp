#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//Design System to display organization hierarchy system

class Developer{
    private:
    string name;
    
    public:
    Developer(string name){
        this->name=name;
    }
    
    void showDetails(){
        cout<<"Developer: "<<name<<endl;
    }
};

class Manager{
    private:
    string name;
    
    public:
    Manager(string name){
        this->name=name;
    }
    
    void showDetails(){
        cout<<"Manager: "<<name<<endl;
    }
};

class CEO{
    private:
    string name;
    
    public:
    CEO(string name){
        this->name=name;
    }
    
    void showDetails(){
        cout<<"CEO: "<<name<<endl;
    }
};

//soln similar interface
class IEmployee{
    public:
    virtual void showHierarchy()=0;
    virtual ~IEmployee(){}
};

//leaf
class DeveloperI:public IEmployee{
    private:
    string name;
    
    public:
    DeveloperI(string name){
        this->name=name;
    }

    void showHierarchy()override{
        cout<<"Developer: "<<name<<endl;
    }
};

//composite
class ManagerI:public IEmployee{
    private:
    string name;
    vector<IEmployee*>employees;
    
    public:
    ManagerI(string name){
        this->name=name;
    }

    void addEmployee(IEmployee* emp){
        employees.push_back(emp);
    }

    void showHierarchy()override{
        cout<<"Manager: "<<name<<endl;
        for(auto emp:employees){
            emp->showHierarchy();
        }
    }
};

//another composite
class CEOI:public IEmployee{
    private:
    string name;
    vector<IEmployee*>employees;

    public:

    CEOI(string name){
        this->name=name;
    }

    void addEmployee(IEmployee* emp){
        employees.push_back(emp);
    }

    void showHierarchy()override{
        cout<<"CEO: "<<name<<endl;
        for(auto emp:employees){
            emp->showHierarchy();
        }
    }
};


int main(){

    //issue all independent but if ceo->show details it wont show which managers under it and 
    // CEO* ceo=new CEO("Kaifur");
    // ceo->showDetails();
    
    // Manager* m1=new Manager("m1");
    // Manager* m2=new Manager("m2");
    
    // Developer* d1=new Developer("d1");
    // Developer* d2=new Developer("d2");
    // Developer* d3=new Developer("d3");
    // Developer* d4=new Developer("d4");
    //cant treat manager developer ceo same way we need something employe->showDetails 

    CEOI* ceo=new CEOI("Kaifur");
    
    ManagerI* m1=new ManagerI("M1");
    ManagerI* m2=new ManagerI("M2");

    IEmployee* d1=new DeveloperI("D1");
    IEmployee* d2=new DeveloperI("D2");
    IEmployee* d3=new DeveloperI("D3");
    IEmployee* d4=new DeveloperI("D4");

    ceo->addEmployee(m1);
    ceo->addEmployee(m2);

    m1->addEmployee(d1);
    m1->addEmployee(d2);

    m2->addEmployee(d3);
    m2->addEmployee(d4);


    ceo->showHierarchy();

    m2->showHierarchy();

    d2->showHierarchy();

    return 0;
}