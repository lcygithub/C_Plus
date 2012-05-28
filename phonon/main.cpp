
 #include <QtGui>
 #include "mediaplayer.h"
 int main (int argc, char *argv[])
 {
     QApplication app(argc, argv);
     app.setApplicationName("Media Player");
     app.setOrganizationName("Qt");
     app.setQuitOnLastWindowClosed(true);

     bool hasSmallScreen = false;

     QString fileString;
     const QStringList args(app.arguments());
    for (int i = 0; i < args.count(); ++i) {
        const QString &at = args.at(i);

        if (at == QLatin1String("-small-screen"))
            hasSmallScreen = true;
        else if (i > 0) 
            fileString = at;
    }

    MediaPlayer player(fileString, hasSmallScreen);
    player.show();

     return app.exec();
 }
