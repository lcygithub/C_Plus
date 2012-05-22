#include <iostream>
#include "Polygon.h"
using namespace std;

/*
    the Classes of user's answer
    in private,defined the user's answer
    you can get or change the answer through the public's methods
*/
class User_Square {
    public:
        void set_perimeter(int pe) { perimeter = pe; }
        int get_perimeter() { return perimeter; }
        void set_area(int ar) { area = ar; }
        int get_area() { return area; }
        void set_right(int rig = 0) {if(rig == 0) right = false;else right = true;}
        bool get_right() { return right; }
    private:
        int perimeter;
        int area;
        bool right;
};
class User_Rectangle {
    public:
        void set_perimeter(int pe) { perimeter = pe; }
        int get_perimeter() { return perimeter; }
        void set_area(int ar) { area = ar; }
        int get_area() { return area; }
        void set_right(int rig = 0) {if(rig == 0) right = false;else right = true;}
        bool get_right() { return right; }
    private:
        int perimeter;
        int area;
        bool right;
};
class User_Triangle {
    public:
        void set_perimeter(int pe) { perimeter = pe; }
        int get_perimeter() { return perimeter; }
        void set_area(int ar) { area = ar; }
        int get_area() { return area; }
        void set_right(int rig = 0) {if(rig == 0) right = false;else right = true;}
        bool get_right() { return right; }
    private:
        int perimeter;
        int area;
        bool right;
};
class User_Trapezoid {
    public:
        void set_perimeter(int pe) { perimeter = pe; }
        int get_perimeter() { return perimeter; }
        void set_area(int ar) { area = ar; }
        int get_area() { return area; }
        void set_right(int rig = 0) {if(rig == 0) right = false;else right = true;}
        bool get_right() { return right; }
    private:
        int perimeter;
        int area;
        bool right;
};
class User_Round {
    public:
        void set_perimeter(float pe) { perimeter = pe; }
        float get_perimeter() { return perimeter; }
        void set_area(float ar) { area = ar; }
        float get_area() { return area; }
        void set_right(int rig = 0) {if(rig == 0) right = false;else right = true;}
        bool get_right() { return right; }
    private:
        int perimeter;
        float area;
        bool right;
};
class Test {
    public:
        Test();            //random make five problems \
                              and defult the value of this attribult
        void Answer();     // answer the problems
        void Goback();     // go back to see and check
        void Submit();     // submit the paper
        void set_count(int cn) { count = cn; }
        int get_count() { return count; }
        void set_right() { right += 1; }
        int get_right() { return right; }
    private:
        int scores;    // scores
        int right;     // counts of right
        int count;
        /*the obj of every polygon*/
    protected:
        Round round;
        Square square;
        Trapezoid trapezoid;
        Triangle triangle;
        Rectangle rectangle;
        
        User_Square uSquare;
        User_Rectangle uRectangle;
        User_Triangle uTriangle;
        User_Trapezoid uTrapezoid;
        User_Round uRound;
};
