#include"prelude"
 yaml[0]=0;
 int b[7] = {5,24,57,98,104,53,79};
 show_int_array(b,9);

 for(int i=0; i < 7; i++){
     b[i] += 3;
 }
 show_int_array(b,9);
#include"postlude"