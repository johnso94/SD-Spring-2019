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
    for(int i = 0; i < 3*x*y; i++){
        int n = 0;
        n += data[i];
        if (i % 3 == 2){
            n = n/3;
            data[i] = n;
            data[i-1] = n;
            data[i-2] = n;
        }
    }
    write_ppm(fname, x, y, range, data);

    delete [] data;
}
