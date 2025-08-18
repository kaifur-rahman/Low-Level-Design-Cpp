#include<iostream>
using namespace std;
//Document Management system that allow to clone a doc of different types and modify its conent and save as copy

//interface for different types of document
class Document{
    public:
    virtual Document* clone()=0;
    virtual void showContent()=0;
    virtual void updateContent(string update)=0;
    virtual ~Document()=default;
};

class PDF:public Document{
    public:
    //suppose these are expensive initializations
    string content="This is a pdf document";
    
    void showContent ()override{
        cout<<content<<endl;
    }
    void updateContent(string update)override{
        content+=update;
    }
    Document* clone()override{
        //saved expensive initialization and just copying it to new object
        return new PDF(*this);
    }
};

class Text:public Document{
    public:
        string content="This is a text document";

        void showContent()override{
            cout<<content<<endl;
        }
        void updateContent(string update)override{
            content+=update;
        }
        Document* clone()override{
            return new Text(*this);
        }
};

int main(){
    PDF* pdfOriginal=new PDF();
    pdfOriginal->showContent();
    pdfOriginal->updateContent(" Added one more line");
    pdfOriginal->showContent();

    Document* newPdf=pdfOriginal->clone();
    newPdf->showContent();
    newPdf->updateContent(" Added update on cloned pdf");
    pdfOriginal->showContent();
    newPdf->showContent();
    return 0;
}