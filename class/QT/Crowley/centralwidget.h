
#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QtGui>

class CentralWidget: public QWidget {
  Q_OBJECT

  private:
    QPushButton* cardDeckButton;
    QLabel* boardLabel;
    QPixmap* cardFaceDown;
    QPixmap* cardFaceUp;
    bool isFaceDown;

  private slots:
    void drawCard();
  
 public:
    CentralWidget();

};

#endif
