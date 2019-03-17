#include <iostream>
using namespace std;

class fighter {
    int strength, dexterity;
  public:
    fighter ();
    fighter (int);
    int ability (void) {return (strength + dexterity);}
};
fighter::fighter (int a){
    strength = a;
    dexterity = 3;
}
fighter::fighter(){
    strength = 5;
    dexterity = 5;
}
int main(){
    fighter archer;
    fighter warrior(10);
    return 0;
}