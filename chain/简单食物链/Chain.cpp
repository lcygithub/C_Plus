#include "Chain.h"
#include "Biologic.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
Chain::Chain() {
    int count = 0;
    cout<<"Please input the number of Grass:";
    cin>>count;
    Grass::set_count(count);
    srand(time(0));
    vector<Grass> grass(count);
    vector<Hare> hare(count);
    vector<Fox> fox(count);
    vector<Wolf> wolf(count);
    cout<<endl<<"Creating data,Wait..."<<endl;
    sleep(2);
    
    for(vector<Grass>::iterator iter = grass.begin();iter != grass.end();++iter) {
        cout<<"age:"<<(*iter).get_age()<<endl;
        cout<<"position:"<<(*iter).get_position()<<endl;
        cout<<"deadline:"<<(*iter).get_deadline()<<endl;
        cout<<"count:"<<(*iter).get_count()<<endl;
    }
    cout<<endl<<"Creating data,Wait..."<<endl;
    sleep(2);
    
    for(vector<Hare>::iterator iter = hare.begin();iter != hare.end();++iter) {
        cout<<"age:"<<(*iter).get_age()<<endl;
        cout<<"gender:"<<(*iter).get_gender()<<endl;
        cout<<"position:"<<(*iter).get_position()<<endl;
        cout<<"deadline:"<<(*iter).get_deadline()<<endl;
        cout<<"count:"<<(*iter).get_count()<<endl;
    }
    cout<<endl<<"Creating data,Wait..."<<endl;
    sleep(2);
    for(vector<Fox>::iterator iter = fox.begin();iter != fox.end();++iter) {
        cout<<"age:"<<(*iter).get_age()<<endl;
        cout<<"gender:"<<(*iter).get_gender()<<endl;
        cout<<"position:"<<(*iter).get_position()<<endl;
        cout<<"deadline:"<<(*iter).get_deadline()<<endl;
        cout<<"count:"<<(*iter).get_count()<<endl;
    }
    cout<<endl<<"Creating data,Wait..."<<endl;
    sleep(2);
    for(vector<Wolf>::iterator iter = wolf.begin();iter != wolf.end();++iter) {
        cout<<"age:"<<(*iter).get_age()<<endl;
        cout<<"gender:"<<(*iter).get_gender()<<endl;
        cout<<"position:"<<(*iter).get_position()<<endl;
        cout<<"deadline:"<<(*iter).get_deadline()<<endl;
        cout<<"count:"<<(*iter).get_count()<<endl;
    }
    wolf.erase (wolf.begin(),wolf.end());
    if(wolf.begin() == wolf.end()){
        cout<<"delete"<<endl;

    }
    cout<<endl<<"Finished!"<<endl;
}
