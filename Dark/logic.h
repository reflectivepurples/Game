#ifndef LOGIC_H
#define LOGIC_H
#include "mainwindow.h"

#include <QString>
#include <QMainWindow>
#include <QTimer>
class Logic : public QObject
{
    Q_OBJECT
public:
    Logic(MainWindow* mainWindow, QObject *parent = 0);
    ~Logic();

    void giveMainWindow(MainWindow* mainWindow);
    void start();
    void draw();
    void movePlayer(QString direction);
    void connectWithMainWindow();

public slots:
    void update();

    void playerMoveUp();
    void playerMoveDown();
    void playerMoveLeft();
    void playerMoveRight();
private:
    MainWindow* mainWindow_;
    QTimer* timer_;
    Player* player_;

    int mapPos = 0;
};

#endif // LOGIC_H
