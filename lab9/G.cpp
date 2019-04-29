#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>
#include<fstream>
int main(){
    vector<string> v;
    string fname = "expenses.10000";
    ifstream f(fname.c_str());
    string t;
    while (getline(f,t)) {
        v.push_back(t);
    }
}