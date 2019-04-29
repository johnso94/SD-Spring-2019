#include<iostream>
using namespace std;
#include<vector>
int main(){
    vector<int> v = {2, 3, 5, 7, 11};
    for(int i = 0; i < 5; ++i)
        cout << v[i] << endl;
    for (int x : v)
        cout << x << endl;

    cout << v.size() << endl << endl;

    v.push_back(5);
    for (auto x : v)
        cout << x << endl;
    cout << endl;

    v.erase(v.begin() + 1);
    for (auto x : v)
        cout << x << endl;
    cout << endl;

    v.insert(v.begin() + 2, 9);
    for (auto x : v)
    cout << x << endl;
    cout << endl;
    for (int i = 0; i < 3 ; i++){
        v.insert(v.begin() + 3+i, i);
    }
    for (auto x : v)
    cout << x << endl;
    cout << endl;
    // v.clear();
    // cout << v.size() << endl;
}