#include <iostream>
using namespace std;

class fighter {
  protected:
    int strength, dex;
  public:
    void set_values (int a, int b)
      { strength=a; strength=b; }
    virtual int ability ()
      { return strength * dex; }

};

class knight: public fighter {
  public:
    int ability ()
      { return (2 * strength); }
};

class archer: public fighter {
  public:
    int ability ()
      { return 2* dex; }
};
