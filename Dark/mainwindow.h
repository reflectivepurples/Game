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

    void getPlayer(Player* player);
    void drawMap(Map map, int pos);
    void drawPlayer();
    void clear();
signals:
    void playerMoveUp();
    void playerMoveDown();
    void playerMoveLeft();
    void playerMoveRight();
private slots:
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::MainWindow *ui;
    QGraphicsScene* mapScene_;
    Player* player_;
    bool gameStarted_ = true;

};
#endif // MAINWINDOW_H
