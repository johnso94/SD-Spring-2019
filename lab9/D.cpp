#include<iostream>
using namespace std;
#include<string>
int main(){
    string s = "hi hi";
    cout << s[1] << endl;
    cout << "size " << s.size() << endl;
    s = s + " ok";
    cout << s << endl;
    string s2 = "ji ji";
    cout << (s < s2) << endl;
}
