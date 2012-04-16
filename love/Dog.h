#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Dog {
    public:
        Dog(); //constructed function
        /* set dog's messages in detial
        for example:
            void set_dog_v'day_gift(); //set Valentine's day gift
        */
        void set_dog_name(string in_name) {name = in_name;}
        void set_dog_age(int in_age) {age = in_age;}
        void set_dog_living_expenses(int in_living_expenses) {living_expenses = in_living_expenses;}
        void set_dog_wage(int in_wage) {wage = in_wage;}
        void set_dog_deposit(int in_deposit) {deposit = in_deposit;}
        void set_dog_down_payment(int in_down_payment) {down_payment = in_down_payment;}
        void set_dog_message();
        void set_dog_love();
        int show_dog_love();
        void show_dog_events();
        /*show dog'messages*/
        void show_dog_message();
    private:
        string event1;        // event
        string event2;
        string event3;
        string event4;
        string event5;
        string name;          // name
        int love;             // love
		int event[5];         // set of event
        int age;              // age
        int living_expenses;  // living_expenses
        int wage;             // wage
        int deposit;          // deposit
        int down_payment;     // down_payment
        bool like;            // the dog whether like the kitten
        bool have_house;      // if the dog has a house
};
