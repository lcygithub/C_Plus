#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Cat {
    public:
        Cat(); //constructed function
        /* set cat's messages in detial
        for example:
            void set_cat_v'day_gift(); //set Valentine's day gift
        */
        void set_cat_name(string in_name) {name = in_name;}
        void set_cat_age(int in_age) {age = in_age;}
        void set_cat_living_expenses(int in_living_expenses) {living_expenses = in_living_expenses;}
        void set_cat_wage(int in_wage) {wage = in_wage;}
        void set_cat_deposit(int in_deposit) {deposit = in_deposit;}
        void set_cat_down_payment(int in_down_payment) {down_payment = in_down_payment;}
        void set_cat_vday_gift(bool y);
        void set_cat_birday_gift(bool y);
        void set_cat_message();
        void set_cat_love();
        /*get cat'messages*/
        void show_cat_events();
        int show_cat_love() {if(love  >= 9) return 1; else return 0;}
        /*show cat'messages*/
        void show_cat_message();
    private:
        string name;          // name
        /* every events in follows*/
        string event1;        
        string event2;        
        string event3;
        string event4;
        string event5;
        float love;           // love
        int event[5];         // set of event
        int age;              // age
        int living_expenses;  // living_expenses
        int wage;             // wage
        int deposit;          // deposit
        int down_payment;     // down_payment
        bool vday_gift;       // Valentine's day gift
        bool birday_gift;     // birthday gift
        bool like;            // the cat whether like the kitten
        bool have_house;      // if the cat has a house
};
