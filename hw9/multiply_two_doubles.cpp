#include"sd_fun.h"
double multiply_two_doubles(double a, double b) {
    double result;
    result = a * b;
    return result;
    }
int main() {
init();
near_equal( multiply_two_doubles(2.5, 3), 7.5 );
near_equal( multiply_two_doubles(.5, .5), .25 );
quit();
}