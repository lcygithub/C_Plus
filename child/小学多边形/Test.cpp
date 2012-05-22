#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "Test.h"
#include <time.h>
#include "Polygon.h"
using namespace std;
Test::Test() {
    right = 0;
    int count = 0;
    cout<<"please input the count of tests:";
    cin>>count;
    set_count(count);
    if(get_count() == 1) {
        round.build_random();     // build round
        round.show();
    } else if(get_count() == 2) {
        round.build_random();     // build round
        round.show();
        square.build_random();    // build square
        square.show();
    } else if(get_count() == 3) {
        round.build_random();     // build round
        round.show();
        square.build_random();    // build square
        square.show();
        trapezoid.build_random(); // build trapezoid
        trapezoid.show();
    } else if(get_count() == 4) {
        round.build_random();     // build round
        round.show();
        square.build_random();    // build square
        square.show();
        trapezoid.build_random(); // build trapezoid
        trapezoid.show();
        triangle.build_random();  // build triangle
        triangle.show();
    } else if(get_count() == 5) {
        round.build_random();     // build round
        round.show();
        square.build_random();    // build square
        square.show();
        trapezoid.build_random(); // build trapezoid
        trapezoid.show();
        triangle.build_random();  // build triangle
        triangle.show();
        rectangle.build_random(); // build rectangle
        rectangle.show();
    }
}
void Test::Answer() {
    int pe = 0;
    int ar = 0;
    if(get_count()== 1) {
        cout<<"input Round's perimeter:";
        cin>>pe;
        cout<<"input Round's area:";
        cin>>ar;
        uRound.set_perimeter(pe);
        uRound.set_area(ar);
    } else if(count == 2) {
        cout<<"input Round's perimeter:";
        cin>>pe;
        cout<<"input Round's area:";
        cin>>ar;
        uRound.set_perimeter(pe);
        uRound.set_area(ar);
        cout<<"input Square's perimeter:";
        cin>>pe;
        cout<<"input Square's area:";
        cin>>ar;
        uSquare.set_perimeter(pe);
        uSquare.set_area(ar);
    } else if(count == 3) {
        cout<<"input Round's perimeter:";
        cin>>pe;
        cout<<"input Round's area:";
        cin>>ar;
        uRound.set_perimeter(pe);
        uRound.set_area(ar);
        cout<<"input Square's perimeter:";
        cin>>pe;
        cout<<"input Square's area:";
        cin>>ar;
        uSquare.set_perimeter(pe);
        uSquare.set_area(ar);
        cout<<"input Trapezoid's perimeter:";
        cin>>pe;
        cout<<"input Trapezoid's area:";
        cin>>ar;
        uTrapezoid.set_perimeter(pe);
        uTrapezoid.set_area(ar);
    } else if(count == 4) {
        cout<<"input Round's perimeter:";
        cin>>pe;
        cout<<"input Round's area:";
        cin>>ar;
        uRound.set_perimeter(pe);
        uRound.set_area(ar);
        cout<<"input Square's perimeter:";
        cin>>pe;
        cout<<"input Square's area:";
        cin>>ar;
        uSquare.set_perimeter(pe);
        uSquare.set_area(ar);
        cout<<"input Trapezoid's perimeter:";
        cin>>pe;
        cout<<"input Trapezoid's area:";
        cin>>ar;
        uTrapezoid.set_perimeter(pe);
        uTrapezoid.set_area(ar);
        cout<<"input Triangle's perimeter:";
        cin>>pe;
        cout<<"input Triangle's area:";
        cin>>ar;
        uTriangle.set_perimeter(pe);
        uTriangle.set_area(ar);
    } else if(count == 5) {
        cout<<"input Round's perimeter:";
        cin>>pe;
        cout<<"input Round's area:";
        cin>>ar;
        uRound.set_perimeter(pe);
        uRound.set_area(ar);
        cout<<"input Square's perimeter:";
        cin>>pe;
        cout<<"input Square's area:";
        cin>>ar;
        uSquare.set_perimeter(pe);
        uSquare.set_area(ar);
        cout<<"input Trapezoid's perimeter:";
        cin>>pe;
        cout<<"input Trapezoid's area:";
        cin>>ar;
        uTrapezoid.set_perimeter(pe);
        uTrapezoid.set_area(ar);
        cout<<"input Triangle's perimeter:";
        cin>>pe;
        cout<<"input Triangle's area:";
        cin>>ar;
        uTriangle.set_perimeter(pe);
        uTriangle.set_area(ar);
        cout<<"input Rectangle's perimeter:";
        cin>>pe;
        cout<<"input Rectangle's area:";
        cin>>ar;
        uRectangle.set_perimeter(pe);
        uRectangle.set_area(ar);
    }
    cout<<"Complete!"<<endl;
}

