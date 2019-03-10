#include<iostream>
using namespace std;
unsigned char * read_ppm(char * format_name, int &x, int &y, int &range){
    cin >> format_name;
    cin >> x >> y >> range;
    cin.get();
    unsigned char *data = new unsigned char[3*x*y];
    cin.read((char *)data, 3*x*y);
    return data;
}
void write_ppm(char * format_name, int x ,int y, int range, unsigned char * data){
    cout << format_name << endl;
    cout << x << " " << y << endl << range << endl;
    cout.write((char *)data, 3*x*y);
}
int main(){
    char fname[5];
    int x, y, range;
    unsigned char * data;
    data = read_ppm(fname, x, y, range);
    int br = 30;
    unsigned char *data2 = new unsigned char[3*(x + 2*br)*(y + 2 * br)];
    int n = 0;
    int q;
    for (int i = 0; i < br * (x + 2 * br); i++){
        data2[n]=75;
        n++;
        data2[n]=0;
        n++;
        data2[n]=130;
        n++;
    }
    for(int i = 0; i < y; i++){
        for (int i2 = 0; i2 < br; i2++){
            data2[n]=75;
            n++;
            data2[n]=0;
            n++;
            data2[n]=130;
            n++;
        }
        for (int i2 = 0; i2 < 3 * x; i2++){
                q = 3 * x * i + i2;
                data2[n]=data[q];
                n++;
            }
        for (int i2 = 0; i2 < br; i2++){
            data2[n]=75;
            n++;
            data2[n]=0;
            n++;
            data2[n]=130;
            n++;
        }
    }
        for (int i = 0; i < br * (x + 2*br); i++){
        data2[n]=75;
        n++;
        data2[n]=0;
        n++;
        data2[n]=130;
        n++;
    }

    write_ppm(fname, x + 2*br, y + 2*br, range, data2);

    delete [] data;
}
