#include<iostream>
using namespace std;
struct Pixel{
    unsigned char red;
    unsigned char blue;
    unsigned char green;
    
};
class Image {
    int width;
    int height;
    int depth = 255;
    Pixel ** data;
    public:
    Image(int w,int h){
    width = w;
    height = h;
    data = new Pixel*[height];
    for(int i = 0; i<height; i++){
        data[i] = new Pixel[width];
    }
    }
    ~Image(){
        delete data;
    }
    int getWidth(){
        return width;
    }
    int getHeight(){
        return height;
    }
    void print();
};
void Image::print(){
    cout << "P6" << endl;
    cout << width << " " << height << endl;
    cout << depth << endl;
    for(int i = 0; i < height; i++){
        cout.write((char *)data[i],sizeof(Pixel) * width);
    }
}
int main(){
    Image cat(5,5);
    cat.print();
    return 0;
}