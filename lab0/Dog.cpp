/* Example implementation module for CS 251 R.Brown, rev 2/15 */

#include <cstring>
#include <iostream>
using namespace std;

#include "Dog.h"

/* helper -- create a newly allocated copy of a string*/
char * Dog::helper(const char *str) {
    char *copy = new char[strlen(str)+1];
    strcpy(copy, str);
    return copy;
}

/* destructor */
Dog::~Dog() {
    //cout <<"~Dog() called" <<endl;
    if(name != 0)
        delete [] name;
    name=0;
}

/* assignment operator */
Dog &Dog::operator=(const Dog &dog) {
    delete [] name;
    name = helper(dog.name);
    age = dog.age;
    return *this;
}

/* set_name -- assign a new name */
void Dog::set_name(const char *new_name) {
    delete [] name;
    name = helper(new_name);
}