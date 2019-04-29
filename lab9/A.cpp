#include<iostream>
using namespace std;
int main(){
    int z = 3;
    float c = 4;
    auto w = z;
    cout << w << endl;
    auto &w2 = z;
    w2 = 5;
    cout << w2 << endl;
    cout << z << endl;
}