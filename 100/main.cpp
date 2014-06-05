// name: main.cpp
// author: amrzs
// date: 20140428


#include <iostream>
#include <string>

#include "library.h"

using namespace std;


int main(){

    Library lib;

    lib.addMedia();
    lib.addMedia();

    cout << "Input title and select a media" << endl;
    cout << ">>> ";
    string title;
    cin >> title;
    lib.findMedia(title);

    lib.listAll();

    return 0;
}
