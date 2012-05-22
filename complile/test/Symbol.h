#ifndef __LO_SYMBOL_HEADER
#define __LO_SYMBOL_HEADER

#include <map>
#include <iostream>
#include <string>
using namespace std;

class SymbolTable{
public:
    int find(char* name);
    int add(char *name);
    SymbolTable();
    ~SymbolTable();
    friend ostream& operator<<(ostream &out,const SymbolTable &self){
        out<<"符号表"<<endl<<"名字"<<"\t地址"<<endl;
        map<string,int>::const_iterator iter;
        for(iter=self.table.begin();iter!=self.table.end();iter++){
            out<<iter->first<<"\t"<<iter->second<<endl;
        }
        return out;
    }
private:
    std::map<string,int> table;
    int addr;
};

#endif
