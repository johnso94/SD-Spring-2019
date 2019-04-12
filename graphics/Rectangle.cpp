#include"Rectangle.h"
#include<iostream>
using namespace std;

void Rectangle::display(){
    cout << "Rectangle ";
    Shape::display();
    cout << "   " << width << ' ' << height << endl;
}
void Rectangle::draw()
{
    append(yaml, "View_", id, ":\n");
    append(yaml, "  style:\n");
    append(yaml, "    position: absolute\n");
    double x0 = min(position.x, position.x + width);
    double y0 = min(position.y, position.y + height);
    append(yaml, "    left: ", x0, "\n");
    append(yaml, "    top: ", y0, "\n");
    append(yaml, "    width: ", abs(width), "\n");
    append(yaml, "    height: ", abs(height), "\n");
    send_color();
}