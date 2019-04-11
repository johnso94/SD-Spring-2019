#include<iostream>
using namespace std;
#include "Shape.h"

int main(){
    Point2 pos;
    pos.x = 10;
    pos.y = 20;
    Color col = {128, 0, 128};
    Shape a;
    Shape b(pos);
    Shape c(cin);
    Point2 t = c.getPosition();
    Color h =  c.getColor();
    cout << endl;
    cout << t.y << endl;
    cout << h.r << endl;
    c.display();
    cout << endl;
    c.setColor(col);
    c.setPosition(30, 40);
    c.display();
    cout << endl;
}