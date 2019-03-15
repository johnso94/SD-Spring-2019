// example: class constructor
#include <iostream>
using namespace std;

class Triangle {
    int width, height;
  public:
    Triangle (int,int);
    int area () {return (width*height/2);}
};

Triangle::Triangle (int a, int b) {
  width = a;
  height = b;
}

int main () {
  Triangle tri (3,4);
  Triangle trib (5,6);
  cout << "tri area: " << tri.area() << endl;
  cout << "trib area: " << trib.area() << endl;
  return 0;
}