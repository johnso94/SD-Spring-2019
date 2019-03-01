#include"sd_fun.h"
void reference_multiplication_function(int a, int &b) {
    b *= a;
    }
int main() {
init();
int a = 2;
int b = 4;
reference_multiplication_function(a,b);
check_equal( b, 8 );
quit();
}