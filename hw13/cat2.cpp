 #include<iostream>
 using namespace std;

 // A feline with a color and a weight in pounds
 struct Cat {
     int color;
     double weight;
     
     void grow() { // Increase the weight of Cat c
         weight *= 1.1;
     }
 };

 int main() {
     Cat misty, dusty;
     misty.color = 3;
     misty.weight = 2;
     cout << "misty weighs " << misty.weight << endl; //misty weighs 2
     misty.grow();
     cout << "misty weighs " << misty.weight << endl; //misty weighs 2.2
 }