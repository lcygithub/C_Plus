#include "Dog.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
Dog::Dog() {
    int dom;
    srand(time(0));
    dom = rand() % 10 + 1;    //Random fixed whether like
    if(dom > 5) like = true;          
    else like = false;
    dom = rand() % 10 + 1;    //Random fixed whether have houese
    if(dom > 5) have_house = true;
    else have_house = false;
    name = "dog";
    love = 0;
    age = 0;
    living_expenses = 0;
    wage = 0;
    deposit = 0;
    down_payment = 200000;
}
void Dog::set_dog_love() {
    int choice = 1;
    while(choice >= 1 && choice < 6) {
        cout<<endl;
		cout<<"			#########################################################"<<endl;
		cout<<"			####                   Set Dog's Events!             ####"<<endl;
		cout<<"			#########################################################"<<endl;
		cout<<"			####                                                 ####"<<endl;
		cout<<"			#### 1、Cat gives one gift in Valentine's day.       ####"<<endl;
		cout<<"			####                                                 ####"<<endl;
		cout<<"			#### 2、Cat gives two gifts in Valentine's day.      ####"<<endl;
		cout<<"			####                                                 ####"<<endl;
		cout<<"			#### 3、Cat give one gift to cat in cat's birthday.  ####"<<endl;
		cout<<"			####                                                 ####"<<endl;
		cout<<"			#### 4、Cat give two gifts to cat in cat's birthday. ####"<<endl;
		cout<<"			####                                                 ####"<<endl;
		cout<<"			#### 5、Dog argument with cat!.                      ####"<<endl;
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
void Dog::set_dog_message() {
    int in_love,in_age,in_living_expenses,in_deposit,in_wage,in_down_payment;
    string in_name;
    cout<<"			>>>Set dog'messages,please!"<<endl;
    cout<<"			>>>Set dog'name:";
    cin>>in_name;
    set_dog_name(in_name);
    cout<<"			>>>Set dog'age:";
    cin>>in_age;
    set_dog_age(in_age);
    cout<<"			>>>Set dog'living_expenses:";
    cin>>in_living_expenses;
    set_dog_living_expenses(in_living_expenses);
    cout<<"			>>>Set dog'wage:";
    cin>>in_wage;
    set_dog_wage(in_wage);
    cout<<"			>>>Set dog'deposit:";
    cin>>in_deposit;
    set_dog_deposit(in_deposit);
    cout<<"			>>>Set the house'down-payment:";
    cin>>in_down_payment;
    set_dog_down_payment(in_down_payment);
    cout<<"			>>>Dog's meessages set completed!"<<endl;
}
void Dog::show_dog_message() {
    if(deposit >= down_payment) {
        if(have_house == false) {
            deposit -= down_payment;
            have_house = true;
        }
    }
    string ilike,house;
    if(like == 1) ilike = " like the kitten!";
    else ilike = " doesn't like the kitten!";
    if(have_house == 0) house = " has a house!";
    else house = " does have a house!";
	cout<<"			###############################################"<<endl;
	cout<<"			####              Dog's Messages!          ####"<<endl;
	cout<<"			###############################################"<<endl;
	cout<<"			####                                       ####"<<endl;
	cout<<"			####>>>>name:"<<name<<endl;
	cout<<"			####>>>>age:"<<age<<endl;
	cout<<"			####>>>>love:"<<love<<endl;
	cout<<"			####>>>>living_expenses:"<<living_expenses<<endl;
	cout<<"			####>>>>wage:"<<wage<<endl;
	cout<<"			####>>>>deposit:"<<deposit<<endl;
	cout<<"			####>>>>"<<name<<ilike<<endl;
	cout<<"			####>>>>"<<name<<house<<endl;
	cout<<endl;
    string cho;
    while(cho != "y" && cho != "Y") {
    	cout<<"			>>>>Continue,please press[Y]:";
    	cin>>cho;
    }
}
void Dog::show_dog_events() {
	if(like == true) cout<<"			>>>>"<<"Dog like her!"<<endl;
	else cout<<"			>>>>"<<"Dog doesn't like her."<<endl;
	if(event[0] == 1) cout<<event1<<endl;
	else if(event[1] == 1) cout<<"			>>>>"<<event2<<endl;
	else if(event[2] == 1) cout<<"			>>>>"<<event3<<endl;
	else if(event[3] == 1) cout<<"			>>>>"<<event4<<endl;
	else if(event[4] == 1) cout<<"			>>>>"<<event5<<endl;
}
int Dog::show_dog_love() {
	if(love >= 9) {
		if(have_house)
		    return 1;
	}
	return 0;
}
