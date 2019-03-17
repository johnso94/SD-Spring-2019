#include <iostream>
using namespace std;

class fighter {
    int strength, dexterity;
    public:
    fighter ();
    fighter (int);
    int ability () {return (strength + dexterity);}
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
    fighter grunt = 2;
    fighter samurai = {7};
    fighter champion {15};
    cout << champion.ability();
    return 0;
}