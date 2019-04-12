#ifndef _DVDARRAYP_H_
#define _DVDARRAYP_H_

#include"DVD.h"
#include<iostream>
using namespace std;

class DVDArrayP{
    DVD ** elt;
    int size;
    int DEFAULT_SIZE = 100;
    public:
    DVDArrayP(unsigned int sz){
        size = sz;
        elt = new DVD*[sz];
        for(int i=0; i< size; i++){
            elt[i] = 0;
        }
    }
    DVDArrayP(){
        size = DEFAULT_SIZE;
        elt = new DVD*[DEFAULT_SIZE];
        for(int i=0; i< size; i++){
            elt[i] = 0;
        }
    }
    DVDArrayP(const DVDArrayP &arr){
        size = arr.size;
        elt = new DVD*[arr.size];
        for(int i = 0; i< size; i++){
            if(arr.elt[i]!=0){
                elt[i] = new DVD (*(arr.elt[i]));
            }
        }
    }
    ~DVDArrayP(){
        for(int i; i< size-1; i++){
            if(elt[i]!=0){
                delete elt[i];
            }
        }
        delete[] elt;
    }
    int getSize();
    DVDArrayP& operator=(const DVDArrayP &arr);
    void display();
    DVD& operator[](int i);
};
#endif