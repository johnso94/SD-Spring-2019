#include<iostream>
using namespace std;
int length_of2(const char * array){
    int i = 0;
    while (array[i] != '\0'){
        i++;
    }
    return i;
}

void copyString(char * &a, const char * b){
    int n = length_of2(b);
    a = new char[n+1];
    for(int i=0; i < n; i++){
        a[i] = b[i];
    }
    a[n]='\0';
}
int main(){
    const char *str1 = "Hello!";
    char *str2;
    copyString (str2,str1);
    cout << "str1 is " << str1 << " and str2 is " << str2 << endl;
    delete [] str2;
    return '\0';
}