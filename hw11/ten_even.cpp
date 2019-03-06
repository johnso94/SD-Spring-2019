#include<iostream>
using namespace std;

int main(){
    cout << "Type a number: ";
    int n;
    cin >> n;
    if (n % 2){
        n += 1;
    }
    else{
        n+=2;
    }
    for(int i=0; i<10; i++){
    cout << n << endl;
    n += 2;
    }
}