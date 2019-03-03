#include"sd_fun.h"
int length_of2(char * array){
    int i = 0;
    while (array[i] != '\0'){
        i++;
    }
    return i;
}

int main() {
    init();
    char a[] = "hello";
    check_equal( length_of2(a), 5);
    char y[100];
    y[0] = 0;
    append(y, "greetings");
    check_equal( length_of2(y), 9);

    quit();
}