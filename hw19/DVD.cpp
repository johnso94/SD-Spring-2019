#include "DVD.h"

unsigned int DVD::getId(){
    return id;
}
char * DVD::getTitle(){
    return title;
}
char * DVD::getDirector(){
    return director;
}
void DVD::display(){
    cout << '[' << id << ".  " << title << '/' << director << ']' << endl;
}
void DVD::setId(unsigned int i){
    id = i;
}
void DVD::setTitle(const char* t){
    int len3 = 0;
    delete [] title;
    for(int i = 0; t[i] != '\0'; i++){
        len3++;
    }
    title = new char[len3 + 1];
    for(int i=0; i < (len3 + 1); i++){
        title[i] = t[i];
    }
}
void DVD::setDirector(const char* t){
    int len4 = 0;
    delete [] director;
    for(int i = 0; t[i] != '\0'; i++){
        len4++;
    }
    director = new char[len4 + 1];
    for(int i=0; i < (len4 + 1); i++){
        director[i] = t[i];
    }
}

DVD& DVD::operator=(const DVD &d)
{
    delete [] title;
    delete [] director;

    id = d.id;
    int len1;
    int len2;
    for(len1=0; d.title[len1] != '\0'; ++len1) ;
    for(len2=0; d.director[len2] != '\0'; ++len2) ;

    title = new char[len1+1];
    director = new char[len2+1];
    for(int i=0; i<len1+1; ++i) {
        title[i] = d.title[i];
    }
    for(int i=0; i<len2+1; ++i) {
        director[i] = d.director[i];
    }
    return *this;
}
int DVD::operator++(){
    id += 1;
    return id;
}
int DVD::operator++(int){
    id += 1;
    return id - 1;
}