#include<iostream>
using namespace std;
int main(){
    int * foo;
    foo = new int[10000000000000000000];
    foo[100000000000] = 5;
}