#ifndef _CIRCLE_
#define _CIRCLE_

#include "Shape.h"

class Circle :  public Shape {
protected:
  double radius;

public:
  Circle() { radius = 50; }
  Circle(Point2 p, double r) { position.x = p.x; position.y = p.y;
                              radius = r; }
  Circle(istream &is);
  Circle(istream &is, int, bool is_button=false);

  virtual void draw();
  virtual void display() { cout << "Circle    "; Shape::display();
                           cout << "   " << radius; }
};
  
#endif // _CIRCLE_
