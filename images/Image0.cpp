#include<iostream>
using namespace std;

class Image0 {
    int width;
    int height;
    public:
    Image0(int w,int h){
    width = w;
    height = h;
    }
    int getWidth(){
        return width;
    }
    int getHeight(){
        return height;
    }
};
int main(){
    Image0 cat(5,6);
    cout << cat.getWidth() << ", " << cat.getHeight() << endl;
    Image0 dog(6,7);
    cout << dog.getWidth() << ", " << dog.getHeight() << endl;
}