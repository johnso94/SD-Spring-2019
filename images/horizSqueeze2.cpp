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
    cin >> fname;
    cin >> x >> y >> range;
    cin.get();
    Pixel** Images = new Pixel*[y];
    Pixel** Images2 = new Pixel*[y];
    for(int i=0; i < y; i++){
        Images[i] = new Pixel[x];
    }
    for(int i=0; i < y; i++){
        cin.read((char *) Images[i], x*sizeof(Pixel));
    }
    for(int i=0; i<y; i++){
        Images2[i] = new Pixel[x];
    }
    int n = 0;
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            if (x % 2 == 1){
                if (j % x == 0){
                    j++;
            }
        }
            if(j%2 == 1){
                Images2[i][n] = Images[i][j];
                n++;
            }
        }
        n = 0;
    }
    write_ppm(fname, x/2, y, range, Images2);

    delete[] Images;
}