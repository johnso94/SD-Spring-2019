#include<iostream>
#include"sd_fun.h"
#include"IntStack.h"

struct Pixel {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  Pixel(unsigned char r, unsigned char g, unsigned char b) :
    red(r), green(g), blue(b) {}
  //TODO: Add an = (assignment) operator that returns true if
  //      all three color values match between two pixels, and 
  //      false otherwise.
  bool operator =(Pixel r){
      if (red == r.red && blue == r.blue && green == r.green){
          return true;
      }
      else{
          return false;
      }
  }

};

const Pixel colors[] = { {140,81,10}, {216,179,101}, {246,232,195}, {199,234,229}, {90,180,172}, {1,102,94} };

// describe the text and the color grid
const char *text_at_top = R"(
Text_1:
  style:
    marginLeft: 30
    marginTop: 10
    fontSize: 30
    color: black
  pos: 1
  len: 18
)";

void make_grid(int offset, int grid_size) {
  append(yaml, R"(
ColorGrid_1:
  style:
    marginLeft: 30
    marginTop: 10
  extra_props:
    magnification: 20
)");
  append(yaml, "    width: ", grid_size, "\n");
  append(yaml, "    height: ", grid_size, "\n");
  append(yaml, "  pos: ", offset, "\n");
}

//TODO: Fix the order of lines in the following function
void append_pixel(Pixel p, int extra = 0) {
  append(yaml, "rgb(", p.red + extra);
  append(yaml, ", ", p.green + extra);
  append(yaml, ", ", p.blue + extra, ")\n");
}

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
  append_pixel(colors[i]);
  append(yaml, "    left: ", 10 + 60*i, "\n");
  append(yaml, R"(
  on_touch:
    backgroundColor: )");
  append_pixel(colors[i], 50);
}

void make_new_game_button()
{
  append(yaml, R"(
Button_New:
  style:
    position: absolute
    left: 50
    top: 375
    width: 130
    height: 35
    borderRadius: 10
    backgroundColor: rgb(150, 150, 150);
  on_touch:
    backgroundColor: rgb(200, 200, 200);
  children: [Text_2]
Text_2:
  style:
    marginLeft: 5
    fontSize: 25
    color: black
  pos: 25
  len: 18
)");
  write_at(mem, 25, "new game");
}

//TODO: Complete this function to set the values in mem for a 
//      particular pixel (using offset and pos to get to the 
//      correct location in mem), using the individual color 
//      values from the argument color.
void set_pixel_color(int offset, int pos, Pixel color) {
    write_at(mem, 3* pos + offset + 0, color.red)
    write_at(mem, 3* pos + offset + 1, color.green)
    write_at(mem, 3* pos + offset + 2, color.blue)
}

void build_random_board(int offset, int grid_size, int num_colors = 6) {
  for (int j = 0; j < grid_size; ++j)
  for (int i = 0; i < grid_size; ++i) {
    int index = num_colors * random_number();
    set_pixel_color(offset, grid_size*j + i, colors[index]);
  }
}

Pixel color_at_position(int offset, int pos) {
  return Pixel(mem[offset + 3*pos + 0], 
               mem[offset + 3*pos + 1], 
               mem[offset + 3*pos + 2]);
}

bool board_is_one_color(int offset, int grid_size) {
  Pixel col(mem[offset + 0], mem[offset + 1], mem[offset + 2]);
  for (int j = 0; j < grid_size; ++j)
  for (int i = 0; i < grid_size; ++i) {
    if (!(col == color_at_position(offset, j*grid_size + i))) {
      return false;
    }
  }
  return true;
}

void check_neighbor(int offset, int grid_size, int npos, IntStack &stack, Pixel target_color, Pixel replacement_color) {
  if (target_color == color_at_position(offset, npos)) {
    set_pixel_color(offset, npos, replacement_color);
    stack.push(npos);
  }
}

void update_board(int offset, int grid_size, int button) {
  Pixel target_color(mem[offset + 0], mem[offset + 1], mem[offset + 2]);
  Pixel replacement_color = colors[button];
  if (target_color == replacement_color) return;
  IntStack stack(grid_size * grid_size);
  stack.push(0);  // initial pixel location
  set_pixel_color(offset, 0, replacement_color);
  while(!stack.empty()) {
    int pos = stack.top();
    stack.pop();
    // check left
    if (pos % grid_size > 0) check_neighbor(offset, grid_size, pos - 1, stack, target_color, replacement_color);
    // check right
    if (pos % grid_size < 14) check_neighbor(offset, grid_size, pos + 1, stack, target_color, replacement_color);
    // check above
    if (pos / grid_size > 0) check_neighbor(offset, grid_size, pos - grid_size, stack, target_color, replacement_color);
    // check below
    if (pos / grid_size < 14) check_neighbor(offset, grid_size, pos + grid_size, stack, target_color, replacement_color);
  }
}

void show_num_moves(int n, int max_moves) {
  int pos = 12;
  write_at(mem, pos, n);
  if (n > 9) pos += 2;
  else pos += 1;
  write_at(mem, pos, "/");
  ++pos;
  write_at(mem, pos, max_moves);
  if (max_moves > 9) pos += 2;
  else pos += 1;
  write_at(mem, pos, " moves.");
}

void handle_button(int grid_size, int board_offset, int num_moves, int max_moves, int button) {
  update_board(board_offset, grid_size, button);
  bool hide_buttons = false;
  if (board_is_one_color(board_offset, grid_size)) { // finished!
    write_at(mem, 1, "You won in ");
    hide_buttons = true;
  } else if (num_moves >= max_moves) {
    hide_buttons = true;
  }
  show_num_moves(num_moves, max_moves);
  if (hide_buttons) { // show the text and board, but not the buttons
    yaml[0] = 0;
    append(yaml, text_at_top);
    make_grid(board_offset, grid_size);
    make_new_game_button();
  }
}

int main() {
  init();

  const int grid_size = 15;
  const int board_offset = 40, max_moves = 25, num_board_colors = 4;
      
  if (length_of(yaml) < 30 || was_pressed(yaml, "Button_New")) {
    // create the whole setup
    write_at(mem, 1, "           ");
    show_num_moves(0, max_moves);

    yaml[0] = 0;
    append(yaml, text_at_top);
    make_grid(board_offset, grid_size);
    for (int i = 0; i < 6; ++i) 
      make_button(i);
    build_random_board(board_offset, grid_size, num_board_colors);
  } else {
    // find out the old number of moves
    int num_moves = as_integer(mem, 12);
    ++num_moves;

    // check if a button was pressed
    for (int i = 0; i < 6; ++i) {
      if (was_pressed(yaml, "Button_", i)) {
        handle_button(grid_size, board_offset, num_moves, max_moves, i);
      }
    }
  }

  quit();
}
