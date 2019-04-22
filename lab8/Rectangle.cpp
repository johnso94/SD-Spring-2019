#include<iostream>
using namespace std;
#include<math.h>
#include"Rectangle.h"
#include"sd_fun.h"

Rectangle::Rectangle(istream &is) : Shape(is) {
  is >> width >> height;
}

Rectangle::Rectangle(istream &f, int _id, bool _is_button) {
  id = _id;
  is_button = _is_button;
  read_react_info(f, position, color, width, height, draggable);
}

void Rectangle::draw()
{
  if (is_button) append(yaml, "Button_R", id, ":\n");
  else append(yaml, "View_R", id, ":\n");
  append(yaml, "  style:\n");
  append(yaml, "    position: absolute\n");
  double x0 = min(position.x, position.x + width);
  double y0 = min(position.y, position.y + height);
  append(yaml, "    left: ", x0, "\n");
  append(yaml, "    top: ", y0, "\n");
  append(yaml, "    width: ", fabs(width), "\n");
  append(yaml, "    height: ", fabs(height), "\n");
  send_color();
  if (is_button) {
    append(yaml, "  on_touch:\n  ");
    send_color(50);
  } else if (draggable) {
    append(yaml, "  on_touch:\n");
    append(yaml, "    draggable: true\n");
  }
}
