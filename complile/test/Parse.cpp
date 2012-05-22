#include "Parse.h"
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;

Token token;

Parse::Parse(ifstream &f):fin(f)
{
    labelp=0;
    bool_sym[ConstStr(">")] = "GT";bool_sym[ConstStr(">=")] = "GE";
    bool_sym[ConstStr("<")] = "LES";bool_sym[ConstStr("<=")] = "LE";
    bool_sym[ConstStr("==")] = "EQ";bool_sym[ConstStr("!=")] = "NOTEQ";
}

void Parse::WriteCode(const char *fname)
{
    FILE *fout = fopen(fname,"w");
    if(!fout){
        throw "open file failure!";
    }else{
        fwrite(rd.getrst(),rd.size(),1,fout);
        fclose(fout);
    }
}

void Parse::Start()
{
	/*
		语法分析
	*/
	next();
    program();
}

void Parse::next(bool mark)
{
	/*
		读取下一个
	*/
	if(mark){
		pre_mark = fin.tellg();
	}
	if(fin.eof()){
		throw 0;
	}
    fin>>token;
}

bool Parse::program()
{
	if(token != "{"){
		//缺少{
		throw "missing `{`";
	}

	next();
	declaration_list();//声明表
	printf("%s list dprogram \n",token.token);
	cout<<symbols<<endl;
	statement_list();//语句表

    rd<<"STOP"<<ENDL;
    return true;
}

bool Parse::declaration_list()
{
	//分析声明表
	printf("%s declaration_list",token.token);
	while(token == "int"){
		next();
		declaration_stat();
	}
    return true;
}

bool Parse::declaration_stat()
{
	//声明语句
	printf("%s declaration_stat\n",token.token);
	if(token != "ID"){
		throw "missing ID";
	}

	next();

	if(token != ";"){
		throw "missing `;`";
	}
	if(symbols.add(token.old1) == -1){
	    static char buf[100];
	    token.back();
	    sprintf(buf,"redefine `%s`",token.token1);
	    throw (const char*)buf;
	}
	printf(" declaration_stat \n");
	next();
    return true;
}

bool Parse::statement_list()
{
	//语句表
	while(token != "}"){
		//next();
		printf("statement_list \n");
		statement();
	}
	next();
    return true;
}

bool Parse::statement()
{
	//语句
	if_stat()||while_stat()||do_while_stat()||for_stat()||read_stat()||
		write_stat()||compound_stat()||expression_stat();
    return true;
}

bool Parse::if_stat()
{
	//if语句
	if(token != "if"){
		return false;
	}

	next();
	if(token != "("){
		throw "missing `(`";
	}
	next();
	expression();
	if(token != ")"){
		throw "missing `)`";
	}
	int label1 = newlabel();
	rd<<"BRF LABEL"<<label1<<ENDL;
	
	next();
	statement();
	
	if(token == "else"){
		int label2 = newlabel();
	    rd<<"BR LABEL"<<label2<<ENDL;
	    rd<<"LABEL"<<label1<<ENDL;
	    next();
		statement();
		rd<<"LABEL"<<label2<<ENDL;
	}else{
	    rd<<"LABEL"<<label1<<ENDL;
	}
	
    return true;
}

bool Parse::while_stat()
{
	//while语句
	if(token != "while"){
		return false;
	}
	next();

	if(token != "("){
		throw "missing `(`";
	}
	next();
    
    int label1 = newlabel();
    rd<<"LABEL"<<label1<<ENDL;
    
	expression();
	if(token != ")"){
		throw "missing `)`";
	}
	next();
    
    int label2 = newlabel();
    rd<<"BRF LABEL"<<label2<<ENDL;

	statement();
	rd<<"BR LABEL"<<label1<<ENDL;
    
    rd<<"LABEL"<<label2<<ENDL;
    return true;
}

bool Parse::do_while_stat()
{
	//do while语句
    if(token != "do"){
		return false;
	}
	next();

	if(token != "{"){
		throw "missing `{`";
	}
	next();
    
    int label1 = newlabel();
    rd<<"LABEL"<<label1<<ENDL;
    while(token != "}") {
    	statement();
    }
    next();
    if(token != "while"){
		throw "missing `while`";
	}
	next();
    if(token != "("){
		throw "missing `(`";
	}
	next();
	expression();
    if(token != ")"){
		throw "missing `)`";
	}
	next();
	if(token != ";"){
		throw "missing `;`";
	}
	int label2 = newlabel();
    rd<<"BRF LABEL"<<label2<<ENDL;
    rd<<"BR LABEL"<<label1<<ENDL;
    rd<<"LABEL"<<label2<<ENDL;
	return 0;
}
bool Parse::for_stat()
{
	//for语句
	if(token != "for"){
		return false;
	}
	next();

	if(token != "("){
		throw "missing `(`";
	}
	next();

    int label_cmp = newlabel(),label_step = newlabel(),
        label_for = newlabel(),label_next = newlabel();
    //init
	expression();
	if(token != ";"){
		throw "missing `;`";
	}
	next();

    //cmp
    rd<<"LABEL"<<label_cmp<<ENDL;
	expression();
	if(token != ";"){
		throw "missing `;`";
	}
	next();
	rd<<"BRF LABEL"<<label_next<<ENDL;
	rd<<"BR LABEL"<<label_for<<ENDL;

    //step
    rd<<"LABEL"<<label_step<<ENDL;
	expression();
	rd<<"BR LABEL"<<label_cmp<<ENDL;

	if(token != ")"){
		throw "missing `)`";
	}
	next();

    rd<<"LABEL"<<label_for<<ENDL;
	statement();
	rd<<"BR LABEL"<<label_step<<ENDL;
	rd<<"LABEL"<<label_next<<ENDL;
    return true;
}

