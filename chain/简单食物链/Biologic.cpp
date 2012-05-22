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
    cout<<"constructors"<<endl;
    deadline = 0;
    position = 0;
}
Grass::Grass(const Grass &grass) {
    cout<<"copy constructors"<<endl;
    age = rand() % 100;
    deadline = rand() % 100;
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
    age = rand() % 100;
    deadline = rand() % 50 + 50;
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
    age = rand() % 100;
    deadline = rand() % 50 + 50;
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
    age = rand() % 100;
    deadline = rand() % 50 + 50;
    position = rand() % 100;
}
//static 
int Grass::count = 100;
int Hare::count = 30;
int Fox::count = 10;
int Wolf::count = 2;
//other functions
