#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include <math.h>
#include <stdlib.h>

#include "Circle.h"
#include "Rectangle.h"
#include "sd_fun.h"

enum ToolType
{
  SELECT,
  CIRCLE,
  RECTANGLE
} currentTool;
Shape *currentToolButton = 0;
Color currentColor(0, 200, 200);
const int numToolButtons = 3;
Shape **toolButtonForeground, **toolButtonBackground;
int num_shapes = 0;
Shape *all_shapes[10000];
const int numColorButtons = 9;
Shape **colorButtonForeground, **colorButtonBackground;
Shape *currentColorButton = 0, *currentColorButtonBG;
void handleColorButtonPress(int i)
{
  // cerr << "handleColorButtonPress i " << i << endl;
  if (currentColorButtonBG)
    currentColorButtonBG->setColor(Color(128, 128, 128));
  currentColorButton = all_shapes[2 * i + 1];
  currentColorButtonBG = all_shapes[2 * i];
  currentColorButtonBG->setColor(Color(255, 255, 0));
}
void loadColorButtons()
{
  char fname[] = "colorButtons.txt";
  ifstream g(fname);
  if (!g.good())
  {
    cerr << "Warning: Unable to open " << fname << ",exiting." << endl;
    return;
  }
  int tmp;
  g >> tmp;
  tmp /= 2;
  // assert(tmp == numColorButtons);
  colorButtonForeground = new Shape *[numColorButtons];
  colorButtonBackground = new Shape *[numColorButtons];
  string header;
  for (int i = 0; i < numColorButtons; ++i)
  {
    g >> header;
    colorButtonBackground[i] = new Rectangle(g);
    colorButtonBackground[i]->is_button = true;
    g >> header;
    colorButtonForeground[i] = new Rectangle(g);
    // cout << "colorButtonForeground[" << i << "] is ";
    // colorButtonForeground[i]->display();
  }
  colorButtonBackground[0]->setColor(Color(255, 255, 0));
  g.close();
  // cerr << "Loaded " << numColorButtons << " color button descriptions." << endl;
}
void draw_all_shapes()
{
  yaml[0] = 0;
  for (int i = 0; i < num_shapes; ++i)
    all_shapes[i]->draw();
}
void loadToolButtons()
{
  char fname[] = "toolButtons.txt";
  ifstream g(fname);
  if (!g.good())
  {
    cerr << "Warning: Unable to open " << fname << ",exiting." << endl;
    return;
  }
  int tmp;
  g >> tmp;
  tmp /= 2;
  // assert(tmp == numToolButtons);
  toolButtonForeground = new Shape *[numToolButtons];
  toolButtonBackground = new Shape *[numToolButtons];
  char header[64];
  for (int i = 0; i < numToolButtons; ++i)
  {
    g >> header;
    toolButtonBackground[i] = new Rectangle(g);
    toolButtonBackground[i]->is_button = true;
    g >> header;
    if (header[0] == 'R')
    {
      toolButtonForeground[i] = new Rectangle(g);
    }
    else
    {
      toolButtonForeground[i] = new Circle(g);
    }
    // cout << "toolButtonForeground[" << i << "] is ";
    // toolButtonForeground[i]->display();
  }
  toolButtonBackground[1]->setColor(Color(255, 255, 0));
  g.close();
  // cerr << "Loaded " << numToolButtons << " tool button descriptions." << endl;
}
void draw_buttons()
{
  yaml[0] = 0;
  for (int i = 0; i < numColorButtons; ++i)
  {
    colorButtonBackground[i]->draw();
    colorButtonForeground[i]->draw();
    // cout << "drawing "; colorButtonForeground[i]->display(); cout << endl;
  }
  // draw the tool buttons
  for (int i = 0; i < numToolButtons; ++i)
  {

    toolButtonBackground[i]->draw();
    toolButtonForeground[i]->draw();
    // cout << "drawing "; toolButtonForeground[i]->display();cout << endl;
  }
}
void handleToolButtonPress(int i)
{
  // show which button was pressed
  if (currentToolButton)
    currentToolButton->setColor(Color(128, 128, 128));
  currentToolButton = all_shapes[2 * i];
  // currentToolButton->setColor( Color(150,150,150) );
  currentToolButton->setColor(Color(255, 255, 0));
  // cerr << "tool " << (i - numColorButtons) << endl;
  // change the current mode
  switch (i - numColorButtons)
  {
  case 0:
    currentTool = SELECT;
    break;
  case 1:
    currentTool = RECTANGLE;
    break;
  case 2:
    currentTool = CIRCLE;
    break;
  }
}
void read_shapes_from_yaml()
{
  int currentColorButtonIndex = -1;
  istringstream f(yaml);
  char keyword[50], value[50];
  int num_r = 0, num_c = 0;
  while (f >> keyword)
  {
    if (equal_str("event_handling:", keyword))
    { // skip
      f.ignore();
      continue;
    }
    else if (equal_str("show_drag_segment:", keyword) ||
             equal_str("first_name:", keyword))
    { // skip
      f >> value;
      f.ignore();
      continue;
    }
    else if (equal_str("event_info:", keyword))
    { // skip
      f.ignore();
      while (' ' == f.peek())
      {
        string line;
        getline(f, line);
      }
      continue;
    }
    else if (equal_str("nodes:", keyword))
    { // skip
      string line;
      getline(f, line);
      continue;
    }
    else if (' ' == keyword[0])
    { // skipcontinue;
    }
    else if (keyword[0] != 'V' && keyword[0] != 'B')
    {
      cerr << "Warning: expected View_ or Button_, got keyword" << keyword << endl;
      continue;
    }
    bool is_button = ('B' == keyword[0]);
    int tpos = is_button ? 7 : 5;
    int id = as_integer(keyword, tpos + 1);
    if ('R' == keyword[tpos])
    {
      all_shapes[num_shapes++] = new Rectangle(f, id, is_button);
      ++num_r;
      if (255 == all_shapes[num_shapes - 1]->getColor().r)
      {
        if (num_shapes <= 2 * numColorButtons)
        {
          currentColorButtonIndex = num_shapes;
        }
        else if (num_shapes <= 2 * (numColorButtons + numToolButtons))
        {
          currentToolButton = all_shapes[num_shapes - 1];
          switch (num_shapes / 2 - numColorButtons)
          {
          case 0:
            currentTool = SELECT;
            break;
          case 1:
            currentTool = RECTANGLE;
            break;
          case 2:
            currentTool = CIRCLE;
            break;
          }
          if (-1 != currentColorButtonIndex)
          {
            currentColorButton = all_shapes[currentColorButtonIndex];
            currentColorButtonBG = all_shapes[currentColorButtonIndex - 1];
          }
          if (currentColorButton)
            currentColor = currentColorButton->getColor();
        }
      }
    }
    else if ('C' == keyword[tpos])
    {
      all_shapes[num_shapes++] = new Circle(f, id, is_button);
      ++num_c;
    }
    else
    {
      cerr << "Warning: expected View_C or View_R, got keyword" << keyword << endl;
      continue;
    }
  }
  // cerr << "num_r " << num_r << " num_c " << num_c << endl;
}
int main()
{
  init();

  read_shapes_from_yaml();

  if (length_of(yaml) < 30)
  {
    loadColorButtons();
    loadToolButtons();
    // draw the color buttons
    draw_buttons();
    // initialize
  }
  else
  {
    //cerr << "testing where this goes" << endl;
    bool button_pressed = false;

    for (int i = 0; i < numColorButtons + numToolButtons; ++i)
    {
      if (was_pressed(yaml, "Button_R", 2 * i))
      {
        cerr << " pressed button i " << i << endl;
        // button_pressed = true;
        if (i < numColorButtons)
        {
          handleColorButtonPress(i);
        }
        else
        {
          handleToolButtonPress(i);
        }
      }
    }
    if (!button_pressed)
    {
      int x0, y0, x, y;
      x = touch_pos_x(yaml);
      y = touch_pos_y(yaml);
      x0 = touch_start_pos_x(yaml);
      y0 = touch_start_pos_y(yaml);
      if (SELECT == currentTool)
      {
        // cerr << "drag shape." << endl;
      }
      else
      {
        Point2 start(x0, y0);
        if (RECTANGLE == currentTool) // build a new rectangle!
          all_shapes[num_shapes] = new Rectangle(start, x - x0, y - y0);
        else if (CIRCLE == currentTool)
        {
          double radius = distance(x, y, start);
          all_shapes[num_shapes] = new Circle(start, radius);
        }
        all_shapes[num_shapes]->setColor(currentColor);
        all_shapes[num_shapes]->draggable = true;
        ++num_shapes;
      }
    }
    draw_all_shapes();
  }

  // show a segment as the user does a drag motion
  if (SELECT != currentTool)
  {
    append(yaml, R"(
event_handling:
  show_drag_segment: true
)");
  }

  quit();
}
