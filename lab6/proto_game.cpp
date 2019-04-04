#include<iostream>
#include"sd_fun.h"

// make a Pixel struct
struct Pixel {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
};

// choose some rgb colors
const Pixel colors[] = { {200, 0, 0}, {130, 70, 0}, {100, 130, 0}, {0, 200, 0}, {0, 130, 130}, {0, 0, 200}, {100, 0, 100} };

// describe the text and the color grid
const char *text_and_grid = R"(
Text_1:
  style:
    marginLeft: 30
    marginTop: 10
    fontSize: 30
    color: black
  pos: 1
  len: 18
ColorGrid_1:
  style:
    marginLeft: 30
    marginTop: 10
  extra_props:
    width: 15
    height: 15
    magnification: 20
  pos: 30
)";

void make_button(int i)
{
  append(yaml, "Button_", i, ":\n");
  append(yaml, R"(
  style:
    position: absolute
    top: 370
    width: 50
    height: 50
    borderRadius: 25
    backgroundColor: )");
  append(yaml, "rgb(", colors[i].red);
  append(yaml, ", ", colors[i].green);
  append(yaml, ", ", colors[i].blue, ")\n");
  append(yaml, "    left: ", 10 + 60*i, "\n");
  append(yaml, R"(
  on_touch:
    backgroundColor: )");
  append(yaml, "rgb(", colors[i].red + 50);
  append(yaml, ", ", colors[i].green + 50);
  append(yaml, ", ", colors[i].blue + 50, ")\n");
}

void build_board(int offset, int button = -1) {
  // initialize pixels to dark grey
  for (int j = 0; j < 15; ++j)
  for (int i = 0; i < 15; ++i) {
    mem[offset + 3*(15*j + i) + 0] = 25;
    mem[offset + 3*(15*j + i) + 1] = 25;
    mem[offset + 3*(15*j + i) + 2] = 25;
  }
  if (-1 != button && 1!=button && 2 != button) {
    // change one pixel
    int index = button;
    mem[offset + 3*button + 0] = colors[index].red;
    mem[offset + 3*button + 1] = colors[index].green;
    mem[offset + 3*button + 2] = colors[index].blue;
  }
  if (1 == button){
    for(int i=0; i< 7; i++){
      int index = i;
      mem[offset + 3*i + 0] = colors[index].red;
      mem[offset + 3*i + 1] = colors[index].green;
      mem[offset + 3*i + 2] = colors[index].blue;
    }
  }
  if (2 == button){
    for(int i=6; i>-1; i--){
      int index = 6-i;
      mem[offset + 3*i + 0] = colors[index].red;
      mem[offset + 3*i + 1] = colors[index].green;
      mem[offset + 3*i + 2] = colors[index].blue;
    }
  }
}

int main() {
  init();

  int button = -1;  // -1 indicates nothing pressed
  if (length_of(yaml) < 30) {  // create the whole setup
    write_at(mem, 1, "Ready.");
    yaml[0] = 0;
    append(yaml, text_and_grid);
    for (int i = 0; i < 7; ++i) 
      make_button(i);
  } else {
    // check if a button was pressed
    for (int i = 0; i < 7; ++i) {
      if (was_pressed(yaml, "Button_", i)) {
        button = i;
      }
    }

    // remove old event info
    int pos = index_of(yaml, "event_info:");
    if (-1 != pos) yaml[pos] = 0;

    // handle button
    if (-1 != button) {
      write_at(mem, 1, "You chose option ");
      write_at(mem, 18, button);
    }
  }
  build_board(30, button);

  quit();
}
