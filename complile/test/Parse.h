#ifndef PARSE_H
#define PARSE_H

#include "Symbol.h"
#include <fstream>
#include <cstring>
#include <map>
#include <string>
using namespace std;

struct ConstStr{
    const char *str;
    int __val;
    ConstStr(const char *str){
        this->str = str;
        __val=1;
        for(int i=0;str[i];i++){
            __val*=str[i];
        }
    }
    bool operator==(const ConstStr &cstr) const{
        return strcmp(str,cstr.str)==0;
    }
    bool operator<(const ConstStr &cstr) const{
        return __val<cstr.__val;
    }
};

struct Token {
    char token[10],token1[10];
    char old[10],old1[10];
    friend ifstream & operator >>(ifstream &fin, Token &t){
        memcpy(t.old,t.token,10);
        memcpy(t.old1,t.token1,10);
        fin>>t.token>>t.token1;
        return fin;
    }
	bool operator==(const char *str) const{
		if(strcmp(str,token) == 0){
			return true;
		}else{
			return false;
		}
	}
	bool operator!=(const char *str) const{
		return !operator==(str);
	}
	void back(){
	    memcpy(token,old,10);
        memcpy(token1,old1,10);
	}
};

#define ENDL "\n"
class Record{
public:
    Record& operator<<(int i){
        static char num[20];
        cout<<i;
        sprintf(num,"%d",i);
        rst+=num;
        return *this;
    }
    Record& operator<<(const char *str){
        cout<<str;
        rst+=str;
        return *this;
    }
    const char* getrst(){
        return rst.c_str();
    }
    int size(){
        return rst.size();
    }
private:
    string rst;
};

extern Token token;

class Parse {
    public:
        Parse(ifstream &fin);
        void Start();
        void WriteCode(const char *fname);
    private:
        void next(bool mark = false);
        bool program();
        bool declaration_list();
        bool declaration_stat();
        bool statement_list();
        bool statement();
        bool if_stat();
        bool while_stat();
        bool do_while_stat();
        bool for_stat();
        bool write_stat();
        bool read_stat();
        bool compound_stat();
        bool expression_stat();
        bool expression();
        bool bool_expr();
        bool additive_expr();
        bool term();
        bool factor();
    private:
		ifstream &fin;
		unsigned int pre_mark;
        SymbolTable symbols;
        map<ConstStr,const char*> bool_sym;
        int labelp;
        
        int newlabel(){
            return labelp++;
        }
        Record rd;
};

#endif