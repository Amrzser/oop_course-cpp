// name: media.h
// author: amrzs
// date: 20140427

#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <string>

using namespace std;

class Media{

public:
    Media(string title):
        title(title){
    }
    virtual ~Media(){}

private:
    string title;

public:
    string getTitle() const{

        return title;
    }
    
    void setTitle(const string title){
    
        this->title = title;
    }

    virtual void showPros() = 0;
};


#endif //MEDIA_H
