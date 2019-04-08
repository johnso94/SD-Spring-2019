#ifndef _INTSTACK_
#define _INTSTACK_

#include<iostream>
using namespace std;

class IntStack{
    public:
    int* numbers;
    int size;
    int pos;
    IntStack(unsigned int n){
        pos = 0;
        size = n;
        numbers = new int[size];
    }
    IntStack(){
        pos = 0;
        size = 100;
        numbers = new int[size];
    }
    ~IntStack(){
        delete[] numbers;
    }
    int getSize();
    int getPos();
    void pop();
    int top();
    void push(int i);
    void reverse();
};
#endif