#include <iostream>
using namespace std;

class goblins{
  public:
    static int pop;
    goblins () { pop++; };
};

int goblins::pop=0;

int main () {
  goblins a;
  goblins b[10];
  cout << a.pop << '\n';
  goblins d[20];
  goblins * c = new goblins;
  cout << goblins::pop << '\n';
  delete c;
  return 0;
}