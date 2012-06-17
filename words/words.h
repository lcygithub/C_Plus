#ifndef WORDS_H
#define WORDS_H

#include <QMainWindow>

namespace Ui {
    class Words;
}

class Words : public QMainWindow
{
    Q_OBJECT

public:
    explicit Words(QWidget *parent = 0);
    ~Words();
    bool getislogin() { return islogin; }
    bool getisshowlogin() { return isshowlogin; }
private:
    Ui::Words *ui;
    bool islogin;
    bool isshowlogin;
};

#endif // WORDS_H
