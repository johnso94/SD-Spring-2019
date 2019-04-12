#include"DVDArrayP.h"
#include<iostream>
using namespace std;

    int DVDArrayP::getSize(){
        return size;
    }
    DVDArrayP& DVDArrayP::operator=(const DVDArrayP &arr){
        size = arr.size;
        for(int i = 0; i < size; i++){
            if(arr.elt[i]!=0){
                delete elt[i];
            }
        }
        elt = new DVD*[size];
        for(int i = 0; i< size; i++){
            if(arr.elt[i]!= 0){
                elt[i] = new DVD (*(arr.elt[i]));
            }
        }
        return * this;
    }
    void DVDArrayP::display(){
        for(int i=0; i<size; i++){
            if(elt[i]!=0){
                int t =i+1;
                cout << i << ":  [" << t << ".  " << (*(elt[i])).title << '/'
                << (*(elt[i])).director << ']' << endl;
            }
        }
    }
    DVD& DVDArrayP::operator[](int i){
        if(i > (size-1)){
            cout << "Warning! Invalid index! Abort Mission!" << endl;
            if (elt[0]== 0){
                elt[0] = new DVD;
            }
            return (*elt[0]);
        }
        else if(i<0){
            cout << "Warning! Invalid index! Abort Mission!" << endl;
            if (elt[size-1]==0){
                elt[size-1] = new DVD;
            }
            return (*elt[size-1]);
        }
        else{
            if (elt[i]==0){
                elt[i] = new DVD;
            }
            return (*elt[i]);
        }
    }