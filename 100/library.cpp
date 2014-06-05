// name: library.cpp
// author: amrzs
// date: 20140427

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

#include "library.h"

using namespace std;


Library::~Library(){

    for(pMedias::iterator iter = meds.begin(); iter != meds.end(); iter++){
        
        delete (*iter);
    }
}

void Library::addMedia(){

    cout << "CD or DVD?" << endl;
    string sMedia;
    cin >> sMedia;
    if("CD" == sMedia){

        cout << "Please input title, artist and number of tracks" << endl;
        cout << ">>> ";
        string title;
        string artist;
        int trackNum;
        cin >> title >> artist >> trackNum;

        pMedia pMed = new Cd(title, artist, trackNum);
        meds.push_back(pMed);
    }else{

        cout << "Please input title, director and length of film" << endl;
        cout << ">>> ";
        string title;
        string director;
        int filmLen;
        cin >> title >> director >> filmLen;

        pMedia pMed = new Dvd(title, director, filmLen);
        meds.push_back(pMed);
    }

}

void Library::findMedia(string title){

    for(pMedias::iterator iter = meds.begin(); iter != meds.end(); iter++){

        if((*iter)->getTitle() == title){

            (*iter)->showPros();
            return;
        }
    }
}

void Library::listAll(){

    cout << "All the medias here: " << endl;
    
    for_each(meds.begin(), meds.end(), mem_fun(&Media::showPros));
}


