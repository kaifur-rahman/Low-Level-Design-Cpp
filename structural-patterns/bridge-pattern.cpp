#include<bits/stdc++.h>
using namespace std;

/*You are building a Document Viewer application that supports:

Different document types: PDF, Word, Excel

Different rendering modes: Light Mode, Dark Mode, High Contrast Mode

Each document type can be displayed in any rendering mode.

You don’t want to create classes like:

PDFLightMode, PDFDarkMode, WordLightMode, etc. (combinatorial explosion!)
*/

//Rendering modes can scale independently (This is implementation)
class IMode{
    public:
    virtual string value()=0;
};


class DarkMode:public IMode{
    public:
    string value()override{
        return "dark mode";
    }
};

class LightMode:public IMode{
    public:
   string value()override{
    return "light mode";
   }
};

//new mode comes in independetly

class HighContrastMode:public IMode{
    public:
    string value()override{
        return "high contrast mode";
    }
};

//Document can scale independently (This is abstraction)
class IDocument{
    protected:
    IMode* mode; //bridge reference (the abstraction “uses” the implementation via a reference  that’s the bridge composition.)
    public:
    IDocument(IMode* mode){
        this->mode=mode;
    }
    virtual void render()=0;
};


class PDF:public IDocument{
    public:
    PDF(IMode* mode):IDocument(mode){};
    void render(){
        cout<<"Rendering PDF Doc in "<<this->mode->value()<<endl;
    }
};

class Word:public IDocument{
    public:
    Word(IMode* mode):IDocument(mode){};
    void render(){
        cout<<"Rendering Word Doc in "<<this->mode->value()<<endl;
    }
};

int main(){
    IDocument* pdf=new PDF(new DarkMode());
    pdf->render();

    IDocument* pdfLight=new PDF(new LightMode());
    pdfLight->render();

    IDocument* wordHigh=new Word(new HighContrastMode());
    wordHigh->render();
    return 0;
}