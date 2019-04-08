#ifndef _DVDArray_
#define _DVDArray_

#include "DVD.h"
#include<iostream>
using namespace std;


class DVDArray{
    public:
    DVD * elt;
    unsigned int size;
    unsigned int DEFAULT_SIZE=10;
    DVDArray(unsigned int sz){
        size = sz;
        elt = new DVD[sz];
    }
    DVDArray(){
        size = DEFAULT_SIZE;
        elt = new DVD[DEFAULT_SIZE];
    }
    DVDArray(const DVDArray &d){
        size = d.size;
        elt = new DVD[d.size];
        for(int i = 0; i< d.size; i++){
            elt[i] = d.elt[i];
        }
    }
    ~DVDArray(){
        delete [] elt;
    }
    unsigned int getSize();
    void display();
    DVDArray& operator=(const DVDArray &d);
    DVD& operator[](int n);
};
#endif //_DVDArray_
