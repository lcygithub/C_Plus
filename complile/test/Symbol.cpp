#include "Symbol.h"
#include <cstring>

int SymbolTable::find(char* name)
{
    map<string,int>::iterator iter;
    iter = table.find(string(name));
    
    if(iter!=table.end()){
        return iter->second;
    }else{
        return -1;
    }
}

int SymbolTable::add(char *name)
{
    if(table.find(string(name)) != table.end()){
        return -1;
    }else{
        table[string(name)] = addr;
        return addr++;
    }
}

SymbolTable::SymbolTable()
{
    addr = 0;
}

SymbolTable::~SymbolTable(){
}
















