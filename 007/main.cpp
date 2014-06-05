// name:   main.cpp
// author: Amrzs
// date:   2014/05/23

#include <iostream>

#include "vector.h"

using namespace std;

int main(int argc, char const *argv[]){

    Vector<int> v1;
    cout << "Length of vector1: " << v1.size() << endl;

    cout << "Length of vector2: " << endl;
    cout << ">>> ";
    int len;
    cin >> len;
    Vector<int> v2(len);
    cout << "Length of vector2: " << v2.size() << endl;

    cout << "Add size of vector2" << endl;
    cout << ">>> ";
    int addSize;
    cin >> addSize;
    v2.inflate(addSize);
    cout << "Length of vector2: " << v2.size() << endl;

    cout << "Input " << v2.size() << " elements in v2" << endl;
    for (int i = 0; i < v2.size(); i++)
        cin >> v2[i];

    Vector<int> v3(v2);
    cout << "Length of vector3: " << v3.size() << endl;
    int index;
    while(true){
        cout << "Input index of v3" << endl;
        cout << ">>> ";
        cin >> index;

        try{
            cout << v3[index] << endl;
        }catch (IndexOutofBounds e){
            cout << "IndexOutofBounds" << endl;
        }
    }


    return 0;
}