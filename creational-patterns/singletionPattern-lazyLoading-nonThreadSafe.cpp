#include<iostream>
using namespace std;

/*Singleton Design Pattern
Non Thread Safe 
Lazy loading: Needs to be initiated manually
*/

class Database{
    private:
        //single instance pointer
        static Database* db;
        
        //constructor avoid direct initialzation
        Database(){
            cout<<"Database instance has been created: "<<this<<endl;
        }
        //Destructor 
        ~Database(){
            cout<<"Database instance has been deleted"<<endl;
        }
        //make it more safe by not allowing copy constructor 
        Database(Database&)=delete;
        //equal operator overload
        Database operator=(Database&)=delete;
        
    public:
        static Database* getInstance(){
            if(db==nullptr){
                db=new Database();
            }
            return db;
        }
        static void deleteInstance(){
            delete db;
            db=nullptr;
            cout<<"Instance has been deleted"<<endl;
        }
        void someOperation(){
            cout<<"Some operations has been performed by "<<this<<endl;
        }
};

Database* Database::db=nullptr;
int main(){
    Database* db1=Database::getInstance();
    db1->someOperation();
    Database* db2=Database::getInstance();
    db2->someOperation();
    db2->deleteInstance();
    return 0;
}