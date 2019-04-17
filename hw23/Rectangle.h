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
    Rectangle(istream &f, int _id) {
        id = _id;
        char style[50];
        f >> style;
        if (!equal_str(style, "style:")) {
            cerr << "Warning:  unrecognized style " << style << endl;
            return;
        }
        f.ignore();  // skip newline
        cout << "correctly read in the style!" << endl;
            //Formatting note, ignore in code: START while loop definition
        while(f.peek() == ' ') {
            char attribute[50], value[50];
            f >> attribute >> value;
            f.ignore();  // skip newline
            // cout << "at " << attribute << ' ' << value << endl;
            if (equal_str(attribute, "left:")) position.x = as_double(value, 0);
            if (equal_str(attribute, "top:")) position.y = as_double(value, 0);
            if (equal_str(attribute, "width:")) width = as_double(value, 0);
            if (equal_str(attribute, "height:")) height = as_double(value, 0);
            else if (equal_str(attribute, "position:")) {} // skip
            else if (equal_str(attribute, "backgroundColor:")) {
                // more complex, need to extract values from inside
                int pos = index_of(value, "(") + 1;
                color.r = as_integer(value, pos);
                pos = index_of(value, pos, ",") + 1;
                color.g = as_integer(value, pos);
                pos = index_of(value, pos, ",") + 1;
                color.b = as_integer(value, pos);
                } else {
                cerr << "Warning:  unexpected attribute " << attribute << " value " << value << endl;
            }
        }
    }
    void display();
    void draw();
};



#endif