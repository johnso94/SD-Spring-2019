 #include<iostream>
 using namespace std;

 class UltimateFrisbee {
     int size;
     float *data;

     public:
         UltimateFrisbee() {
             size = 0;
             data = 0;
         }

         UltimateFrisbee(int s) {
             size = s;
             data = new float[size];
         }

         UltimateFrisbee(const UltimateFrisbee &u);
         ~UltimateFrisbee() {
             cout << "bye!" << endl;
             if ( data ) delete [] data;
         }

         void display() {
             cout << "size " << size << endl;
         }
 };
 UltimateFrisbee::UltimateFrisbee(const UltimateFrisbee &u){
     size = u.size;
     int len;
     for(len=0; u.data != '\0'; ++len){};
     data = new float[len];
     for(int i=0; i<len; ++i){
         data[i] = u.data[i];
     }
 };

 int main() {
     UltimateFrisbee g1, g2(3);

     g1.display();
     g2.display();
     return 0;
 }