#include<iostream>
using namespace std;

struct Pixel{
    unsigned char red;
    unsigned char blue;
    unsigned char green;
    
};
void write_ppm(char * format_name, int x ,int y, int range, unsigned char * data){
    cout << format_name << endl;
    cout << x << " " << y << endl << range << endl;
    cout.write((char *)data, sizeof(Pixel)*x*y);
}
int main(){
    char fname[5];
    int x, y, range;
    cin >> fname;
    cin >> x >> y >> range;
    Pixel** Images = new Pixel*[y];
    for(int i=0; i<y; i++){
        Images[i] = new Pixel[x];
    }
    Images[0][1].green = 255;
    cout << (int)Images[0][1].green << endl;
    for(int i=0; i < y; i++){
        cin.read( (char *) Images[i], x*sizeof(Pixel));
    }
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            cout << (int)Images[i][j].red << " " << (int)Images[i][j].blue << " " << (int)Images[i][j].green << endl;
        }
    }
}