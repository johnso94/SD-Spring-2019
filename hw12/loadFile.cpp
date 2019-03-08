 #include <iostream>
 using namespace std;

 int main() {
     int * foo;
     int n;
     cin >> n;
     foo = new int [n];
     for(int i = 0; i < n; i++){
         cin >> foo[n];
         cout << foo[n] << "    ";
     }
 }