#include <iostream>
using namespace std;

class slime{
    public:
    int size;
    float color;
    slime() {};
    slime(int a, float b) : size(a), color(b){}
    slime operator + (const slime&);
    slime operator - (const slime&);
    slime operator * (int a);
};

slime slime:: operator + (const slime& param){
    slime temp;
    temp.size = size + param.size;
    temp.color = (color + param.color)/2;
    return temp;
}

slime slime:: operator - (const slime& param){
    slime temp;
    temp.size = size - param.size;
    temp.color = 2*color - param.color;
    return temp;
}

slime slime:: operator * (int a){
    slime temp;
    temp.size = size * a;
    temp.color = color;
    return temp;
}

int main(){
    slime red (3,2);
    slime blue (6,5);
    slime mix;
    mix = red + blue;
    cout << mix.size << ',' << mix.color << '\n';
    slime split;
    split = mix - red;
    cout << split.size << ',' << split.color << '\n';
    slime grow;
    grow = split * 2;
    cout << grow.size << ',' << grow.color << '\n';
    return 0;
}