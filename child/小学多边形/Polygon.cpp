#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "Polygon.h"
using namespace std;
Polygon::Polygon() {
    height = 0;    // the polygon's height
    length = 0;    // the polygon's length
    radius = 0;    // the polygon's radius
    upper_base = 0;// the polygon's upper_base
    lower_base = 0;// the polygon's lower_base
}
// Square
void Square::build_random() {
    int dom;
    srand(time(0));            //Random
    dom = rand() % 100 + 1;    //dom  1---100
    height = dom;
}
int Square::get_perimeter() {
    return 4*height;
}
int Square::get_area() {
    return height * height;
}
void Square::show() {
    cout<<"The squre's height is "<<height<<endl;
}
// Rectangle
void Rectangle::build_random() {
    int dom;
    srand(time(0));            //Random
    dom = rand() % 100 + 1;    //dom  1---100
    height = dom;
    dom = 0;
    srand(time(0));            //Random
    dom = rand() % 100 + 1;    //dom  1---100
    length = dom;
}
int Rectangle::get_perimeter() {
    return 2*(height + length);
}
int Rectangle::get_area() {
    return height * length;
}
void Rectangle::show() {
    cout<<"The Rectangle's height is "<<height<<endl;
    cout<<"The Rectangle's length is "<<length<<endl;
}
// Trapezoid
void Trapezoid::build_random() {
    int dom;
    srand(time(0));            //Random
    dom = rand() % 100 + 1;    //dom  1---100
    height = dom;
    dom = rand() % 100 + 1;    //dom  1---100
    upper_base = dom;
    dom = rand() % 100 + 1;    //dom  1---100
    lower_base = dom;
    dom = rand() % 100 + 1;    //dom  1---100
    left = dom;
    dom = rand() % 100 + 1;    //dom  1---100
    right = dom;
}
int Trapezoid::get_perimeter() {
    return (upper_base + lower_base + right + left);
}
int Trapezoid::get_area() {
    return ((upper_base + lower_base)*height)/2;
}
void Trapezoid::show() {
    cout<<"The Trapezoid's upper_base is "<<upper_base<<endl;
    cout<<"The Trapezoid's lower_base is "<<lower_base<<endl;
    cout<<"The Trapezoid's height is "<<height<<endl;
    cout<<"The Trapezoid's left is "<<left<<endl;
    cout<<"The Trapezoid's right is "<<right<<endl;
}
// Round
void Round::build_random() {
    int dom;
    srand(time(0));            //Random
    dom = rand() % 100 + 1;    //dom  1---100
    radius = dom;
}
float Round::get_perimeter() {
    return 2*radius*3.14;
}
float Round::get_area() {
    return 3.14*radius*radius;
}
void Round::show() {
    cout<<"The radius's height is "<<radius<<endl;
}
// Triangle
void Triangle::build_random() {
    int dom;
    srand(time(0));            //Random
    dom = rand() % 100 + 1;    //dom  1---100
    height = dom;
    dom = rand() % 100 + 1;    //dom  1---100
    lower_base = dom;
    dom = rand() % 100 + 1;    //dom  1---100
    left = dom;
    dom = rand() % 100 + 1;    //dom  1---100
    right = dom;
}
int Triangle::get_perimeter() {
    return (right + left + lower_base);
}
int Triangle::get_area() {
    return height * lower_base / 2;
}
void Triangle::show() {
    cout<<"The Triangle's height is "<<height<<endl;
    cout<<"The Triangle's left is "<<left<<endl;
    cout<<"The Triangle's right is "<<right<<endl;
    cout<<"The Triangle's lower_base is "<<lower_base<<endl;
}


