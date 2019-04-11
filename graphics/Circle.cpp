#include"Circle.h"
#include<iostream>
using namespace std;

void Circle::display(){
    cout << "Circle ";
    Shape::display();
    cout << "   " << radius << endl;
}