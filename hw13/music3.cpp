 #include<iostream>
 using namespace std;

 struct Instrument {
     char *type;
     char *player;
     Instrument *sounds_good_with;
 };


 void swapper(Instrument **arr)
 {
     Instrument *tmp;
     tmp = arr[0];
     arr[0] = arr[3];
     arr[3] = tmp;
 }

 int main()
 {
     Instrument guitar, drum;
     Instrument piano, organ;

     Instrument *band[4];

     guitar.type = "string"; guitar.player = "Jimmy Hendrix";
     drum.type = "percussion"; drum.player = "John Bonham";
     piano.type = "keyboard"; guitar.player = "Chopin";
     drum.type = "organ"; drum.player = "Jimmy Smith";
     
     guitar.sounds_good_with = &drum; drum.sounds_good_with = &guitar;
     piano.sounds_good_with = &organ; organ.sounds_good_with = &piano;

     band[0] = &guitar;  band[1] = &drum;
     band[2] = &piano; band[3] = &organ;

     swapper(band);

     cout << "guess what? " << band[0]->sounds_good_with -> type << endl;
 }
