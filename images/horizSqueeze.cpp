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
    int nx = x/2;
    unsigned char *data2 = new unsigned char[3*nx*y];
    int n = 0;
    for(int i = 0; i < 3 * y * x; i++){
        if (x % 2 == 1){
            if (i % x == 0){
                i++;
            }
        }
        if (i % 6  == 0){
            data2 [n] = data[i];
            n++;
            data2 [n] = data[i+1];
            n++;
            data2 [n] = data[i+2];
            n++;
        }
    }

    write_ppm(fname, nx, y, range, data2);

    delete [] data;
}
