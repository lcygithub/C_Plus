#include "words.h"
#include "ui_words.h"
#include "login.h"
#include <iostream>
using namespace std;
Words::Words(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Words)
{
	Login user;
	user.exec();
	cout<<user.getlogin()<<endl;
	if(user.getlogin()) {
		islogin = true;
		ui->setupUi(this);
	} else {
		islogin = false;
	}
}

Words::~Words()
{
    delete ui;
}
