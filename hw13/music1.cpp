 #include<iostream>
 using namespace std;

 struct Measurement {
     char *type;
     char *player;
 };

 struct Instrument {
     Measurement m;
     Instrument *sounds_good_with;
 };

 int main() {
     Instrument guitar, drum;

     guitar.m.type = "string";
     guitar.m.player = "Jimmy Hendrix";
     drum.m.type = "percussion";
     drum.m.player = "John Bonham";

     guitar.sounds_good_with = &drum;
     drum.sounds_good_with = &guitar;

     cout << "The guitar sounds good with ";
     cout << (*(guitar.sounds_good_with)).m.type << endl;
 }