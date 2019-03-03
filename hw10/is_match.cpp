#include"sd_fun.h"
bool is_match(char * array, int b, char * array2){
    bool r = true;
    for (int i = 0; i < length_of(array2); i++){
        if (array2[i] == array[i + b]){
            continue;
        }
        else{
            r = false;
            break;
        }
    }
    return r;
}


int main() {
    init();
    char a[] = "Wbyebye";
    char b[] = "bye";
    check_equal(is_match(a, 0, b), false);
    check_equal(is_match(a, 1, b), true);
    check_equal(is_match(a, 2, b), false);
    check_equal(is_match(a, 4, b), true);

    quit();
}