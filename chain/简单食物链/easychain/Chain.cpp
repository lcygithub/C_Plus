#include "Chain.h"
#include "Biologic.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
//#include <unistd.h>
#include <fstream>
using namespace std;
Chain::Chain() {
    for(int i = 0;i<100;i++) {
        grass_position[i] = 0;
        hare_position[i] = 0;
        fox_position[i] = 0;
        wolf_position[i] = 0;
    }
    int count = 0;
    cout<<"\t>>>Please input the number of Grass:";
    cin>>count;
    grass_count = count;
    Grass::set_count(count);
    cout<<"\t>>>Please input the number of Hare:";
    cin>>count;
    hare_count = count;
    Hare::set_count(count);
    cout<<"\t>>>Please input the number of Fox:";
    cin>>count;
    fox_count = count;
    Fox::set_count(count);
    cout<<"\t>>>Please input the number of Wolf:";
    cin>>count;
    wolf_count = count;
    Wolf::set_count(count);
    cout<<"\t>>>please input the chain's runtime:";
    cin>>count;
    timer = count;
    cout<<"\t>>>Grass: "<<Grass::get_count()<<endl;
    cout<<"\t>>>Hare: "<<Hare::get_count()<<endl;
    cout<<"\t>>>Fox: "<<Fox::get_count()<<endl;
    cout<<"\t>>>Wolf: "<<Wolf::get_count()<<endl;
    srand(time(0));
}
Chain::Chain(vector<Grass> *grass,
             vector<Hare> *hare,
             vector<Fox> *fox,
             vector<Wolf> *wolf) {
    ifstream out;
    char buffer[100];
    //grass
    out.open("grass",ios::in);
    out.getline(buffer,100,'\n');
    Grass::set_count(atoi(buffer));
    int i = atoi(buffer);
    while(i--) {
        out.getline(buffer,100,'\n');
        Grass *newgrass = new Grass;
        newgrass->set_newage(atoi(buffer));
        out.getline(buffer,100,'\n');
        newgrass->set_postion(atoi(buffer));
        out.getline(buffer,100,'\n');
        newgrass->set_deadline(atoi(buffer));
        grass->push_back(*newgrass);
        delete newgrass;
    }
    out.close();
    //hare
    out.open("hare",ios::in);
    out.getline(buffer,100,'\n');
    Hare::set_count(atoi(buffer));
    i = atoi(buffer);
    while(i--) {
        out.getline(buffer,100,'\n');
        Hare *newhare = new Hare;
        newhare->set_newage(atoi(buffer));
        out.getline(buffer,100,'\n');
        newhare->set_postion(atoi(buffer));
        out.getline(buffer,100,'\n');
        newhare->set_deadline(atoi(buffer));
        hare->push_back(*newhare);
        delete newhare;
    }
    out.close();
    //fox
    out.open("fox",ios::in);
    out.getline(buffer,100,'\n');
    Fox::set_count(atoi(buffer));
    i = atoi(buffer);
    while(i--) {
        out.getline(buffer,100,'\n');
        Fox *newfox = new Fox;
        newfox->set_newage(atoi(buffer));
        out.getline(buffer,100,'\n');
        newfox->set_postion(atoi(buffer));
        out.getline(buffer,100,'\n');
        newfox->set_deadline(atoi(buffer));
        fox->push_back(*newfox);
        delete newfox;
    }
    out.close();
    //wolf
    out.open("wolf",ios::in);
    out.getline(buffer,100,'\n');
    Wolf::set_count(atoi(buffer));
    i = atoi(buffer);
    while(i--) {
        out.getline(buffer,100,'\n');
        Wolf *newwolf = new Wolf;
        newwolf->set_newage(atoi(buffer));
        out.getline(buffer,100,'\n');
        newwolf->set_postion(atoi(buffer));
        out.getline(buffer,100,'\n');
        newwolf->set_deadline(atoi(buffer));
        wolf->push_back(*newwolf);
        delete newwolf;
    }
    out.close();
    cout<<"\t>>>please input the chain's runtime:";
    cin>>i; // i means timer
    timer = i;
}
void Chain::Create_Chain(vector<Grass> *grass,
                        vector<Hare> *hare,
                        vector<Fox> *fox,
                        vector<Wolf> *wolf) {
    int count = 0;
    cout<<endl<<"Creating data,Wait..."<<endl<<endl;
    sleep(2);
    for(vector<Grass>::iterator iter1 = grass->begin();iter1 != grass->end();++iter1) {
        count++;
        cout<<"The "<<count<<"th grass has been created!"<<endl;
        grass_position[(*iter1).get_position()] += 1;
        cout<<"\t>>>age:"<<(*iter1).get_age()<<endl;
        cout<<"\t>>>position:"<<(*iter1).get_position()<<endl;
        cout<<"\t>>>deadline:"<<(*iter1).get_deadline()<<endl;
    }
    cout<<"\t>>>The number of grasses:"<<Grass::get_count()<<endl<<endl;
    count = 0;
    cout<<endl<<"Creating data,Wait..."<<endl<<endl;
    sleep(2);
    for(vector<Hare>::iterator iter2 = hare->begin();iter2 != hare->end();++iter2) {
        count ++;
        cout<<"The "<<count<<"th hare has been created!"<<endl;
        hare_position[(*iter2).get_position()] += 1;
        cout<<"\t>>>age:"<<(*iter2).get_age()<<endl;
        cout<<"\t>>>gender:"<<(*iter2).get_gender()<<endl;
        cout<<"\t>>>position:"<<(*iter2).get_position()<<endl;
        cout<<"\t>>>deadline:"<<(*iter2).get_deadline()<<endl;
    }
    cout<<"\t>>>The number of hares:"<<Hare::get_count()<<endl<<endl;
    count = 0;
    cout<<endl<<"Creating data,Wait..."<<endl<<endl;
    sleep(2); 
    for(vector<Fox>::iterator iter3 = fox->begin();iter3 != fox->end();++iter3) {
        count ++;
        cout<<"The "<<count<<"th fox has been created!"<<endl;
        fox_position[(*iter3).get_position()] += 1;
        cout<<"\t>>>age:"<<(*iter3).get_age()<<endl;
        cout<<"\t>>>gender:"<<(*iter3).get_gender()<<endl;
        cout<<"\t>>>position:"<<(*iter3).get_position()<<endl;
        cout<<"\t>>>deadline:"<<(*iter3).get_deadline()<<endl;
    }
    cout<<"\t>>>The number of foxs:"<<Fox::get_count()<<endl<<endl;
    count = 0;
    cout<<endl<<"Creating data,Wait..."<<endl<<endl;
    sleep(2);
    for(vector<Wolf>::iterator iter4 = wolf->begin();iter4 != wolf->end();++iter4) {
        count ++;
        cout<<"The "<<count<<"th wolf has been created!"<<endl;
        wolf_position[(*iter4).get_position()] += 1;
        cout<<"\t>>>age:"<<(*iter4).get_age()<<endl;
        cout<<"\t>>>gender:"<<(*iter4).get_gender()<<endl;
        cout<<"\t>>>position:"<<(*iter4).get_position()<<endl;
        cout<<"\t>>>deadline:"<<(*iter4).get_deadline()<<endl;
    }
    cout<<"\t>>>The number of wolves:"<<Wolf::get_count()<<endl;
    cout<<endl<<"Create finished!"<<endl<<endl;
}
void Chain::Run_Chain(vector<Grass> *grass,vector<Hare> *hare,vector<Fox> *fox,vector<Wolf> *wolf,int time) {
    int total_time =  time;
    cout<<"      >>>>>>>>>RUNING THE CHAIN!<<<<<<"<<endl;
    sleep(1);
    int current_time = 1;
    while(total_time) {    
        sleep(1);
    /*grass*/ 
        // dead if age >= dead
        for(vector<Grass>::iterator iter = grass->begin();iter != grass->end();) {
            if((*iter).get_age() >= (*iter).get_deadline()) {
                grass_position[(*iter).get_position()] = 0;
                grass->erase(iter);
                Grass::set_count(-1);
                cout<<"\t>>>When "<<current_time<<"s a grass dead!"<<endl;
            } else {
                ++iter;
            }
        }
        // birth 1/sec
        Grass *newgrass = new Grass;
        Grass::set_count(1);
        newgrass->set_newage(0);
        grass->push_back(*newgrass);
        grass_position[newgrass->get_position()] += 1;
        cout<<"\t>>>When "<<current_time<<"s a grass birth!"<<endl;
        delete newgrass;
        // position dead
        for(vector<Grass>::iterator iter = grass->begin();iter != grass->end();) {
            if(hare_position[(*iter).get_position()] != 0) {
                grass->erase(iter);
                Grass::set_count(-1);
            } else {
                ++iter;
            }
        }
        // age ++ 1/sec
        for(vector<Grass>::iterator iter = grass->begin();iter != grass->end();++iter) {
            (*iter)++;
        }
        cout<<"\t>>>grass total count:"<<Grass::get_count()<<endl<<endl;
    /*end grass*/
    /*hare*/
        // dead if age >= dead
        for(vector<Hare>::iterator iter = hare->begin();iter != hare->end();) {
            if((*iter).get_age() >= (*iter).get_deadline()) {
                hare_position[(*iter).get_position()] = 0;
                hare->erase(iter);
                Hare::set_count(-1);
                cout<<"\t>>>When "<<current_time<<"s a hare dead!"<<endl;
               // cout<<"\t>>>hare age dead count: "<<Hare::get_count()<<endl;
            } else {
                ++iter;
            }
        }
        // birth 1/sec
        Hare *newhare = new Hare;
        Hare::set_count(1);
        newhare->set_newage(0);
        hare->push_back(*newhare);
        hare_position[newhare->get_position()] += 1;
        cout<<"\t>>>When "<<current_time<<"s a hare birth!"<<endl;
        delete newhare;
        // position dead
        for(vector<Hare>::iterator iter = hare->begin();iter != hare->end();) {
            hare_position[(*iter).get_position()] -= 1;
            (*iter).set_postion();
            hare_position[(*iter).get_position()] += 1;
            if(fox_position[(*iter).get_position()] != 0) {
                hare->erase(iter);
                Hare::set_count(-1);
                cout<<"\t>>>When "<<current_time<<"s a hare was ate by a fox!"<<endl;
            } else {
                ++iter;
            }
        }
        // age ++ 1/sec
        for(vector<Hare>::iterator iter = hare->begin();iter != hare->end();++iter) {
            (*iter)++;
        }
        cout<<"\t>>>hare total count:"<<Hare::get_count()<<endl<<endl;
    /*end hare*/
    /*fox*/
        // dead if age >= dead
        for(vector<Fox>::iterator iter = fox->begin();iter != fox->end();) {
            if((*iter).get_age() >= (*iter).get_deadline()) {
                wolf_position[(*iter).get_position()] = 0;
                fox->erase(iter);
                Fox::set_count(-1);
                cout<<"\t>>>When "<<current_time<<"s a fox was dead!"<<endl;
            } else {
                ++iter;
            }
        }
        // birth 1/sec
        Fox *newfox = new Fox;
        Fox::set_count(1);
        newfox->set_newage(0);
        fox->push_back(*newfox);
        fox_position[newfox->get_position()] += 1;
        cout<<"\t>>>When "<<current_time<<"s a fox was birth!"<<endl;
        delete newfox;
        // position dead
        for(vector<Fox>::iterator iter = fox->begin();iter != fox->end();) {
            fox_position[(*iter).get_position()] -= 1;
            (*iter).set_postion();
            fox_position[(*iter).get_position()] += 1;
            if(wolf_position[(*iter).get_position()] != 0) {
                fox->erase(iter);
                Fox::set_count(-1);
                cout<<"\t>>>When "<<current_time<<"s a fox was ate by a wolf!"<<endl;
            } else {
                ++iter;
            }
        }
        // age ++ 1/sec
        for(vector<Fox>::iterator iter = fox->begin();iter != fox->end();++iter) {
            (*iter)++;
        }
        cout<<"\t>>>fox total count:"<<Fox::get_count()<<endl<<endl;
    /*end fox*/
    /*wolf*/      
        // dead if age >= dead
        for(vector<Wolf>::iterator iter = wolf->begin();iter != wolf->end();) {
            if((*iter).get_age() >= (*iter).get_deadline()) {
                wolf_position[(*iter).get_position()] = 0;
                wolf->erase(iter);
                Wolf::set_count(-1);
                cout<<"\t>>>When "<<current_time<<"s a wolf dead!"<<endl;
            } else {
                ++iter;
            }
        }
        // birth 1/sec
        Wolf *newwolf = new Wolf;
        Wolf::set_count(1);
        newwolf->set_newage(0);
        wolf->push_back(*newwolf);
        wolf_position[newwolf->get_position()] += 1;
        cout<<"\t>>>When "<<current_time<<"s a wolf birth!"<<endl;
        delete newwolf;
        // age ++ 1/sec
        for(vector<Wolf>::iterator iter = wolf->begin();iter != wolf->end();++iter) {
            (*iter)++;
        }
        cout<<"\t>>>wolf total count:"<<Wolf::get_count()<<endl<<endl;
    /*end wolf*/
        total_time--;
        current_time ++;
    }
}

