#include <QtGui/QApplication>
#include <QTextCodec>
#include "words.h"
#include "login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    Words learn;
    if(learn.getislogin()) {
    	learn.show();
    } else {
    	return 0;
    }
    return a.exec();
}
