#include "login.h"
#include "user.h"
#include <QtGui>
#include <iostream>
using namespace std;
Login::Login(QWidget* parent) : QDialog(parent) {
    //label 用来写出 “用户名：“和”密码:"
    usrLabel = new QLabel(tr("用户名："));
    pwdLabel = new QLabel(tr("密  码："));
    //LineEdit 用来填写 用户名和密码
    usrLineEdit = new QLineEdit;
    pwdLineEdit = new QLineEdit;
    //用 setEchoMode 来设置 Line 的显示格式
    /*
        The echo mode determines how the text entered in the line edit
        is displayed (or echoed) to the user.
        
        Constant	Value	Description
        QLineEdit::Normal	0	Display characters as they are entered. This is the default.
        QLineEdit::NoEcho	1	Do not display anything. This may be appropriate for passwords where even the length of the password should be kept secret.
        QLineEdit::Password	2	Display asterisks instead of the characters actually entered.
        QLineEdit::PasswordEchoOnEdit	3	Display characters as they are entered while editing otherwise display asterisks.
    */
    pwdLineEdit->setEchoMode(QLineEdit::Password);
    //设置按钮
    okBtn = new QPushButton(tr("登录"));
    clBtn = new QPushButton(tr("退出"));
    rgBtn = new QPushButton(tr("注册"));
    okBtn->setDefault(1);
    //布局 把各个部件放进去
    /*
	setSpacing（int）是个虚函数，用于设置loyout内部构件之间间距。
	setMargin ( int ) 也是虚函数，用于设置layout边框的宽度。
    */
    // GridLayout 把 用户名的label 和 editline 放进去
    msgLayout = new QGridLayout;
    msgLayout->addWidget(usrLabel,0,0,1,1);
    msgLayout->addWidget(usrLineEdit,0,1,1,2);
    msgLayout->addWidget(pwdLabel,1,0,1,1);
    msgLayout->addWidget(pwdLineEdit,1,1,1,2);

    //HBoxLayout 把各个按钮加入布局
    btnLayout = new QHBoxLayout;
    //btnLayout->setMargin(40);
    btnLayout->setSpacing(30);
    btnLayout->addWidget(clBtn);
    btnLayout->addWidget(okBtn);
    btnLayout->addWidget(rgBtn);

    //VBoxLayout 
    mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(40);
    mainLayout->addLayout(msgLayout);
    mainLayout->addStretch(40);
    mainLayout->addLayout(btnLayout);
    setLayout(mainLayout);
    cout<<"mainLayout"<<endl;
    //signal slot
    connect(okBtn,SIGNAL(clicked()),this,SLOT(accept()));
    connect(clBtn,SIGNAL(clicked()),this,SLOT(cancel()));
}
Login::~Login() {
	delete usrLabel;
	delete pwdLabel;
	delete usrLineEdit; 
	delete pwdLineEdit;
	// three buttons for ok cancel and register
	delete okBtn;
	delete clBtn;
	delete rgBtn;
	//QGridLayouts
	delete msgLayout;
	//HBoxLayout
	delete btnLayout;
	//VBoxLayout
	delete mainLayout;
}
void Login::accept() {
    if(usrLineEdit->text().trimmed() == tr("lcy") &&
            pwdLineEdit->text() == tr("123")) {
                isLogin = true;
                cout<<isLogin<<endl;
                emit close();
                //QDialog::accept();
	}
	else {
        isLogin = false;
        cout<<isLogin<<endl;
		QMessageBox::warning(this,
		tr("警告"),
		tr("用户或密码错误！"),
		QMessageBox::Yes);
		usrLineEdit->setFocus();
	}
}
void Login::cancel() {
    isLogin = false;
    emit close();
    cout<<"close"<<endl;
}