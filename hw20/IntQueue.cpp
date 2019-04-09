#include<iostream>
using namespace std;
#include"IntQueue.h"

int IntQueue::getSize(){
    return size;
}
int IntQueue::getFront(){
    return front;
}
int IntQueue::getBack(){
    return back;
}
void IntQueue::incSize(){
    int a[size];
    for(int i = 0; i<size; i++){
        a[i] = numbers[i];
    }
    delete[] numbers;
    size *= 2;
    numbers = new int[size];
    for(int i=0; i < size/2; i++){
        numbers[i] = a[i];
    }
}
void IntQueue::Stack(){
    int n = front;
    while(numbers[n++] != 0){}
    for(int i=front; i<n-1; i++){
        cout << numbers[i] << " ";
    }
    cout << endl;
}
void IntQueue::pop(){
    if(front == back){
        cout << "The queue is empty" << endl;
    }
    else{
        numbers[front] = 0;
        front++;
    }
}
int IntQueue::frontNumber(){
    return numbers[front];
}
void IntQueue::push(int i){
    if(numbers[front] && front == back){
        cout << "The queue is full" << endl;
    }
    else{
        numbers[back] = i;
        back ++;
    }
}
void IntQueue::reverse(){
    int n = front;
    while(numbers[n++] != 0){}
    n--;
    int a[n];
    for(int i=front; i < n; i++){
        a[i] = numbers[i];
    }
    delete[] numbers;
    numbers = new int[size];
    for(int i= front; i<n; i++){
        numbers[i] = a[n-i ];
    }
}