#include<iostream>
using namespace std;

struct Pixel{
    unsigned char red;
    unsigned char blue;
    unsigned char green;
    
};
int main(){
    Pixel p1;
    p1.red = p1.green = p1.blue = 17;
    cout << "p1.green " << (int)p1.green<< endl;
}