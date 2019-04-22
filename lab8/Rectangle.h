#ifndef _RECTANGLE_
#define _RECTANGLE_

#include "Shape.h"

class Rectangle :  public Shape {
protected:
  double width, height;

public:
  Rectangle() { width = height = 100; }
  Rectangle(Point2 p, double w, double h) {
                         position.x = p.x; position.y = p.y;
                         width = w; height = h; }
  Rectangle(istream &is);
  Rectangle(istream &is, int _id, bool _is_button = false);

  virtual void draw();
  virtual void display() { cout << "Rectangle "; Shape::display();
                           cout << "   " << width << " " << height; }
};
  
#endif // _RECTANGLE_
