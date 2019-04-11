#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include"Shape.h"
#include<iostream>
using namespace std;

class Circle: public Shape {
    int radius;
    public:
    Circle(){
        radius = 50;
    }
    Circle(Point2 p, int r) : Shape(p) {
        radius = r;
    }
    Circle(istream & is) : Shape(is) {
        is >> radius;
    }
    void display();
};

#endif