#include"sd_fun.h"
int absolute_value(int a) {
    double result;
    result = 5 * (a - 32) / 9;
    return result;
    }
int main() {
init();
near_equal( convert_to_celsius(95), 35 );
near_equal( convert_to_celsius(32), 0 );
near_equal( convert_to_celsius(-40), -40 );
quit();
}