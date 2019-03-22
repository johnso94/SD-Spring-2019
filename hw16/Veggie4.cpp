#include<iostream>
using namespace std;
class Veggie{
    public:
    int * other;
    ~Veggie(){delete other;}
    Veggie(const Veggie& x): other(new int(x)) {}
};
int main(){

}