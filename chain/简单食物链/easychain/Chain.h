#ifndef CHAIN_H
#define CHAIN_H
#include "Biologic.h"
#include <vector>
class Chain {
    public:
        Chain();
        Chain(vector<Grass> *grass,
                        vector<Hare> *hare,
                        vector<Fox> *fox,
                        vector<Wolf> *wolf);
        void Create_Chain(vector<Grass> *grass,
                        vector<Hare> *hare,
                        vector<Fox> *fox,
                        vector<Wolf> *wolf);
        void Run_Chain(vector<Grass> *grass,
                        vector<Hare> *hare,
                        vector<Fox> *fox,
                        vector<Wolf> *wolf,
                        int time);
        void Stop_Chain(vector<Grass> *grass,
                        vector<Hare> *hare,
                        vector<Fox> *fox,
                        vector<Wolf> *wolf);
        int get_gcount() { return grass_count;}
        int get_hcount() { return hare_count; }
        int get_fcount() { return fox_count;  }
        int get_wcount() { return wolf_count; }
        int get_time() { return timer; }
    private:
        int timer;                //total runtime 
        int grass_count;          //grass static count
        int hare_count;           //hare static count
        int fox_count;            //fox static count
        int wolf_count;           //wolf static count
        /*every second position*/
        int grass_position[100];  
        int hare_position[100];
        int fox_position[100];
        int wolf_position[100];
};
#endif
