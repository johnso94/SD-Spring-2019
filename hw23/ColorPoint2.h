#ifndef _COLORPOINT2_H_
#define _COLORPOINT2_H_


#include <iostream>
using namespace std;

struct Color{
    int r;
    int g;
    int b;
    void display(){
        cout << "red " << r << ", green " << g << ", blue "<< b <<endl;
    }
};

struct Point2{
    int x;
    int y;
    void display(){
        cout << "(x,y) = " << '(' << x << ',' << y << ')' <<endl;
    }
};

#endif