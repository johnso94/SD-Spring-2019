#include<iostream>
using namespace std;
#include "DVDArray.h"


int main() {
    char str[] = "Gandhi";
    DVD d1(4, str, "Richard Attenborough");
    DVD d2;
    DVD d3(d1);

    str[0] = 'X';

    cout << d2.getId() << endl; // 0
    cout << d1.getTitle() << endl; // Gandhi
    cout << d1.getDirector() << endl; // Richard Attenborough

    d1.setId(2);
    d1.setTitle("Shadowlands");
    d2.setDirector("Ingmar Bergman");

    d3 = d2;
    d2.setTitle("Wild Strawberries");

    DVDArray a1(2);
    DVDArray a2;
    a2.getSize();
    a1[0] = d1;
    a1[1] = d3;
    DVDArray a3(a1);
    a2 = a1;
    a2.getSize();
    a1.display();

}