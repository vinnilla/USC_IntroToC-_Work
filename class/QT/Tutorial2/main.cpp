#include <QApplication>
 #include <QFont>
 #include <QPushButton>

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);

     QPushButton quit("Quit\nPlease");
     //quit.resize(500, 300);
     quit.setFont(QFont("Times", 100, QFont::Bold));

     QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

     quit.show();
     return app.exec();
 }