#include"sd_fun.h"
void write_at2(char * array, int b, char * array2){
    int r = 0;
    while (array[b] != '\0' && array[r] != '\0'){
        array[b] = array2[r];
        b++;
        r++;
    }
    array[b] = '\0';
}


int main() {
    init();
    char a[] = "hello";
    char b[] = "bye";
    write_at2(a, 1, b);
    check_equal(a, "hbye");

    char y[100];
    y[0] = 0;
    append(y, "greetings");
    write_at2(y, 3, b);
    check_equal(y, "grebye");
    quit();
}