#ifndef _SHAPE_
#define _SHAPE_

#include<iostream>
using namespace std;

struct Color {
  unsigned char r, g, b;
  Color() { r = g = b = 128; }
  Color(int _r, int _g, int _b) { r = _r; g = _g; b = _b; }
  void display() { cout << (int)r << " " << (int)g << " " << (int)b; }
};

struct Point2 {
  double x, y;
  Point2() { x = y = 0; }
  Point2(double _x, double _y) : x(_x), y(_y) {}
  void display() { cout << x << " " << y; }
};
double distance(double, double, Point2);

class Shape {
  static int num_shapes_created;
protected:
  int id;
  Color color;
  Point2 position;

public:
  bool is_button, draggable = false;
  Shape() { id = num_shapes_created++;
            color.r = color.g = color.b = 128;
            position.x = position.y = 0; }
  Shape(istream &is);

  Point2 getPosition() { return position; }
  void setPosition(double x, double y) { position.x = x; position.y = y; }
  Color getColor() { return color; }
  void setColor(Color newcol) { color = newcol; }
  void send_color(int extra=0);

  virtual void draw() = 0;
  virtual void display();
};

bool equal_str(const char *c0, const char *c1);
void read_react_info(istream &f, Point2 &position, Color &color, double &width, double &height, bool &draggable);
  
#endif // _SHAPE_
