#ifndef _SHAPE_H_
#define _SHAPE_H_

#include"ColorPoint2.h"
#include<iostream>
#include"sd_fun.h"

using namespace std;



class Shape{
    protected:
    Color color;
    Point2 position;
    public:
    int id;
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

    bool equal_str(const char *c0, const char *c1) {
        int len0 = length_of(c0), len1 = length_of(c1);
        if (len0 != len1) return false;
        for (int i = 0; i < len0; ++i) {
            if (c0[i] != c1[i]) return false;
        }
        return true;
    }
};


#endif