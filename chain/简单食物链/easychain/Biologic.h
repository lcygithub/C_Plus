#ifndef BIOLOGIC_H
#define BIOLOGIC_H
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class Biologic {
    public:
        Biologic();
        /*
        Interface function:
        */
        Biologic& operator++ ();
        Biologic operator++ (int);
        void set_age(int a) { age += a; }
        void set_newage(int a) { age = a; }
        void set_postion() { position = rand() % 50 + 50; }
        void set_postion(int p) { position = p; }
        void set_deadline(int d) { deadline = d; }
        int get_age() const { return age ;}
        int get_position() const { return position; }
        int get_deadline() const { return deadline; }
    protected:
        int age;       //age default age = 0
        int position;  //position
        int deadline;  //deadline
};
class Grass : public Biologic {  // public inheritance
    public:
        Grass();
        Grass(const Grass &a);
        static int get_count() { return count; }
        static void set_count(int c) { count += c; }
    private:
        static int count;
};
class Hare : public Biologic {  // public inheritance
    public:
        Hare();
        Hare(const Hare &hare);
        void set_gender(string g);
        string get_gender() { return gender; }
        static int get_count() { return count; }
        static void set_count(int c) { count += c; }
    private:
        static int count;
        string gender;          // gender female & male
};
class Fox : public Biologic {  // public inheritance
    public:
        Fox();
        Fox(const Fox &fox);
        void set_gender(string g);
        string get_gender() { return gender; }
        static int get_count() { return count; }
        static void set_count(int c) { count += c; }
    private:
        static int count;
        string gender;
};
class Wolf : public Biologic {  // public inheritance
    public:
        Wolf();
        Wolf(const Wolf &wolf);
        void set_gender(string g);
        string get_gender() { return gender; }
        static int get_count() { return count; }
        static void set_count(int c) { count += c; }
    private:
        static int count;
        string gender;
};
#endif
