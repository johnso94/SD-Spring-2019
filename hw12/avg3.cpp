 #include <iostream>
 using namespace std;

 int main() {
     int * foo;
     int n;
     int a = 0;
     cin >> n;
     foo = new int [n];
     for(int i = 0; i < n; i++){
         cin >> foo[n];
         a += foo[n];
     }
     a = a/n;
     cout << a;
 }