#include<iostream>
using namespace std;
#include "Circle.h"

int main(){
    Point2 pos = {40,35};
    Color col = {128, 0, 128};
    Circle c1;
    Circle c2(pos, 60);
    Circle c3(cin);
    Point2 t = c3.getPosition();
    Color h =  c3.getColor();
    cout << endl;
    cout << t.y << endl;
    cout << h.r << endl;
    c3.display();
    c3.setColor(col);
    c3.setPosition(30, 40);
    c3.display();
}
