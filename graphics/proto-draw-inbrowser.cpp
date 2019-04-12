#include<iostream>
#include"sd_fun.h"
#include"Rectangle.h"
#include"Circle.h"

int main() {
    init();
    yaml[0] = 0;

    Point2 pos1, pos2;
    pos1.x = 10;  pos1.y = 10;
    pos2.x = 100;  pos2.y = 100;
    Rectangle r(pos1, 50, 30);
    Circle c(pos2, 75);
    r.draw();
    c.draw();

    quit();
}