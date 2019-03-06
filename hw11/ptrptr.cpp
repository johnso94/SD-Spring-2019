#include<iostream>
using namespace std;
int main(){
    int i = 5;
    int q = 10;
    int *pi = &i;
    int **ppi = &pi;
    *ppi = &q;
    *pi += 15;
    cout << "i == " << i << ", *pi == " << *pi << ", ** ppi ==" << **ppi << endl;
    
}