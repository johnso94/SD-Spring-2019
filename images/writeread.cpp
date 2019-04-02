#include<fstream>
#include<iostream>
using namespace std;

int main() {

    ofstream f("output.txt");

    f << "1 2" << endl;
    f.close();

    ifstream g("output.txt");

    int i, j;
    g >> i >> j;
    g.close();
    cout << "i is " << i << " and j is " << j << endl;
}