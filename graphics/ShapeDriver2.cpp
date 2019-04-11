#include<iostream>
using namespace std;
#include "Rectangle.h"
#include "Circle.h"
#include <fstream>


int main(){
    ifstream g("shapes.txt");
    int numShapes;
    g >> numShapes;
    Shape * ShapeArray[numShapes];
    char n[64];
    for (int i = 0; i < numShapes; i++){
        g >> n;
        if(n[0] == 'R'){
            ShapeArray[i] = new Rectangle(g);
        }

        else if(n[0] == 'C'){
            ShapeArray[i] = new Circle(g);
        }
    }
    for (int i = 0; i < numShapes; i++){
        ShapeArray[i] -> display();
        delete ShapeArray[i];
    }
}