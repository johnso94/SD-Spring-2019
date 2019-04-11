#include<iostream>
using namespace std;
#include"Shape.h"

Color Shape::getColor(){
    return color;
}
Point2 Shape::getPosition(){
    return position;
}
void Shape::setColor(Color c){
    color = c;
}
void Shape::setPosition(int a, int b){
    position.x = a;
    position.y = b;
}
void Shape::display(){
    cout << color.r  << " ";
    cout << color.g  << " ";
    cout << color.b  << "   ";
    cout << position.x  << " ";
    cout << position.y  << " ";
}