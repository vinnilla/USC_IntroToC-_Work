//menu.cpp
#include "menu.h"
#include <QVBoxLayout>
#include <QFont>

Menu::Menu( Player* p[]) : QWidget() {
	roll = new QPushButton(tr("Roll Die"));
	roll -> setFont(QFont("Times", 12, QFont::Bold));

	upgrade = new QPushButton(tr("Upgrade"));
	upgrade -> setFont(QFont("Times", 12, QFont::Bold));

	resign = new QPushButton(tr("Resign"));
	resign -> setFont(QFont("Times", 12, QFont::Bold));

	end = new QPushButton(tr("End Turn"));
	end -> setFont(QFont("Times", 12, QFont::Bold));

	QVBoxLayout *layout = new QVBoxLayout;
	layout -> addWidget (roll);
	layout -> addWidget (upgrade);
	layout -> addWidget (end);
	layout -> addWidget (resign);
	setLayout (layout);

}
