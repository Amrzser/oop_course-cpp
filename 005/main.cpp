// name:   main.cpp
// author: Amrzs
// date:   2014/05/11

#include <iostream>

using namespace std;

#include "castle.h"

int main(int argc, char const *argv[]){
    
    Castle castle("Good Castle", "castle.txt");

    castle.run();

    return 0;
}