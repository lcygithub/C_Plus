#include <vector>
#include <string>
#include "Chain.h"
#include <iostream>
using namespace std;
int main() {
    int key;
    cout<<"1.use file data  2.input data by hand"<<endl;
    cin>>key;
    if(key == 1) {
        vector<Grass> *grass = new vector<Grass>;
        vector<Hare> *hare = new vector<Hare>;
        vector<Fox> *fox = new vector<Fox>;
        vector<Wolf> *wolf = new vector<Wolf>;
        Chain *chain = new Chain(grass,hare,fox,wolf);
        chain->Create_Chain(grass,hare,fox,wolf);
        chain->Run_Chain(grass,hare,fox,wolf,chain->get_time());
        chain->Stop_Chain(grass,hare,fox,wolf);
        delete grass;
        delete hare;
        delete fox;
        delete wolf;
    } else {
        Chain *chain = new Chain;
        vector<Grass> *grass = new vector<Grass>(chain->get_gcount());
        vector<Hare> *hare = new vector<Hare>(chain->get_hcount());
        vector<Fox> *fox = new vector<Fox>(chain->get_fcount());
        vector<Wolf> *wolf = new vector<Wolf>(chain->get_wcount());
        chain->Create_Chain(grass,hare,fox,wolf);
        chain->Run_Chain(grass,hare,fox,wolf,chain->get_time());
        chain->Stop_Chain(grass,hare,fox,wolf);
        delete grass;
        delete hare;
        delete fox;
        delete wolf;
    }
    return 0;
}

