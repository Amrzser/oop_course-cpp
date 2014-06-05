// name:   vector.h
// author: Amrzs
// date:   2014/05/23

#ifndef VECTOR_H
#define VECTOR_H

#include <cstring>

using namespace std;

class IndexOutofBounds {};  // the exception class

template <typename T>       // maybe typename is a good choice
class Vector {
public:
    Vector():
        m_nSize(0),
        m_pElements(NULL){
    }
    Vector(int size):
        m_nSize(size){
        m_pElements = new T[m_nSize];
    }
    Vector(const Vector& r){
        m_nSize = r.m_nSize;
        m_pElements = new T[m_nSize];
        if(m_pElements)
            memcpy(m_pElements, r.m_pElements, m_nSize*sizeof(T));
    }

    virtual ~Vector(){
        delete [] m_pElements;
    }

private:
    T *m_pElements;
    int m_nSize;

public:
    T& operator[](int index) throw(IndexOutofBounds){

        if(index < 0 || index >= m_nSize)
            throw(IndexOutofBounds());
        return m_pElements[index];
    }

    int size() const {
        return m_nSize;
    }

    int inflate(int addSize){

        T *pElements = new T[m_nSize + addSize];
        memcpy(pElements, m_pElements, m_nSize*sizeof(T));
        m_nSize += addSize;
        delete [] m_pElements;
        m_pElements = pElements;
    }
};


#endif // VECTOR_H