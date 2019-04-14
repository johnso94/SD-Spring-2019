#ifndef _HARRYPOTTERDVD_H_
#define _HARRYPOTTERDVD_H_

#include "DVD.h"
#include<iostream>
using namespace std;

class HarryPotterDVD: public DVD{
    int episode;
    char * antagonist;
    public:
    HarryPotterDVD(unsigned int i, char* t, char * dir, int n, char * ant){
        id = i;
        title = t;
        director = dir;
        episode = n;
        antagonist = ant;
    }
    HarryPotterDVD(){
        episode = -1;
        antagonist = new char[0];
    }
    HarryPotterDVD(const HarryPotterDVD &HP){
        episode = HP.episode;
        int len1 = 0;
        for(int i = 0; HP.antagonist[i] != '\0'; i++){
            len1++;
        }
        len1++;
        antagonist = new char[len1];
        for(int i = 0; i < len1; i++){
            antagonist[i] = HP.antagonist[i];
        }
    }
    ~HarryPotterDVD(){
        delete antagonist;
    }
    int getEpisode();
    char* getAntagonist();
    void display();
    void setEpisode(unsigned int e);
    void setAntagonist(const char * c);
    HarryPotterDVD& operator= (const HarryPotterDVD &st);
};

#endif //HarryPotterDvd