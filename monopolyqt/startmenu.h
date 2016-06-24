//startmenu.h
#include <QtGui>

#ifndef STARTMENU_H
#define STARTMENU_H

#include <QPushButton>
#include <QGridLayout>

class StartMenu : public QWidget {
  Q_OBJECT

  protected:
  	QLabel* blank;
  	QLabel *question;
    QPushButton *two;
    QPushButton *three;
    QPushButton *four;
    QGridLayout *layout;
    int Players;

    private slots:
	  void hideAll();
    void twoAct();
    void threeAct();
    void fourAct();


  public:
    StartMenu ();  
    int returnPlayers();
};

#endif