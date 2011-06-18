#include "paddle.h"

Paddle::Paddle() :
        Penjin::Sprite()
{
    load("img/paddle.png");
}

void Paddle::moveLeft()
{
    position.x -= 3.0;
}

void Paddle::moveRight()
{
    position.x += 3.0;
}
