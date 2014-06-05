// name:   main.cpp
// author: Amrzs
// date:   2014/05/17

#include <iostream>
#include <string>
#include "frac.h"

using namespace std;

int main(int argc, char const *argv[]){

    Frac frac1_3(1, 3), frac1_2(-2, 4);

    cout << frac1_3 << endl << frac1_2 << endl;

    cout << frac1_2 / frac1_3 << endl;
    cout << frac1_2 - frac1_3 << endl;

    Frac frac;
    cout << ">>> ";
    cin >> frac;
    cout << frac << endl;

    cout << double(frac1_2) << endl;

    cout << (frac1_3 >= frac1_2) << endl;

    return 0;
}