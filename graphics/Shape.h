#ifndef _SHAPE_H_
#define _SHAPE_H_

#include"ColorPoint2.h"
#include<iostream>
#include"sd_fun.h"

using namespace std;

class Shape{
    Color color;
    Point2 position;
    public:
    Shape(){
        color.r = 128;
        color.g = 0;
        color.b = 128;
        position.x = 100;
        position.y = 200;
    }
    Shape(Point2 p){
        color.r = 256;
        color.g = 0;
        color.b = 0;
        position = p;
    }
    Shape(istream & is){
        is >> color.r;
        is >> color.g;
        is >> color.b;
        is >> position.x;
        is >> position.y;
    }
    Color getColor();
    Point2 getPosition();
    void setColor(Color c);
    void setPosition(int x, int y);
    void send_color();
    void display();
};


#endif