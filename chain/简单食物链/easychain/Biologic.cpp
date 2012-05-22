#include "Biologic.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
// constructors
Biologic::Biologic() {
    age = 0;
    deadline = 0;
    position = 0;
}
Grass::Grass() {
    age = rand() % 100;
    deadline = 0;
    position = 0;
}
Grass::Grass(const Grass &grass) {
    age = rand() % 10;
    deadline = rand() % 10 + 10;
    position = rand() % 50 + 50;
}
Hare::Hare() {
    gender = "female";
    age = 0;
    deadline = 0;
    position = 0;
}
Hare::Hare(const Hare &hare) {
    if(rand()%2 == 0) gender = "female";
    else gender = "male";
    age = rand() % 10;
    deadline = rand() % 10 + 10;
    position = rand() % 100;
}
Fox::Fox() {
    gender = "female";
    age = 0;
    deadline = 0;
    position = 0;
}
Fox::Fox(const Fox &fox) {
    if(rand()%2 == 0) gender = "female";
    else gender = "male";
    age = rand() % 10;
    deadline = rand() % 10 + 10;
    position = rand() % 100;
}
Wolf::Wolf() {
    gender = "female";
    age = 0;
    deadline = 0;
    position = 0;
}
Wolf::Wolf(const Wolf & wolf) {
    if(rand()%2 == 0) gender = "female";
    else gender = "male";
    age = rand() % 10;
    deadline = rand() % 10 + 10;
    position = rand() % 100;
}
//static 
int Grass::count = 0;
int Hare::count = 0;
int Fox::count = 0;
int Wolf::count = 0;
//other functions
Biologic &Biologic::operator++ () {
    set_age(1);
    return *this;
}
Biologic Biologic::operator++ (int) {
    Biologic biologic = *this;
    ++(*this);
    return biologic; 
}
