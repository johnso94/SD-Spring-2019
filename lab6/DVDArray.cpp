#include<iostream>
using namespace std;
#include "DVDArray.h"
#include "DVD.h"

unsigned int DVDArray::getSize(){
    return size;
}
void DVDArray::display(){
    for(int i = 0; i < size; i++){
        cout << i << ":  [" << elt[i].id << 
        ".  " << elt[i].title << '/' << 
        elt[i].director << ']' << endl;
    }
}
DVDArray& DVDArray::operator=(const DVDArray &d){
    delete[] elt;
    size = d.size;
    elt = new DVD[d.size];
    for(int i = 0; i < d.size; i++){
        elt[i] = d.elt[i];
    }
    return *this;
}
DVD& DVDArray::operator[](int i){
    if(i >= 0 && i <= (size-1)){
        return elt[i];
    }
    else{
        cout << "The array does not have a " << i <<
        "-th element." <<endl;
        if(i < 0){
            return elt[0];
        }
        else{
            return elt[size - 1];
        }
    }
    return elt[0];
}
