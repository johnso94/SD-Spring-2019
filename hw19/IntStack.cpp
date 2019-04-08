#include<iostream>
using namespace std;
#include "IntStack.h"

int IntStack::getSize(){
    return size;
}
int IntStack::getPos(){
    return pos;
}
void IntStack::pop(){
    if (pos>0){
        pos -= 1;
        numbers[pos] = 0;
    }
}
int IntStack::top(){
    if (pos>0){
        return numbers[pos - 1];
    }
    else {
        return 1;
    }
}
void IntStack::push(int i){
    if (pos == size){}
    else{
        numbers[pos] = i;
        pos +=1;
    }
}
void IntStack::reverse(){
    int array[5];
    for(int i=0; i<pos; i++){
        array[i] = numbers[i];
    }
    for(int i=0; i<pos; i++){
        numbers[pos -1 - i] = array[i];
    }
}