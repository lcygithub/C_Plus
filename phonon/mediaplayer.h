 #ifndef MEDIALAYER_H
 #define MEDIAPLAYER_H

 #include <QtGui/QWidget>
 #include <QtGui/QApplication>
 #include <QtCore/QTimerEvent>
 #include <QtGui/QShowEvent>
 #include <QtGui/QIcon>
 #include <QtCore/QBasicTimer>
 #include <QtGui/QAction>

 #include <phonon/audiooutput.h>
 #include <phonon/backendcapabilities.h>
 #include <phonon/effect.h>
 #include <phonon/effectparameter.h>
 #include <phonon/effectwidget.h>
 #include <phonon/mediaobject.h>
 #include <phonon/seekslider.h>
 #include <phonon/videowidget.h>
 #include <phonon/volumeslider.h>

 class QPushButton;
 class QLabel;
 class QSlider;
 class QTextEdit;
 class QMenu;
 class Ui_settings;

 class MediaPlayer;

 class MediaVideoWidget : public Phonon::VideoWidget
 {
     Q_OBJECT

 public:
     MediaVideoWidget(MediaPlayer *player, QWidget *parent = 0);

 public slots:
     // Over-riding non-virtual Phonon::VideoWidget slot
     void setFullScreen(bool);

 signals:
     void fullScreenChanged(bool);

 protected:
     void mouseDoubleClickEvent(QMouseEvent *e);
     void keyPressEvent(QKeyEvent *e);
     bool event(QEvent *e);
     void timerEvent(QTimerEvent *e);
     void dropEvent(QDropEvent *e);
     void dragEnterEvent(QDragEnterEvent *e);

 private:
     MediaPlayer *m_player;
     QBasicTimer m_timer;
     QAction m_action;
 };

 class MediaPlayer :
             public QWidget
 {
     Q_OBJECT
 public:
     MediaPlayer(const QString &,
                 const bool hasSmallScreen);

     void dragEnterEvent(QDragEnterEvent *e);
     void dragMoveEvent(QDragMoveEvent *e);
     void dropEvent(QDropEvent *e);
     void handleDrop(QDropEvent *e);
     void setFile(const QString &text);
     void setLocation(const QString &location);
     void initVideoWindow();
     //void initSettingsDialog();

 public slots:
     void openFile();
     void rewind();
     void forward();
     void updateInfo();
     void updateTime();
     void finished();
     void playPause();


 private slots:

     void stateChanged(Phonon::State newstate, Phonon::State oldstate);

     void openUrl();

     void hasVideoChanged(bool);

 private:
     bool playPauseForDialog();

     QIcon playIcon;
     QIcon pauseIcon;
     QMenu *fileMenu;
     QPushButton *playButton;
     QPushButton *rewindButton;
     QPushButton *forwardButton;
     Phonon::SeekSlider *slider;
     QLabel *timeLabel;
     QLabel *progressLabel;
     Phonon::VolumeSlider *volume;
     QSlider *m_hueSlider;
     QSlider *m_satSlider;
     QSlider *m_contSlider;
     QLabel *info;
     Phonon::Effect *nextEffect;
     QDialog *settingsDialog;
     Ui_settings *ui;
     QAction *m_fullScreenAction;

     QWidget m_videoWindow;
     Phonon::MediaObject m_MediaObject;
     Phonon::AudioOutput m_AudioOutput;
     MediaVideoWidget *m_videoWidget;
     Phonon::Path m_audioOutputPath;
     const bool m_hasSmallScreen;
 };

 #endif //MEDIAPLAYER_H
