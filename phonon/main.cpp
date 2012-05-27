
 #include <QtGui>
 #include "mediaplayer.h"

 int main (int argc, char *argv[])
 {
     //Q_INIT_RESOURCE(mediaplayer);
     QApplication app(argc, argv);
     app.setApplicationName("Media Player");
     app.setOrganizationName("Qt");
     app.setQuitOnLastWindowClosed(true);

     bool hasSmallScreen = false;

     QString fileString;
     const QStringList args(app.arguments());
     /* We have a minor problem here, we accept two arguments, both are
      * optional:
      * - A file name
      * - the option "-small-screen", so let's try to cope with that.
      */
    for (int i = 0; i < args.count(); ++i) {
        const QString &at = args.at(i);

        if (at == QLatin1String("-small-screen"))
            hasSmallScreen = true;
        else if (i > 0) // We don't want the app name.
            fileString = at;
    }

    MediaPlayer player(fileString, hasSmallScreen);
    player.show();

     return app.exec();
 }
