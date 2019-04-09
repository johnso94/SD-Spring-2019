#include<iostream>
using namespace std;
#include "IntQueue.h"

int main(){
    IntQueue a;
    IntQueue a2(5);
    a2.pop();
    for(int i=0; i < 5; i++){
        a2.push(11 - 2*i);
        a2.Stack();
    }
    a2.pop();
    a2.Stack();
    a2.incSize();
    a2.incSize();
    a2.push(11);
    a2.push(15);
    a2.Stack();
    cout << a2.frontNumber() << endl;
    a2.Stack();
    a2.reverse();
    a2.Stack();
    return 0;
}