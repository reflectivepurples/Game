#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "map.h"
#include "player.h"

#include <QMainWindow>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void drawMap(Map map, int pos);
    void drawPlayer();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* mapScene_;
    Player* player_;

};
#endif // MAINWINDOW_H
