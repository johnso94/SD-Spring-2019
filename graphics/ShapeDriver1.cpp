#include<iostream>
using namespace std;
#include "Rectangle.h"
#include "Circle.h"


int main(){
    Point2 pos = {40,35};
    Color col = {128, 0, 128};
    Rectangle r2(pos, 60, 70);
    Rectangle r3;
    cout << endl;
    r2.display();
    r3.setColor(col);
    r3.setPosition(30, 40);
    r3.display();
    Circle c1;
    Circle c3(cin);
    cout << endl;
    c3.display();
    c1.setColor(col);
    c1.setPosition(30, 40);
    c1.display();
}