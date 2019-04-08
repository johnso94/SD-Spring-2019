#include<iostream>
using namespace std;
#include "IntStack.h"

int main(){
    IntStack test(3);
    test.pop();
    cout << "size: " << test.getSize() << " pos: " << test.getPos() << endl;
    test.push(3);
    cout << test.top() << endl;
    test.push(5);
    cout << test.top() << endl;
    test.push(7);
    cout << test.top() << endl;
    test.push(9);
    cout << test.top() << endl;
    test.reverse();
    cout << test.top() << endl;
    test.pop();
    cout << test.top() << endl;
}