#ifndef _INTQUEUE_H_
#define _INTQUEUE_H_

#include<iostream>
using namespace std;

class IntQueue{
    int * numbers;
    int size;
    int front;
    int back;
    public:
    IntQueue(unsigned int n){
        size = n;
        front = 0;
        back = 0;
        numbers = new int[size];
        for(int i = 0; i< size; i++){
            numbers[i] = 0;
        }
    }
    IntQueue(){
        size = 100;
        front = 0;
        back = 0;
        numbers = new int[size];
        for(int i = 0; i< size; i++){
            numbers[i] = 0;
        }
    }
    ~IntQueue(){
        delete[] numbers;
    }
    int getSize();
    int getFront();
    int getBack();
    void Stack();
    void incSize();
    void pop();
    int frontNumber();
    void push(int i);
    void reverse();
};
#endif