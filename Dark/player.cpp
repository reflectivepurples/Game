#include "player.h"

Player::Player(int x, int y)
{
    x_ = x;
    y_ = y;
}

Player::~Player()
{

}

int Player::giveX() const
{
    return x_;
}

int Player::giveY() const
{
    return y_;
}

void Player::move(int x, int y)
{
    x_ += x;
    y_ += y;
}

bool Player::isRemoved() const
{
    return true;
}

void Player::remove()
{
    isRemoved();
}
