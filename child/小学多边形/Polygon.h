#include <iostream>
#ifndef POLYGON_H
#define POLYGON_H
class Polygon {
    public:
        Polygon();  //constructor
        /*
            set functions:set the value of the attribute
            for example:
                set_height(int hg) { height = hg; }   
        */
        void set_height(int hg) { height = hg; }
        void set_length(int lg) { length = lg; }
        void set_radius(int rd) { radius = rd; }
        void set_upper_base(int ub) { upper_base = ub; }
        void set_lower_base(int lb) {lower_base = lb; }
        /*
            get function: return the value of the attribute
            for example:
            get_height() { return height; }
        */
        int get_height() const { return height; }
        int get_length() const { return length; }
        int get_radius() const { return radius; }
        int get_upper_base() const { return upper_base; }
        int get_lower_base() const { return lower_base; }
    protected:
        int height;     // the polygon's height
        int length;     // the polygon's length
        int radius;     // the polygon's radius
        int upper_base; // the polygon's upper_base
        int lower_base; // the polygon's lower_base
};
/*
    inheritance
    show() show the main attributes
    get_perimeter() return the polygon's perimeter
    get_area() return the polygon's area
*/
class Square:public Polygon {
    public:
//        Square(int lg = 0):Polygon(length = lg)
        void build_random();
        void show();
        int get_perimeter();
        int get_area();
};
class Rectangle:public Polygon {
    public:
//        Rectangle(int lg = 0,int hg = 0) { length = lg;height = hg; }
        void build_random();
        void show();
        int get_perimeter();
        int get_area();
};
class Trapezoid:public Polygon {
    public:
//        Trapezoid(int up = 0,int lw = 0,hg = 0) { height = hg;upper_base = up;height = hg; }
        void build_random();
        void show();
        int get_perimeter();
        int get_area();
    private:
        int left;
        int right;
};
class Round:public Polygon {
    public:
//        Round(int rd = 0) { radius = rd; }
        void build_random();
        void show();
        float get_perimeter();
        float get_area();
};
class Triangle:public Polygon { 
    public:
//        Triangle(int lg = 0,int hg = 0) { height = hg;length = lg; }
        void build_random();
        void show();
        int get_perimeter();
        int get_area();
    private:
        int left;
        int right;
};
#endif
