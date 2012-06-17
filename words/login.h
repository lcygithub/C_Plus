#ifndef LOGIN_H
#define LOGIN_H
#include <QLineEdit>
#include <QtGui>
class Login : public QDialog {
	Q_OBJECT
public:
	//构造函数的声明,QWidget是它的顶级父类
	Login(QWidget* = 0);
	virtual ~Login();
	bool getlogin() { return isLogin; }
public slots:
	//从新声明基类QDialog的虚函数accept(),在cpp文件中将重写此函数
	virtual void accept();
	void cancel();
private:
        //isLogin
    bool isLogin;
	//user & pwd 
	QLabel* usrLabel;
	QLabel* pwdLabel;
        QLineEdit* usrLineEdit;
	QLineEdit* pwdLineEdit;
	// three buttons for ok cancel and register
	QPushButton* okBtn;
	QPushButton* clBtn;
	QPushButton* rgBtn;
	//QGridLayouts
	QGridLayout* msgLayout;
	//HBoxLayout
	QHBoxLayout* btnLayout;
	//VBoxLayout
	QVBoxLayout* mainLayout;
};
#endif // LOGIN_H
