#include<iostream>
using namespace std;
int main(){
     int *p0 = new int;
     *p0 = 5;
     cout << "*p0==" << *p0 << endl;

     int *p1 = new int[3];
     p1[0] = 11;
     p1[1] = 12;
     p1[2] = 13;
     cout << "p1[1]==" << p1[1] << endl;

     int * p2 = p0;
     p0 = p1;
     p1 = p2;
     cout << "p1==" << *p1 << endl;
     cout << "*p0[1]==" << p0[1] << endl;
     cout << "*p01[1]==" << p1[1] << endl;
     delete p0;
     delete [] p1;
}