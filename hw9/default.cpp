#include"sd_fun.h"
int cool_function(int a, int b = 0, int c = 0) {
    int result = a;
    if (b > 0 || b < 0){
        result *= b;
    }
    if (c > 0 || c < 0){
        result *= c;
    }
    return result;
    }
int main() {
init();
check_equal( cool_function(2, 3), 6 );
quit();
}