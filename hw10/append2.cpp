#include"sd_fun.h"
void append2(char * array, char * array2){
    int i = 0;
    int q = length_of(array);
    while (array2[i] != '\0'){
        array[q] = array2[i];
        i++;
        q++;
    }
    array[q] = '\0';
}


int main() {
    init();
    char a[15];
    a[0] = 'W';
    a[1] = 0;
    check_equal( a, "W");
    char b[] = "bye";
    append2(a, b);
    check_equal( a, "Wbye");
    append2(a, b);
    check_equal( a, "Wbyebye");

    char y[100];
    y[0] = 0;
    append2(y, "greetings");
    append2(y, a);
    check_equal( y, "greetingsWbyebye" );
    quit();
}