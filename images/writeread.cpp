#include<fstream>
#include<iostream>
using namespace std;

int main() {
<<<<<<< HEAD
    ofstream f("output.txt");

    f << "Testing" << endl;

    ifstream g("output.txt");

    char * message = new char[7];
    g >> message;
    f.close();
    g.close();

    cout << message << endl;
=======

    ofstream f("output.txt");

    f << "1 2" << endl;
    f.close();

    ifstream g("output.txt");

    int i, j;
    g >> i >> j;
    g.close();
    cout << "i is " << i << " and j is " << j << endl;
>>>>>>> lab5
}