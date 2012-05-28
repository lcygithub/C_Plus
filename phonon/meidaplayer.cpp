 #include <QtGui>
 #include "mediaplayer.h"
 #define SLIDER_RANGE 8

 MediaVideoWidget::MediaVideoWidget(MediaPlayer *player, QWidget *parent) :
     Phonon::VideoWidget(parent), m_player(player), m_action(this)
 {
     m_action.setCheckable(true);
     m_action.setChecked(false);
     m_action.setShortcut(QKeySequence( Qt::AltModifier + Qt::Key_Return));
     m_action.setShortcutContext(Qt::WindowShortcut);
     connect(&m_action, SIGNAL(toggled(bool)), SLOT(setFullScreen(bool)));
     addAction(&m_action);
     setAcceptDrops(true);
 }

 void MediaVideoWidget::setFullScreen(bool enabled)
 {
     Phonon::VideoWidget::setFullScreen(enabled);
     emit fullScreenChanged(enabled);
 }

 void MediaVideoWidget::mouseDoubleClickEvent(QMouseEvent *e)
 {
     Phonon::VideoWidget::mouseDoubleClickEvent(e);
     setFullScreen(!isFullScreen());
 }

 void MediaVideoWidget::timerEvent(QTimerEvent *e)
 {
    /*
     if (e->timerId() == m_timer.timerId()) {
         //let's store the cursor shape
 #ifndef QT_NO_CURSOR
         setCursor(Qt::BlankCursor);
 #endif
     }
    */

     Phonon::VideoWidget::timerEvent(e);
 }

 MediaPlayer::MediaPlayer(const QString &filePath,
                          const bool hasSmallScreen) :
             playButton(0), 
             m_AudioOutput(Phonon::VideoCategory),
             m_videoWidget(new MediaVideoWidget(this)),
             m_hasSmallScreen(hasSmallScreen)
 {
     setWindowTitle(tr("Lcyang's Media Player"));

     QSize buttonSize(34, 28);
     
     QPushButton *openButton = new QPushButton(this);
     openButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));

     rewindButton = new QPushButton(this);
     rewindButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));

     forwardButton = new QPushButton(this);
     forwardButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
     forwardButton->setEnabled(false);

     playButton = new QPushButton(this);
     playIcon = style()->standardIcon(QStyle::SP_MediaPlay);
     pauseIcon = style()->standardIcon(QStyle::SP_MediaPause);
     playButton->setIcon(playIcon);

     slider = new Phonon::SeekSlider(this);
     slider->setMediaObject(&m_MediaObject);
     volume = new Phonon::VolumeSlider(&m_AudioOutput);
    /*right layout*/
    QStringList headers;
    headers << tr("Title") << tr("Artist") << tr("Album") << tr("Year");

    musicTable = new QTableWidget(0, 4);
    musicTable->setHorizontalHeaderLabels(headers);
    musicTable->setSelectionMode(QAbstractItemView::SingleSelection);
    musicTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    //connect(musicTable, SIGNAL(cellDoubleClicked(int,int)),
    //        this, SLOT(tableClicked(int,int)));
    QVBoxLayout *upLayout = new QVBoxLayout;
    upLayout->addWidget(musicTable);

    /*up layout*/
     QVBoxLayout *vLayout = new QVBoxLayout(this);
     vLayout->setContentsMargins(8,8,8,8);

     /*dowm layout*/
     QHBoxLayout *layout = new QHBoxLayout();
    
     info = new QLabel(this);
     info->setMinimumHeight(70);
     info->setAcceptDrops(false);
     info->setMargin(2);
     info->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
     info->setLineWidth(2);
     info->setAutoFillBackground(true);
     QPalette palette;
     palette.setBrush(QPalette::WindowText, Qt::black);
     info->setStyleSheet("border-image:url(:/images/screen.png) ; border-width:3px");
     info->setText(tr("<center>No media</center>"));
     info->setPalette(palette);

     volume->setFixedWidth(120);

     layout->addWidget(openButton);
     layout->addWidget(rewindButton);
     layout->addWidget(playButton);
     layout->addWidget(forwardButton);
     layout->addStretch();
     layout->addWidget(volume);

     vLayout->addWidget(info);
     initVideoWindow();
     vLayout->addWidget(&m_videoWindow);
     QVBoxLayout *buttonPanelLayout = new QVBoxLayout();
     m_videoWindow.hide();
     buttonPanelLayout->addLayout(layout);

     timeLabel = new QLabel(this);
     progressLabel = new QLabel(this);
     QWidget *sliderPanel = new QWidget(this);
     QHBoxLayout *sliderLayout = new QHBoxLayout();
     sliderLayout->addWidget(slider);
     sliderLayout->addWidget(timeLabel);
     sliderLayout->addWidget(progressLabel);
     sliderLayout->setContentsMargins(0, 0, 0, 0);
     sliderPanel->setLayout(sliderLayout);

     buttonPanelLayout->addWidget(sliderPanel);
     buttonPanelLayout->setContentsMargins(0, 0, 0, 0);
     QWidget *buttonPanelWidget = new QWidget(this);
     //buttonPanelWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
     buttonPanelWidget->setLayout(buttonPanelLayout);
     
     QWidget *musicLable = new QWidget(this);
     musicLable->setLayout(upLayout);

     vLayout->addWidget(buttonPanelWidget,0,0);
     vLayout->addWidget(musicLable,1,0);
     setLayout(vLayout);
     setMinimumSize(450,400);

     // Create menu bar:
     fileMenu = new QMenu(this);
     QAction *openFileAction = fileMenu->addAction(tr("Open &File..."));
     QAction *openUrlAction = fileMenu->addAction(tr("Open &Location..."));

     fileMenu->addSeparator();
     /*fullscreenaction*/
     m_fullScreenAction = fileMenu->addAction(tr("Full screen video"));
     m_fullScreenAction->setCheckable(true);
     m_fullScreenAction->setEnabled(false); // enabled by hasVideoChanged
     bool b = connect(m_fullScreenAction, SIGNAL(toggled(bool)), m_videoWidget, SLOT(setFullScreen(bool)));
     Q_ASSERT(b);
     b = connect(m_videoWidget, SIGNAL(fullScreenChanged(bool)), m_fullScreenAction, SLOT(setChecked(bool)));
     Q_ASSERT(b);
     // Setup signal connections:
     connect(rewindButton, SIGNAL(clicked()), this, SLOT(rewind()));
     openButton->setMenu(fileMenu);

     connect(playButton, SIGNAL(clicked()), this, SLOT(playPause()));
     connect(forwardButton, SIGNAL(clicked()), this, SLOT(forward()));
     connect(openUrlAction, SIGNAL(triggered(bool)), this, SLOT(openUrl()));
     connect(openFileAction, SIGNAL(triggered(bool)), this, SLOT(openFile()));
     connect(&m_MediaObject, SIGNAL(metaDataChanged()), this, SLOT(updateInfo()));
     connect(&m_MediaObject, SIGNAL(totalTimeChanged(qint64)), this, SLOT(updateTime()));
     connect(&m_MediaObject, SIGNAL(tick(qint64)), this, SLOT(updateTime()));
     connect(&m_MediaObject, SIGNAL(finished()), this, SLOT(finished()));
     connect(&m_MediaObject, SIGNAL(stateChanged(Phonon::State,Phonon::State)), this, SLOT(stateChanged(Phonon::State,Phonon::State)));
     connect(&m_MediaObject, SIGNAL(hasVideoChanged(bool)), this, SLOT(hasVideoChanged(bool)));

     rewindButton->setEnabled(false);
     playButton->setEnabled(false);
     //setAcceptDrops(true);

     m_audioOutputPath = Phonon::createPath(&m_MediaObject, &m_AudioOutput);
     Phonon::createPath(&m_MediaObject, m_videoWidget);

     if (!filePath.isEmpty())
         setFile(filePath);
     resize(minimumSizeHint());
 }
 void MediaPlayer::stateChanged(Phonon::State newstate, Phonon::State oldstate)
 {
//     Q_UNUSED(oldstate);

     if (oldstate == Phonon::LoadingState) {
         QRect videoHintRect = QRect(QPoint(0, 0), m_videoWindow.sizeHint());
         QRect newVideoRect = QApplication::desktop()->screenGeometry().intersected(videoHintRect);
         if (!m_hasSmallScreen) {
             if (m_MediaObject.hasVideo()) {
                 // Flush event que so that sizeHint takes the
                 // recently shown/hidden m_videoWindow into account:
                 qApp->processEvents();
                 resize(sizeHint());
             } else
                 resize(minimumSize());
         }
     }

     switch (newstate) {
         case Phonon::ErrorState:
             if (m_MediaObject.errorType() == Phonon::FatalError) {
                 playButton->setEnabled(false);
                 rewindButton->setEnabled(false);
             } else {
                 m_MediaObject.pause();
             }
             QMessageBox::warning(this, "Phonon Mediaplayer", m_MediaObject.errorString(), QMessageBox::Close);
             break;

         case Phonon::StoppedState:
             m_videoWidget->setFullScreen(false);
             // Fall through
         case Phonon::PausedState:
             playButton->setIcon(playIcon);
             if (m_MediaObject.currentSource().type() != Phonon::MediaSource::Invalid){
                 playButton->setEnabled(true);
                 rewindButton->setEnabled(true);
             } else {
                 playButton->setEnabled(false);
                 rewindButton->setEnabled(false);
             }
             break;
         case Phonon::PlayingState:
             playButton->setEnabled(true);
             playButton->setIcon(pauseIcon);
             if (m_MediaObject.hasVideo())
                 m_videoWindow.show();
             // Fall through
         case Phonon::BufferingState:
             rewindButton->setEnabled(true);
             break;
         case Phonon::LoadingState:
             rewindButton->setEnabled(false);
             break;
     }

 }
 void MediaPlayer::initVideoWindow()
 {
     QVBoxLayout *videoLayout = new QVBoxLayout();
     videoLayout->addWidget(m_videoWidget);
     videoLayout->setContentsMargins(0, 0, 0, 0);
     m_videoWindow.setLayout(videoLayout);
     m_videoWindow.setMinimumSize(100, 100);
 }
 void MediaPlayer::playPause()
 {
     if (m_MediaObject.state() == Phonon::PlayingState)
         m_MediaObject.pause();
     else {
         if (m_MediaObject.currentTime() == m_MediaObject.totalTime())
             m_MediaObject.seek(0);
         m_MediaObject.play();
     }
 }
 void MediaPlayer::setFile(const QString &fileName)
 {
     setWindowTitle(fileName.right(fileName.length() - fileName.lastIndexOf('/') - 1));
     m_MediaObject.setCurrentSource(Phonon::MediaSource(fileName));
     m_MediaObject.play();
 }
 void MediaPlayer::setLocation(const QString& location)
 {
     setWindowTitle(location.right(location.length() - location.lastIndexOf('/') - 1));
     m_MediaObject.setCurrentSource(Phonon::MediaSource(QUrl::fromEncoded(location.toUtf8())));
     m_MediaObject.play();
 }
 bool MediaPlayer::playPauseForDialog()
 {
     // If we're running on a small screen, we want to pause the video when
     // popping up dialogs. We neither want to tamper with the state if the
     // user has paused.
     if (m_hasSmallScreen && m_MediaObject.hasVideo()) {
         if (Phonon::PlayingState == m_MediaObject.state()) {
             m_MediaObject.pause();
             return true;
         }
     }
     return false;
 }
 void MediaPlayer::openFile()
 {
     const bool hasPausedForDialog = playPauseForDialog();

     fileNames = QFileDialog::getOpenFileNames(this, QString(),
                                                           QDesktopServices::storageLocation(QDesktopServices::MusicLocation));

     if (hasPausedForDialog)
         m_MediaObject.play();

     m_MediaObject.clearQueue();
     if (fileNames.size() > 0) {
         QString fileName = fileNames[0];
         setFile(fileName);
         for (int i=1; i<fileNames.size(); i++)
             m_MediaObject.enqueue(Phonon::MediaSource(fileNames[i]));
     }
     forwardButton->setEnabled(m_MediaObject.queue().size() > 0);
 }
 void MediaPlayer::updateInfo()
 {
     int maxLength = 30;
     QString font = "<font color=black>";
     QString fontmono = "<font family=\"monospace,courier new\" color=black>";

     QMap <QString, QString> metaData = m_MediaObject.metaData();
     QString trackArtist = metaData.value("ARTIST");
     if (trackArtist.length() > maxLength)
         trackArtist = trackArtist.left(maxLength) + "...";

     QString trackTitle = metaData.value("TITLE");
     int trackBitrate = metaData.value("BITRATE").toInt();


     QString fileName;
     if (m_MediaObject.currentSource().type() == Phonon::MediaSource::Url) {
         fileName = m_MediaObject.currentSource().url().toString();
     } else {
         fileName = m_MediaObject.currentSource().fileName();
         fileName = fileName.right(fileName.length() - fileName.lastIndexOf('/') - 1);
         if (fileName.length() > maxLength)
             fileName = fileName.left(maxLength) + "...";
     }

     QString title;
     if (!trackTitle.isEmpty()) {
         if (trackTitle.length() > maxLength)
             trackTitle = trackTitle.left(maxLength) + "...";
         title = "Title: " + font + trackTitle + "<br></font>";
     } else if (!fileName.isEmpty()) {
         if (fileName.length() > maxLength)
             fileName = fileName.left(maxLength) + "...";
         title = font + fileName + "</font>";
         if (m_MediaObject.currentSource().type() == Phonon::MediaSource::Url) {
             title.prepend("Url: ");
         } else {
             title.prepend("File: ");
         }
     }

     QString artist;
     if (!trackArtist.isEmpty())
         artist = "Artist:  " + font + trackArtist + "</font>";

     QString bitrate;
     if (trackBitrate != 0)
         bitrate = "<br>Bitrate:  " + font + QString::number(trackBitrate/1000) + "kbit</font>";

     info->setText(title + artist + bitrate);
 }
 void MediaPlayer::updateTime()
 {
     long len = m_MediaObject.totalTime();
     long pos = m_MediaObject.currentTime();
     QString timeString;
     if (pos || len)
     {
         int sec = pos/1000;
         int min = sec/60;
         int hour = min/60;
         int msec = pos;

         QTime playTime(hour%60, min%60, sec%60, msec%1000);
         sec = len / 1000;
         min = sec / 60;
         hour = min / 60;
         msec = len;

         QTime stopTime(hour%60, min%60, sec%60, msec%1000);
         QString timeFormat = "m:ss";
         if (hour > 0)
             timeFormat = "h:mm:ss";
         timeString = playTime.toString(timeFormat);
         if (len)
             timeString += " / " + stopTime.toString(timeFormat);
     }
     timeLabel->setText(timeString);
 }
 void MediaPlayer::rewind()
 {
     m_MediaObject.seek(0);
 }
 void MediaPlayer::forward()
 {
     QList<Phonon::MediaSource> queue = m_MediaObject.queue();
     if (queue.size() > 0) {
         m_MediaObject.setCurrentSource(queue[0]);
         forwardButton->setEnabled(queue.size() > 1);
         m_MediaObject.play();
     }
 }
 void MediaPlayer::openUrl()
 {
     QSettings settings;
     settings.beginGroup(QLatin1String("BrowserMainWindow"));
     QString sourceURL = settings.value("location").toString();
     bool ok = false;
     sourceURL = QInputDialog::getText(this, tr("Open Location"), tr("Please enter a valid address here:"), QLineEdit::Normal, sourceURL, &ok);
     if (ok && !sourceURL.isEmpty()) {
         setLocation(sourceURL);
         settings.setValue("location", sourceURL);
     }
 }
 void MediaPlayer::finished()
 {
 }
 void MediaPlayer::hasVideoChanged(bool bHasVideo)
 {
     info->setVisible(!bHasVideo);
     m_videoWindow.setVisible(bHasVideo);
     m_fullScreenAction->setEnabled(bHasVideo);
 }
