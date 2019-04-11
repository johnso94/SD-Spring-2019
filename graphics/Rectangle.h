#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include"Shape.h"
#include<iostream>
using namespace std;

class Rectangle: public Shape {
    int width;
    int height;
    public:
    Rectangle(){
        width = 50;
        height = 30;
    }
    Rectangle(Point2 p, int w, int h) : Shape(p) {
        width = w;
        height = h;
    }
    Rectangle(istream & is) : Shape(is) {
        is >> width;
        is >> height;
    }
    void display();
};

#endif