#include "Parse.h"
#include <fstream>
#include <iostream>
using namespace std;

extern "C" int lex(const char *fsource);

int main()
{
	char fname[20];
	cout<<"源文件:";
	cin>>fname;

	//词法分析
	if(lex(fname)){
		return -1;
	}

	ifstream ifs("temp.file");
	if(!ifs){
		cout<<"open file failure"<<endl;
	}

	//语法分析
	Parse parse(ifs);
	try{
		parse.Start();
		cout<<"语法、语义分析及代码生成结束!"<<endl;
		parse.WriteCode("code.tm");
	}catch(const char *errmsg){
		cout<<"**语法分析错误 : "<<errmsg<<" at:  "<<token.token<<"  "<<token.token1<<endl;
	}
    return 0;
}
