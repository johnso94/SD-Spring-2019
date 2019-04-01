#include<fstream>
#include<iostream>
using namespace std;

int main() {
    ofstream f("output.txt");

    f << "Testing" << endl;

    ifstream g("output.txt");

    char * message = new char[7];
    g >> message;
    f.close();
    g.close();

    cout << message << endl;
}