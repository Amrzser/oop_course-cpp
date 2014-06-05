// name: library.h
// author: amrzs
// date: 20140427

#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>

#include "media.h"
#include "cd.h"
#include "dvd.h"

using namespace std;

typedef Media* pMedia;
typedef vector<pMedia> pMedias;


class Library{

public:
    Library(){}
    ~Library();

private:
    pMedias meds;

public:
    
    void addMedia();
    void findMedia(string title); 
    void listAll();    
};

#endif // LIBRARY_H