bool Parse::write_stat()
{
	//write语句
	if(token != "write"){
		return false;
	}
	next();
	expression();
	if(token != ";"){
		throw "missing `;`";
	}
	rd<<"OUT"<<ENDL;
	next();
    return true;
}

bool Parse::read_stat()
{
	//read语句
    if(token != "read"){
		return false;
	}
	next();
	if(token != "ID"){
		throw "missing `ID`";
	}
	int addr = symbols.find(token.token1);
	if(addr == -1){
	    static char buf[100];
	    sprintf(buf,"undefined symbol : `%s`",token.token1);
	    throw buf;
	}
	next();
	rd<<"IN"<<ENDL;
	rd<<"STI "<<addr<<ENDL;
	
	if(token != ";"){
		throw "missing `;`";
	}
	next();
    return true;
}

bool Parse::compound_stat()
{
    if(token != "{"){
        return false;
    }
    next();
	return statement_list();
}

bool Parse::expression_stat()
{
	//表达式语句
	printf(" expression_stat \n");
	if(token == ";"){
		next();
	}else{
		printf(" into expression \n");
		expression();
		if(token != ";"){
			throw "missing `;`";
		}
		next();
	}
    return true;
}

bool Parse::expression()
{
	//表达式
	printf("in expression token : %s \n",token.token);
	if(token == "ID"){
		Token tmp;
		strcpy(tmp.token,token.token);
		strcpy(tmp.token1,token.token1);
		next(true);
        
		if(token == "="){
		    int addr = symbols.find(token.old1);
		    if(addr==-1){
		        static char buf[100];
	            sprintf(buf,"undefined symbol : `%s`",token.token1);
	            throw buf;
		    }
			next();
			bool_expr();
			rd<<"STO "<<addr<<ENDL;
		}else{
			fin.seekg(pre_mark);
			strcpy(token.token,tmp.token);
			strcpy(token.token1,tmp.token1);
			bool_expr();
		}
	}else{
		printf("in bool_expr \n");
		bool_expr();
	}
    return true;
}

bool Parse::bool_expr()
{
	//bool表达式
	printf("bool_expr \n");
	additive_expr();
    map<ConstStr,const char*>::iterator iter;
    iter = bool_sym.find(ConstStr(token.token));    
	if(iter != bool_sym.end()){
		next();
		additive_expr();
		rd<<iter->second<<ENDL;
	}
    return true;
}

bool Parse::additive_expr()
{
	//算术表达式
	printf("additive_expr \n");
	term();
	while(token == "+" || token == "-"){
	    char m = token.token[0];
		next();
		term();
		if(m == '+'){
		    rd<<"ADD"<<ENDL;
		}else{
		    rd<<"SUB"<<ENDL;
		}
	}
    return true;
}

bool Parse::term()
{
	//项
	printf("term \n");
	factor();
	while(token == "*" || token == "/" || token.token[0] == '%'){
	    char back = token.token[0];
		next();
		factor();
		if(back == '*'){
		    rd<<"MULT"<<ENDL;
		}else if(back == '/'){
		    rd<<"DIV"<<ENDL;
		}else{
			rd<<"MOD"<<ENDL;
		}
	}
    return true;
}

bool Parse::factor()
{
	//因子
	printf("factor \n");
	if(token == "("){
		printf("from factor into expression \n");
		next();
		expression();
		if(token != ")"){
			throw "missing `)`";
		}
	}else{
		if(token == "ID"){
		    int addr = symbols.find(token.token1);
		    if(addr == -1){
		        static char buf[100];
	            sprintf(buf,"undefined symbol : `%s`",token.token1);
	            throw buf;
		    }
		    rd<<"LOAD "<<addr<<ENDL;
		}else if(token == "NUM"){
		    rd<<"LOADI "<<token.token1<<ENDL;
		}else{
			throw "missing operator";
		}
	}
	
	next();
    return true;
}