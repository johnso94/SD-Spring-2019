#include"Rectangle.h"
#include<iostream>
using namespace std;

void Rectangle::display(){
    cout << "Rectangle ";
    Shape::display();
    cout << "   " << width << ' ' << height << endl;
}