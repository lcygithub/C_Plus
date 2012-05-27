#include <QtGui>
#include <QTranslator>
#include "mainwindow.h"
int main(int argv, char **args)
{
    QApplication app(argv, args);
    QTranslator translator;
    translator.load("GBK");
    app.installTranslator(&translator);
    app.setApplicationName("Music Player");
    app.setQuitOnLastWindowClosed(true);
    MainWindow window;
    window.show();

    return app.exec();
}
