#include<iostream>
using namespace std;
int main(){
    int arr[5] = {2,3,5,7,11};
    // for (int i = 0; i< 5; ++i)
    //     cout << arr[i] << endl;
    for (int &x : arr)
        x = 19;
    for (auto x : arr)
        cout << x << endl;
}