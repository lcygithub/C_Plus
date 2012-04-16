#include "Cat.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
Cat::Cat() {             
    int dom;
    srand(time(0));            //Random fixed whether like
    dom = rand() % 100 + 1;    
    if(dom > 50) like = true;          
    else like = false;
    dom = rand() % 100 + 1;    //Random fixed whether have houese
    if(dom > 50) have_house = true;
    else have_house = false;
    /* set message by default*/
    name = "cat";
    love = 0;
    age = 0;
    living_expenses = 0;
    wage = 0;
    deposit = 0;
    down_payment = 200000;     
	event1 = "Dog gives one gift in Valentine's day.";
	event2 = "Dog gives two gifts in Valentine's day.";
	event3 = "Dog give one gift to cat in cat's birthday.";
	event4 = "Dog give two gifts to cat in cat's birthday.";
	event5 = "Argument!.";
}
void Cat::set_cat_love() {
    int choice = 1;
    while(choice >= 1 && choice < 6) {
        cout<<endl;
		cout<<"			#########################################################"<<endl;
		cout<<"			####                   Set Cat's Events!             ####"<<endl;
		cout<<"			#########################################################"<<endl;
		cout<<"			####                                                 ####"<<endl;
		cout<<"			#### 1、Dog gives one gift in Valentine's day.       ####"<<endl;
		cout<<"			####                                                 ####"<<endl;
		cout<<"			#### 2、Dog gives two gifts in Valentine's day.      ####"<<endl;
		cout<<"			####                                                 ####"<<endl;
		cout<<"			#### 3、Dog give one gift to cat in cat's birthday.  ####"<<endl;
		cout<<"			####                                                 ####"<<endl;
		cout<<"			#### 4、Dog give two gifts to cat in cat's birthday. ####"<<endl;
		cout<<"			####                                                 ####"<<endl;
		cout<<"			#### 5、Dog rgument with cat!.                       ####"<<endl;
		cout<<"			####                                                 ####"<<endl;
		cout<<"			#### 6、Completed.                                   ####"<<endl;
		cout<<"			####                                                 ####"<<endl;
		cout<<"			#########################################################"<<endl;
		cout<<endl;
		cout<<"			              >>>";
		cin>>choice;
		switch(choice) {
            case 1: love += 2;event[0] = 1;break;
            case 2: love += 4;event[1] = 1;break;
            case 3: love += 1;event[2] = 1;break;
            case 4: love += 2;event[3] = 1;break;
            case 5: love -= 0.5;event[4] = 1;break;
            case 6: break;
        }
    }
    if(like) love += 5;
}
void Cat::set_cat_message() {
    int in_love,in_age,in_living_expenses,in_deposit,in_wage,in_down_payment;
    string in_name;
    cout<<"			>>>Set cat'messages,please!"<<endl;
    cout<<"			>>>Set cat'name:";
    cin>>in_name;
    set_cat_name(in_name);
    cout<<"			>>>Set cat'age:";
    cin>>in_age;
    set_cat_age(in_age);
    cout<<"			>>>Set cat'living_expenses:";
    cin>>in_living_expenses;
    set_cat_living_expenses(in_living_expenses);
    cout<<"			>>>Set cat'wage:";
    cin>>in_wage;
    set_cat_wage(in_wage);
    cout<<"			>>>Set cat'deposit:";
    cin>>in_deposit;
    set_cat_deposit(in_deposit);
    cout<<"			>>>cat's meessages set completed!"<<endl;
    cout<<endl;
}
void Cat::show_cat_message() {
    string ilike;
    if(like == 1) ilike = " like the dog!";
    else ilike = " doesn't like the dog!";
	cout<<"			####################################################"<<endl;
	cout<<"			####                    Dog's Messages!         ####"<<endl;
	cout<<"			####################################################"<<endl;
	cout<<"			####                                            ####"<<endl;
	cout<<"			####>>>>name:"<<name<<endl;
	cout<<"			####>>>>age:"<<age<<endl;
	cout<<"			####>>>>love:"<<love<<endl;
	cout<<"			####>>>>living_expenses:"<<living_expenses<<endl;
	cout<<"			####>>>>wage:"<<wage<<endl;
	cout<<"			####>>>>deposit:"<<deposit<<endl;
	cout<<"			####>>>>"<<name<<ilike<<endl;
	cout<<endl;
    string cho;
    while(cho != "y" && cho != "Y") {
    	cout<<"			>>>>Continue,please press[Y]:";
    	cin>>cho;
    }
}
void Cat::show_cat_events() {
	if(like == true) cout<<"			>>>>"<<"Cat like him!"<<endl;
	else cout<<"			>>>>"<<"Cat doesn't like him."<<endl;
	if(event[0] == 1) cout<<"			>>>>"<<event1<<endl;
	if(event[1] == 1) cout<<"			>>>>"<<event2<<endl;
	if(event[2] == 1) cout<<"			>>>>"<<event3<<endl;
	if(event[3] == 1) cout<<"			>>>>"<<event4<<endl;
	if(event[4] == 1) cout<<"			>>>>"<<event5<<endl;
}

