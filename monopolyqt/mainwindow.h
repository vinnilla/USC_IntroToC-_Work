//mainwindow.h

#include <QtGui>

#include "guiplayer.h"

#include <QGridLayout>
#include <QPushButton>

class CentralWidget;

class MainWindow : public QWidget {
	Q_OBJECT

	private:
	int numPlayers;

	Player* players[4];
	GUIPlayer* guiPlayers[4];

	CentralWidget* centralWidget;

	QGridLayout* layout;
	
	QGridLayout* startmenu;
	QLabel* question;
	QPushButton* two;
	QPushButton* three;
	QPushButton* four;


	QGridLayout* playersetup;
	int setupcounter;
	QLabel* setupMenuQ;
	QLabel* setupMenuPlayer;
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

    QGridLayout* taxQuestion;
    QLabel* taxQ;
    QPushButton* percent;
    QPushButton* straightup;

	private slots:
	void hideStartMenu();
	void twoAct();
	void threeAct();
	void fourAct();

	void hidePlayerSetupMenu();
	void heartAct();
    void pawAct();
    void sunAct();
    void targetAct();
    void swordAct();
    void yingyangAct();

	public:
	MainWindow();
	void StartMenu();
	void PlayerSetupMenu();
	void TaxQuestion();
	void showtaxQuestion();
	void hidetaxQuestion();
	void changePlayerGui(int);
	void updatePlayerGui(int);
};