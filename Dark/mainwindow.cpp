#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QDebug>

const int MAP_HEIGHT = 12; // BLOCKS
const int MAP_WIDTH = 16;

const int BLOCK_SIZE = 50; // PX

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gameView->setFixedSize(802, 602);

    mapScene_ = new QGraphicsScene(this);
    mapScene_->setSceneRect(0, 0, 800, 600);
    ui->gameView->setScene(mapScene_);

    //player_ = new Player(0, 10);
    //ui->gameView->fitInView(0, 0, 24.123, 24.123, Qt::KeepAspectRatio);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getPlayer(Player *player)
{
    player_ = player;
}

void MainWindow::drawMap(Map map, int pos)
{
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        QString line(map.giveLevelLayout()->at(i));

        for (int j = 0 + pos; j < MAP_WIDTH + pos; j++)
        {
            QChar c = line.at(j);

            if (c == "#")
            {
                QPen pen;
                pen.setBrush(Qt::black);
                QBrush brush;
                brush.setStyle(Qt::SolidPattern);

                mapScene_->addRect(j * BLOCK_SIZE, i * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, pen, brush);
            }
            else if (c == ".")
            {
                //mapScene_->addRect(j * BLOCK_SIZE, i * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
            }
        }
    }
}

void MainWindow::drawPlayer()
{
    int x = player_->giveX();
    int y = player_->giveY();
    mapScene_->addRect(x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);

}
void MainWindow::clear()
{
    mapScene_->clear();
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if (gameStarted_)
    {

        if (event->key() == Qt::Key_W)
        {
            emit playerMoveUp();
        }
        
        if (event->key() == Qt::Key_S)
        {
            emit playerMoveDown();
        }
        
        if (event->key() == Qt::Key_A)
        {
            emit playerMoveLeft();
        }
        
        if (event->key() == Qt::Key_D)
        {

            emit playerMoveRight();
            qDebug() << "key pressed";
        }

    }
    

}

