#include "mainwindow.h"
#include "map.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Map level_1(1);
    w.drawMap(level_1, 0);
    w.drawPlayer();


    return a.exec();
}
