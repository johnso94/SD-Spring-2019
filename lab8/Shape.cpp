#include<iostream>
using namespace std;
#include<math.h>
#include"Shape.h"
#include"sd_fun.h"

int Shape::num_shapes_created = 0;

bool equal_str(const char *c0, const char *c1) {
  int len0 = length_of(c0), len1 = length_of(c1);
  if (len0 != len1) return false;
  for (int i = 0; i < len0; ++i) {
    if (c0[i] != c1[i]) return false;
  }
  return true;
}

void read_react_info(istream &f, Point2 &position, Color &color, double &width, double &height, bool &draggable)
{
  char style[50];
  f >> style;
  if (style[0] != 's') {
    cerr << "Warning:  unrecognized style " << style << endl;
    return;
  }
  f.ignore();  // skip newline
  while(f.peek() == ' ') {
    char attribute[50], value[50];
    f >> attribute >> value;
    f.ignore();  // skip newline
    // cout << "at " << attribute << ' ' << value << endl;
    if (equal_str(attribute, "left:")) position.x = as_double(value, 0);
    else if (equal_str(attribute, "top:")) position.y = as_double(value, 0);
    else if (equal_str(attribute, "position:")) {} // skip
    else if (equal_str(attribute, "borderRadius:")) {} // skip
    else if (equal_str(attribute, "width:")) width = as_double(value, 0);
    else if (equal_str(attribute, "height:")) height = as_double(value, 0);
    else if (equal_str(attribute, "backgroundColor:")) {
      // more complex, need to extract values from inside
      int pos = index_of(value, "(") + 1;
      color.r = as_integer(value, pos);
      pos = index_of(value, pos, ",") + 1;
      color.g = as_integer(value, pos);
      pos = index_of(value, pos, ",") + 1;
      color.b = as_integer(value, pos);
      // cout << " color: " << (int)color.r << ' ' << (int)color.g << ' ' << (int)color.b << endl;
    } else if (equal_str(attribute, "on_touch:")) {  // parse also!
      f.ignore();  // skip newline
      if (equal_str("backgroundColor:", value)) {
        f >> value;
        f.ignore();  // skip newline
      } else if (equal_str("draggable:", value)) {
        f >> value;
        f.ignore();  // skip newline
        draggable = true;
      }
    } else {
      cerr << "Warning:  unexpected attribute " << attribute << " value " << value << endl;
    }
  }
}

double distance(double x, double y, Point2 q)
{
  double dx = x - q.x;
  double dy = y - q.y;
  return sqrt(dx*dx + dy*dy);
}

Shape::Shape(istream &is)
{
  id = num_shapes_created++;
  int r, g, b;
  is >> r >> g >> b;
  color.r = r;
  color.g = g;
  color.b = b;

  is >> position.x >> position.y;
}

void Shape::display()
{
  color.display();
  cout << "   ";
  position.display();
}

void Shape::send_color(int extra)
{
  append(yaml, "    backgroundColor: ");
  append(yaml, "rgb(", color.r + extra);
  append(yaml, ",", color.g + extra);
  append(yaml, ",", color.b + extra, ")\n");
}
