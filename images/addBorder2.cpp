#include<iostream>
using namespace std;

struct Pixel{
    unsigned char red;
    unsigned char blue;
    unsigned char green;
    
};
void write_ppm(char * format_name, int x ,int y, int range, Pixel** Images){
    cout << format_name << endl;
    cout << x << " " << y << endl << range << endl;
    for(int i=0; i<y; i++){
        cout.write((char *)Images[i], sizeof(Pixel)*x);
    }
}
int main(){
    char fname[5];
    int x, y, range;
    int br = 40;
    cin >> fname;
    cin >> x >> y >> range;
    cin.get();
    Pixel** Images = new Pixel*[y];
    Pixel** Images2 = new Pixel*[y + 2*br];
    for(int i=0; i < y; i++){
        Images[i] = new Pixel[x];
    }
    for(int i=0; i< (y + 2*br); i++){
        Images2[i] = new Pixel[2*br + x];
    }
    for(int i=0; i < y; i++){
        cin.read((char *) Images[i], x*sizeof(Pixel));
    }
    for (int i = 0; i < br; i++){
        for (int j = 0; j < x + 2*br; j++){
        Images2[i][j].red = 75;
        Images2[i][j].blue = 0;
        Images2[i][j].green = 130;
        }
    }
    int n = 0;
    for(int i = 0; i < y; i++){
        for(int j = 0; j<br; j++){
            Images2[i+br][j].red = 75;
            Images2[i+br][j].blue = 0;
            Images2[i+br][j].green = 130;
            n++;
        }
        for(int j = 0; j<x; j++){
            Images2[i+br][n] = Images[i][j];
            n++;
        }
        for(int j = 0; j<br; j++){
            Images2[i+br][j+x+br].red = 75;
            Images2[i+br][j+x+br].blue = 0;
            Images2[i+br][j+x+br].green = 130;
            n++;
        }
        n=0;
    }
    for (int i = (y+br); i < (y + 2*br); i++){
        for (int j = 0; j < x + 2*br; j++){
        Images2[i][j].red = 75;
        Images2[i][j].blue = 0;
        Images2[i][j].green = 130;
        }
    }
    write_ppm(fname, x + 2*br, 2 * br+y, range, Images2);

    delete[] Images;
}