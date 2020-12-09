#ifndef PLAYER_H
#define PLAYER_H
#include "dynamic.h"


class Player : public Dynamic
{
public:
    Player(int x, int y);
    ~Player();

    // Dynamic interface
public:
    int giveX() const;
    int giveY() const;
    void move(int x, int y);
    bool isRemoved() const;
    void remove();
private:
    int x_;
    int y_;
};

#endif // PLAYER_H
