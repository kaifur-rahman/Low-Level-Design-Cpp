#include<bits/stdc++.h>
using namespace std;
/*
to design a system to represent a Music Playlist and provide a way to iterate through all the songs in it without exposing the underlying data structure.

Each song has: title, artist, duration (in seconds)

Your playlist class should:

Allow adding songs. Allow creating an iterator to traverse songs sequentially.

The iterator should provide methods:

hasNext() → returns true if there are more songs.

next() → returns the next song.

*/

//interfaces
class ISong{
    public:
    string title;
    string artist;
    int duration;
};

class IIterator{
    public:
    virtual bool hasNext()=0; //next item exist?
    virtual ISong* next()=0;  //returns current item and moves index to next
};

class IPlaylist{
    protected:
    vector<ISong*>songs;
    
    public:
    virtual void addSong(ISong* song)=0;
    virtual IIterator* createIterator()=0; //to create a iterator for it
};

//song concrete
class Song:public ISong{
    public:
    //constructor
    Song(string title,string artist,int duration){
        this->title=title;
        this->artist=artist;
        this->duration=duration;
    }
};

//Iterator concrete
class Iterator:public IIterator{
    private:
    int idx=0;
    vector<ISong*>songs;
    
    public:
    //Imp: constructor while creating iterator pass its collection
    Iterator(vector<ISong*>songs){
        this->songs=songs;
    }
    
    bool hasNext(){
        if (idx>=songs.size()){
            return false;
        }else{
            return true;
        }
    }

    ISong* next(){
        return songs[idx++];
    }
};

//Playlist create with iterator
class Playlist:public IPlaylist{
    private:
    IIterator* iterator=nullptr;
    
    public:
    void addSong(ISong* song){
        songs.push_back(song);
    }
    
    IIterator* createIterator(){
        this->iterator=new Iterator(this->songs);
        return iterator;
    }
};

int main(){
    //create songs independetly
    ISong* s1=new Song("Abc","Song-1",120);
    ISong* s2=new Song("Def","Song-2",140);
    ISong* s3=new Song("Ghi","Song-3",60);
    
    //creating playlist independtly
    IPlaylist* playlist=new Playlist();

    //adding song to playlist
    playlist->addSong(s1);
    playlist->addSong(s2);
    playlist->addSong(s3);

    //create iterator for this playlist
    IIterator* iterator=playlist->createIterator();

    //iterate over playlist without know its internal state and datastructure
    while(iterator->hasNext()){
        ISong* song=iterator->next();
        cout<<song->artist<<" "<<song->title<<" "<<song->duration<<endl;
    }
    return 0;
}