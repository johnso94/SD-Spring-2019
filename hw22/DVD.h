#ifndef _DVD_
#define _DVD_

#include<iostream>
using namespace std;

class DVD{
    public:
    unsigned int id;
    char * title;
    char * director;
    DVD(unsigned int i, char* t, char * dir){
        id = i;
        int len1 = 0;
        int len2 = 0;
        for(int i = 0; t[i] != '\0'; i++){
            len1++;
        }
        for(int i = 0; dir[i] != '\0'; i++){
            len2++;
        }
        title = new char[len1+1];
        director = new char[len2+1];
        for(int i = 0; i < len1+1; i++){
            title[i] = t[i];
        }
        for(int i = 0; i < len2+1; i++){
            director[i] = dir[i];
        }
    }
    DVD(){
        id = 0;
        title = new char[1];
        director = new char[1];
        title[0] = '\0';
        director[0] = '\0';
    }
    DVD(const DVD &d){
        id = d.id;
        int len1 = 0;
        int len2 = 0;
        for(int i = 0; d.title[i] != '\0'; i++){
            len1++;
        }
        for(int i = 0; d.director[i] != '\0'; i++){
            len2++;
        }
        title = new char[len1 + 1];
        director = new char[len2 + 1];
        for(int i = 0; i < (len1+1); i++){
            title[i] = d.title[i];
        }
        for(int i = 0; i < (len2+1); i++){
            director[i] = d.director[i];
        }
    }
    ~DVD(){
        delete [] title;
        delete [] director;
    }
    unsigned int getId();
    char * getTitle();
    char * getDirector();
    void display();
    void setId(unsigned int i);
    void setTitle(const char* t);
    void setDirector(const char* t);
    DVD& operator=(const DVD &d);
};
#endif //_DVD_
