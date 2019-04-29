#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>
#include<fstream>
int main(){
    map<string, int> num;
    map<string, string> dict;
    string fname = "data.txt";
    ifstream f(fname.c_str());
    string t;
    while (f >> t) {
        int n;
        f >> n;
        string d;
        getline(f, d);
        num[t] = n;
        dict[t] = d;
        cout << num["aardvark"] << ' ' << dict["aardvark"] << endl;
        cout << endl;
        for (auto p : dict)
            cout << p.first << ' ' << p.second << endl;
            cout << endl;
    }
}
