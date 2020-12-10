#include "logic.h"
#include <QDebug>

Logic::Logic(MainWindow* mainWindow, QObject *parent) : QObject(parent)
{
    giveMainWindow(mainWindow);
    connectWithMainWindow();
    start();

}

Logic::~Logic()
{

}


void Logic::giveMainWindow(MainWindow *mainWindow)
{
    mainWindow_ = mainWindow;
}

void Logic::start()
{
    mainWindow_->show();
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(update()));
    timer_->start(1);
    player_ = new Player(0, 10);
    mainWindow_->getPlayer(player_);
}
void Logic::draw()
{
    mainWindow_->drawMap(Map(1), 0);
    mainWindow_->drawPlayer();
}

void Logic::movePlayer(QString direction)
{
   if (direction == "up")
   {
       player_->move(0, -1);
   }

   if (direction == "down")
   {
       player_->move(0, 1);
   }

   if (direction == "left")
   {
       player_->move(-1, 0);
   }

   if (direction == "right")
   {
       player_->move(1, 0);
   }
   qDebug() << player_->giveX() << player_->giveY();
}

void Logic::playerMoveUp()
{
    movePlayer("up");
}

void Logic::playerMoveDown()
{
    movePlayer("down");
}

void Logic::playerMoveLeft()
{
    movePlayer("left");
}

void Logic::playerMoveRight()
{
    movePlayer("right");
}
void Logic::connectWithMainWindow()
{
    connect(mainWindow_, SIGNAL(playerMoveUp()), this, SLOT(playerMoveUp()));
    connect(mainWindow_, SIGNAL(playerMoveDown()), this, SLOT(playerMoveDown()));
    connect(mainWindow_, SIGNAL(playerMoveLeft()), this, SLOT(playerMoveLeft()));
    connect(mainWindow_, SIGNAL(playerMoveRight()), this, SLOT(playerMoveRight()));

}

void Logic::update()
{
    mainWindow_->clear();
    draw();
}