void Test::Goback() {
    string con;
    do {
    int key = 0;
    int pe = 0;
    int ar = 0;
    do {
    cout<<"Show you hava done:"<<endl;
    cout<<"1、uRound."<<endl;
    cout<<"2、uSquare."<<endl;
    cout<<"3、uTrapezoid."<<endl;
    cout<<"4、uTriangle."<<endl;
    cout<<"5、uRectangle."<<endl;
    cin>>key;
    } while(key > get_count());
    switch(key) {
        case 1:
            round.show();
            cout<<"Your answer:"<<endl;
            cout<<"round's perimeter:"<<uRound.get_perimeter()<<endl;
            cout<<"round's perimeter:"<<uRound.get_area()<<endl;
            break;
        case 2:
            square.show();
            cout<<"Your answer:"<<endl;
            cout<<"square's perimeter:"<<uSquare.get_perimeter()<<endl;
            cout<<"square's perimeter:"<<uSquare.get_area()<<endl;
            break;
        case 3:
            trapezoid.show();
            cout<<"Your answer:"<<endl;
            cout<<"trapezoid's perimeter:"<<uTrapezoid.get_perimeter()<<endl;
            cout<<"trapezoid's perimeter:"<<uTrapezoid.get_area()<<endl;
            break;
        case 4:
            triangle.show();
            cout<<"Your answer:"<<endl;
            cout<<"triangle's perimeter:"<<uTriangle.get_perimeter()<<endl;
            cout<<"triangle's perimeter:"<<uTriangle.get_area()<<endl;
            break;
        case 5:
            rectangle.show();
            cout<<"Your answer:"<<endl;
            cout<<"rectangle's perimeter:"<<uRectangle.get_perimeter()<<endl;
            cout<<"rectangle's perimeter:"<<uRectangle.get_area()<<endl;
            break;
    }
    string contune;
    cout<<"change [y/n]:";
    cin>>contune;
    if(contune == "y") {
        do {
            cout<<"choose to change:"<<endl;
            cout<<"1、uRound."<<endl;
            cout<<"2、uSquare."<<endl;
            cout<<"3、uTrapezoid."<<endl;
            cout<<"4、uTriangle."<<endl;
            cout<<"5、uRectangle."<<endl;
            cout<<">>>>";
            cin>>key;
        }while(key > get_count());
        if(key == 1) {
            cout<<"1、change perimeter"<<endl;
            cout<<"2、change area"<<endl;
            cout<<">>>>";
            cin>>key;
            if(key == 1) {
                cin>>pe;
                uRound.set_perimeter(pe);
            } else {
                cin>>ar;
                uRound.set_area(ar);
            }
        } else if(key == 2){
            cout<<"1、change perimeter"<<endl;
            cout<<"2、change area"<<endl;
            cout<<">>>>";
            cin>>key;
            if(key == 1) {
                cin>>pe;
                uSquare.set_perimeter(pe);
            } else {
                cin>>ar;
                uSquare.set_area(ar);
            }
        } else if(key == 3){
            cout<<"1、change perimeter"<<endl;
            cout<<"2、change area"<<endl;
            cout<<">>>>";
            cin>>key;
            if(key == 1) {
                cin>>pe;
                uTrapezoid.set_perimeter(pe);
            } else {
                cin>>ar;
                uTrapezoid.set_area(ar);
            }
        } else if(key == 4){
            cout<<"1、change perimeter"<<endl;
            cout<<"2、change area"<<endl;
            cout<<">>>>";
            cin>>key;
            if(key == 1) {
                cin>>pe;
                uTriangle.set_perimeter(pe); 
            } else {
                cin>>ar;
                uTriangle.set_area(ar);
            }
        } else if(key == 5){
            cout<<"1、change perimeter"<<endl;
            cout<<"2、change area"<<endl;
            cout<<">>>>";
            cin>>key;
            if(key == 1) {
                cin>>pe;
                uRectangle.set_perimeter(pe); 
            } else {
                cin>>ar;
                uRectangle.set_area(ar);
            } 
        }
    }
    cout<<"continue[y/n]:"<<endl;
    cin>>con;
    }while(con == "y");
}
void Test::Submit() {
    if(get_count()== 1) {
        if(uRound.get_perimeter() == round.get_perimeter() && uRound.get_area() == round.get_area()) 
            set_right();
    } else if(get_count()== 2) {
        if(uRound.get_perimeter() == round.get_perimeter() && uRound.get_area() == round.get_area()) 
            set_right();
        if(uSquare.get_perimeter() == square.get_perimeter() && uSquare.get_area() == square.get_area())
            set_right();
    } else if (get_count()== 3) {
        if(uRound.get_perimeter() == round.get_perimeter() && uRound.get_area() == round.get_area()) 
            set_right();
        if(uSquare.get_perimeter() == square.get_perimeter() && uSquare.get_area() == square.get_area())
            set_right();
        if(uTrapezoid.get_perimeter() == uTrapezoid.get_perimeter() && uTrapezoid.get_area() == trapezoid.get_area())
            set_right();
    } else if (get_count()== 4) {
        if(uRound.get_perimeter() == round.get_perimeter() && uRound.get_area() == round.get_area()) 
            set_right();
        if(uSquare.get_perimeter() == square.get_perimeter() && uSquare.get_area() == square.get_area())
            set_right();
        if(uTrapezoid.get_perimeter() == uTrapezoid.get_perimeter() && uTrapezoid.get_area() == trapezoid.get_area())
            set_right();
        if(uTriangle.get_perimeter() == triangle.get_perimeter() && uTriangle.get_area() == triangle.get_area())
            set_right();
    } else if(get_count()== 5) {
        if(uRound.get_perimeter() == round.get_perimeter() && uRound.get_area() == round.get_area()) 
            set_right();
        if(uSquare.get_perimeter() == square.get_perimeter() && uSquare.get_area() == square.get_area())
            set_right();
        if(uTrapezoid.get_perimeter() == uTrapezoid.get_perimeter() && uTrapezoid.get_area() == trapezoid.get_area())
            set_right();
        if(uTriangle.get_perimeter() == triangle.get_perimeter() && uTriangle.get_area() == triangle.get_area())
            set_right();
        if(uRectangle.get_perimeter() == rectangle.get_perimeter() && uRectangle.get_area() == rectangle.get_area())
            set_right();
    }
    cout<<"Scores:";
    cout<<right<<"/"<<(get_count() - get_right())<<endl;
}






