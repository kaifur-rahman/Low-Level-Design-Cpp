#include<iostream>
using namespace std;

/*Singleton Design Pattern
Thread Safe: By default
Eager loading: Automatically initialized before the program main starts
*/

class Database{
    private:
        //static database instance pointer
       static Database* db;
       //private constructor to avoid direct initialization
       Database(){
        cout<<"Database instance has been created"<<this<<endl;
       }
       //private destructor to avoid direct deletion 
       ~Database(){
        cout<<"Database instance has been deleted"<<endl;
       }
        //more safe by avoiding copy constructor and overloading equal assignment operator
        Database(Database&)=delete;
        Database& operator =(Database&)=delete;
    public:
       static Database* getInstance(){
        return db;
       }
       void someOperation(){
        cout<<"Some operation has been performed by "<<this<<endl;
       }
};
//Eager loading (by default thread safe since its created before main runs)
Database* Database::db=new Database();

int main(){
    Database* db1=Database::getInstance();
    db1->someOperation();
    Database* db2=Database::getInstance();
    db2->someOperation();
    return 0;
}