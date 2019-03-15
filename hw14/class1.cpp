// example: one class, two objects
#include <iostream>
using namespace std;

class Triangle {
    int width, height;
  public:
    void set_values (int,int);
    int area () {return width*height/2;}
};

void Triangle::set_values (int x, int y) {
  width = x;
  height = y;
}

int main () {
  Triangle tri, trib;
  rect.set_values (3,4);
  rectb.set_values (5,6);
  cout << "tri area: " << tri.area() << endl;
  cout << "trib area: " << trib.area() << endl;
  return 0;
}