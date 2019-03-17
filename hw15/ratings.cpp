#include <iostream>
using namespace std;

class Rating{
    int id, stars;
    public:
    int set_stars(int number_of_stars){
        if(number_of_stars < 1){
            stars = 1;
        }
        else if (number_of_stars > 5){
            stars = 5;
        }
        else{
            stars = number_of_stars;
        }
        return stars;
    }
    int get_id(){
        return id;
    }
    int get_stars(){
        return stars;
    }
    void display(std::ostream &os){
        os << id;
        os << ":";
        for(int i=0; i<stars; i++){
            os << "*";
        }
        os << endl;
    }
Rating (int id_number, int number_of_stars){
    id = id_number;
    if(number_of_stars >=1 && number_of_stars <= 5){
        stars= number_of_stars;
    }
}
};
int main() {
    Rating r(1234, 3);
    cout << "Rating r contains ";   r.display(cout);  cout << endl;
    r.set_stars(4);
    cout << "After r.set_stars(4), id=" << r.get_id()
        << " and stars=" << r.get_stars() << endl;

    Rating *arr[8];
    int i;
    for (i = 0;  i < 8;  i++)
        arr[i] = new Rating(100+i, i);
    cout << "Ratings in array arr:  ";
    for (i = 0;  i < 8;  i++)
        arr[i]->display(cout); cout << "  ";
    cout << endl;
}