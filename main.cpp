#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //just plays the game
    //implementation done in minesweeper and in the window class
    QApplication a(argc, argv);
   //  Q_INIT_RESOURCE(graphlib);
    MainWindow w;
    w.show();

    return a.exec();
}
