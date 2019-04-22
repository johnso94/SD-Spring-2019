#include<iostream>
using namespace std;
#include<math.h>
#include"Circle.h"
#include"sd_fun.h"

Circle::Circle(istream &is) : Shape(is) {
  is >> radius;
}

Circle::Circle(istream &f, int _id, bool _is_button) {
  id = _id;
  is_button = _is_button;
  double width, height;
  read_react_info(f, position, color, width, height, draggable);
  radius = width/2;
  position.x += radius;
  position.y += radius;
}

void Circle::draw()
{
  if (is_button) append(yaml, "Button_C", id, ":\n");
  else append(yaml, "View_C", id, ":\n");
  append(yaml, "  style:\n");
  append(yaml, "    position: absolute\n");
  append(yaml, "    borderRadius: 50%\n");
  append(yaml, "    left: ", position.x - radius, "\n");
  append(yaml, "    top: ", position.y - radius, "\n");
  append(yaml, "    width: ", 2*radius, "\n");
  append(yaml, "    height: ", 2*radius, "\n");
  send_color();
  if (is_button) {
    append(yaml, "  on_touch:\n  ");
    send_color(50);
  } else if (draggable) {
    append(yaml, "  on_touch:\n");
    append(yaml, "    draggable: true\n");
  }
}
