#include<iostream>
using namespace std;
#include "Rectangle.h"

int main(){
    Point2 pos = {40,35};
    Color col = {128, 0, 128};
    Rectangle r1;
    Rectangle r2(pos, 60, 70);
    Rectangle r3(cin);
    Point2 t = r3.getPosition();
    Color h =  r3.getColor();
    cout << endl;
    cout << t.y << endl;
    cout << h.r << endl;
    r3.display();
    r3.setColor(col);
    r3.setPosition(30, 40);
    r3.display();
}
