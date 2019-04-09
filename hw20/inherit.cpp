#include <iostream>
using namespace std;

class Player_Character{
  protected:
    int Intelligence, Strength, Constitution;
  public:
    void set_values (int a, int b, int c)
      { Intelligence=a; Strength=b; Constitution = c;}
 };

class Fighter: public Player_Character {
  public:
    int fighting_ability ()
      { return Strength + Constitution + Intelligence/5; }
 };

class Wizard: public Player_Character {
  public:
    int casting_ability ()
      { return 2*Intelligence + Constitution / 2; }
  };
  
int main () {
  Fighter Roy;
  Wizard Varsuvius;
  Roy.set_values (3,8,7);
  Varsuvius.set_values (6,3,4);
  cout << Roy.fighting_ability() << '\n';
  cout << Varsuvius.casting_ability() << '\n';
  return 0;
}