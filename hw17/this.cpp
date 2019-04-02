#include <iostream>
using namespace std;

class mime {
  public:
    bool mirror (mime& param);
};

bool mime::mirror(mime& param)
{
  if (&param == this) return true;
  else return false;
}

int main () {
  mime a;
  mime* b = &a;
  if ( b->mirror(a) )
    cout << "that is me in the mirror\n";
  return 0;
}