#include "Dog.h"
#include "Cat.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
Dog *dog = new Dog; //object Dog
Cat *cat = new Cat; //object Cat
int main() {
	int choice = 0;
	void Show_menu();
	void Show_events();
	void Set_events();
	Show_menu();
	cin>>choice;
	while(choice>=1 && choice < 7) {
		switch(choice) {
			case 1: dog->set_dog_message();break; // set dog'message
			case 2: cat->set_cat_message();break; // set cat'message
			case 3: Set_events();break;           // set main events
			case 4: dog->show_dog_message();break; // show dog'message
			case 5: cat->show_cat_message();break; // show cat'message
			case 6: Show_events();break;          //
		}
		choice = 0;
		Show_menu();
		cin>>choice;
	}
	delete dog;
	delete cat;
    return 0;
}
void Show_menu() {
    cout<<"			#####################################"<<endl;
    cout<<"			####   Cat And Dog's Love Stroy! ####"<<endl;
    cout<<"			#####################################"<<endl;
    cout<<"			####                             ####"<<endl;
    cout<<"			####  1、Set the dog' messages.  ####"<<endl; 
    cout<<"			####                             ####"<<endl;
    cout<<"			####  2、Set the cat'messages.   ####"<<endl; 
    cout<<"			####                             ####"<<endl;
    cout<<"			####  3、Set the main events.    ####"<<endl; 
    cout<<"			####                             ####"<<endl;
    cout<<"			####  4、Show dog's messages.    ####"<<endl; 
    cout<<"			####                             ####"<<endl;
    cout<<"			####  5、Show cat's messages.    ####"<<endl; 
    cout<<"			####                             ####"<<endl;
	cout<<"			####  6、Show the main events.   ####"<<endl; 
    cout<<"			####                             ####"<<endl;
    cout<<"			####  7、EXIT.                   ####"<<endl;
    cout<<"			####                             ####"<<endl;
    cout<<"			#####################################"<<endl;
    cout<<"			####      Writer: 刘重阳         ####"<<endl;
    cout<<"			####      Number：20101611       ####"<<endl;
    cout<<"			####      Class: software 1005   ####"<<endl;
    cout<<"			#####################################"<<endl;
    cout<<endl;
    cout<<"			         >>>";                               // choice
}
void Show_events() {
	cat->show_cat_events();
	dog->show_dog_events();
	if(dog->show_dog_love() && cat->show_cat_love())
	    cout<<"			Result:The cat and the dog will be in love!"<<endl;
	else 
		cout<<"			Result:Both not decree by destiny!"<<endl;
    string cho;
    while(cho != "y" && cho != "Y") {
    	cout<<"			>>Continue,please press[Y]:";
    	cin>>cho;
    }
}
void Set_events() {
	int choice = 0;    
	cout<<"			#####################################"<<endl;
    cout<<"			####       Set Main Events!      ####"<<endl;
    cout<<"			#####################################"<<endl;
    cout<<"			####                             ####"<<endl;
    cout<<"			####     1、Set dog's events.    ####"<<endl;
    cout<<"			####                             ####"<<endl;
    cout<<"			####     2、Set cat's events.    ####"<<endl;
    cout<<"			####                             ####"<<endl;
    cout<<"			#####################################"<<endl;
    cout<<endl;
    cout<<"			         >>>";
    cin>>choice;
    if(choice == 1) dog->set_dog_love();
    else if (choice == 2) cat->set_cat_love();
}
