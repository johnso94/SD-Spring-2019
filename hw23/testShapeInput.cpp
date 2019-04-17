#include<iostream>
using namespace std;
#include "Rectangle.h"
#include "Circle.h"
#include <fstream>

int main(){
    initialize_empty(mem,yaml);

    ifstream g("input.txt");
    char keyword[50];
    g >> keyword;
// for making a rectangle
    Rectangle r1(g, 5);
    r1.display();
    int n = 0;
    while(keyword[n]!='\0'){
        cout << keyword[n];
        n++;
    }
// for making a circle
    Circle c1(g, 6);
    c1.display();

//Formatting note, ignore in code: END while loop definition

//making the shapes
    // cout << endl;
    // Point2 pos = {40,35};
    // Color col = {128, 0, 128};
    // Rectangle r2(pos, 60, 70);
    // Rectangle r3;
    // cout << endl;
    // r3.setColor(col);
    // r3.setPosition(30, 40);
    // Circle c1;
    // c1.setColor(col);
    // c1.setPosition(30, 40);
    // c1.draw();
    // r3.draw();

    // int i = 1;
    // r3.draw();
    // c1.draw();
    // while(yaml[i]!='\0'){
    //     cout << yaml[i];
    //     i++;
    // }
    cout << yaml << endl;
}