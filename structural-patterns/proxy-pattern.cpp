#include<bits/stdc++.h>
using namespace std;

/*Proxy Pattern Question
The Scenario: E-book Reader Access Control 

You are designing a system for a digital library. Users can access e-books, but there are certain restrictions:
1. Guest users (not logged in) can only view the TOC (Table of Contents) but not the book content.
2. Authenticated users (logged in) can view both the TOC and the book content.
3. The actual process of loading and rendering the book content is resource-intensive and should only happen if the user is authorized.
*/

class User{    
    public:
    bool authenticated=false;
    //constructor
    User(bool authenticated){
        this->authenticated=authenticated;
    }
};

class IBook{
    public:
    virtual string viewTOC ()=0;
    virtual string viewContent()=0;
    virtual ~IBook()=default;
};

class Book:public IBook{
    protected:
    string toc="This is the table of content";
    string content="This is the content";
    
    public:
    string viewTOC()override{
        return toc;
    }

    string viewContent()override{
        return content;
    }
};

class BookProxy:public IBook{
    protected:
    IBook* book=nullptr;
    User* user=nullptr;
    
    public:
    BookProxy(IBook* book,User* user){
        this->book=book;
        this->user=user;
    }
    
    string viewTOC(){
        cout<<book->viewTOC()<<endl;
    }

    string viewContent(){
        if(user->authenticated){
            cout<<book->viewContent()<<endl;
        }else{
            cout<<"User is not autenticated"<<endl;
        }
    }
};

int main(){
    //auth
    User* u1=new User(true);
    //not auth
    User* u2=new User(false);

    Book* b1=new Book();
    
    BookProxy* b1Reader=new BookProxy(b1,u1);
    BookProxy* b1Reader2=new BookProxy(b1,u2);

    b1Reader->viewTOC();
    b1Reader2->viewTOC();

    b1Reader->viewContent();
    b1Reader2->viewContent();

    return 0;
}