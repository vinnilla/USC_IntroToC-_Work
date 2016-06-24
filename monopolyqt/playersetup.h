//playersetup.h
#include <QtGui>

#ifndef PLAYERSETUP_H
#define PLAYERSETUP_H

#include <QPushButton>
#include <QGridLayout>

class PlayerSetup : public QWidget {
  Q_OBJECT

  protected:
  	QLabel* blank;
  	QLabel *question;

  	QPixmap* heartpic;
    QPushButton *heart;
    QPixmap* pawpic;
    QPushButton *paw;
    QPixmap* sunpic;
    QPushButton *sun;
    QPixmap* targetpic;
    QPushButton *target;
    QPixmap* swordpic;
    QPushButton *sword;
    QPixmap* yingyangpic;
    QPushButton *yingyang;

    QGridLayout *layout;
    int Players;
    int currentPlayer;

    private slots:
	void hideAll();
    void heartAct();
    void pawAct();
    void sunAct();
    void targetAct();
    void swordAct();
    void yingyangAct();
    void setPlayers();


  public:
    PlayerSetup ();  
};

#endif