#include"sd_fun.h"
int convert_to_celsius(int a) {
    int result;
    if (a > 0){
        result = a;
    }
    else{
        result = -a;
    }
    return result;
    }
int main() {
init();
check_equal( convert_to_celsius(5), 5 );
check_equal( convert_to_celsius(-3), 3 );
check_equal( convert_to_celsius(1), 1 );
quit();
}