void Chain::Stop_Chain(vector<Grass> *grass,
                        vector<Hare> *hare,
                        vector<Fox> *fox,
                        vector<Wolf> *wolf) {
    cout<<"\t>>>Time out the chain stoped<<<<<<"<<endl;
    cout<<"\t>>>Grass: "<<Grass::get_count()<<endl;
    cout<<"\t>>>Hare: "<<Hare::get_count()<<endl;
    cout<<"\t>>>Fox: "<<Fox::get_count()<<endl;
    cout<<"\t>>>Wolf: "<<Wolf::get_count()<<endl<<endl;
    ofstream in;
    ifstream out;
    //grass
    in.open("grass",ios::trunc);
    in<<Grass::get_count()<<endl;
    for(vector<Grass>::iterator iter = grass->begin();iter != grass->end();++iter) {
        in<<(*iter).get_age()<<endl;
        in<<(*iter).get_position()<<endl;
        in<<(*iter).get_deadline()<<endl;
    }
    cout<<">>>Grass's date was saved in file 'grass'"<<endl;
    in.close();
    //hare
    in.open("hare",ios::trunc);
    in<<Hare::get_count()<<endl;
    for(vector<Hare>::iterator iter = hare->begin();iter != hare->end();++iter) {
        in<<(*iter).get_age()<<endl;
        in<<(*iter).get_position()<<endl;
        in<<(*iter).get_deadline()<<endl;
    }
    cout<<">>>Hare's date was saved in file 'hare'"<<endl;
    in.close();
    //fox
    in.open("fox",ios::trunc);
    in<<Fox::get_count()<<endl;
    for(vector<Fox>::iterator iter = fox->begin();iter != fox->end();++iter) {
        in<<(*iter).get_age()<<endl;
        in<<(*iter).get_position()<<endl;
        in<<(*iter).get_deadline()<<endl;
    }
    cout<<">>>Fox's date was saved in file 'fox'"<<endl;
    in.close();
    //wolf
    in.open("wolf",ios::trunc);
    in<<Wolf::get_count()<<endl;
    for(vector<Wolf>::iterator iter = wolf->begin();iter != wolf->end();++iter) {
        in<<(*iter).get_age()<<endl;
        in<<(*iter).get_position()<<endl;
        in<<(*iter).get_deadline()<<endl;
    }
    cout<<">>>Wolf's date was saved in file 'wolf'"<<endl;
    in.close();
}
