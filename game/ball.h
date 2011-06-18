#ifndef BALL_H
#define BALL_H

#include "Sprite.h"

class Ball : public Penjin::Sprite
{
public:
    Ball();

    void update();
    void setDirection(Penjin::Vector2d<float> const& newDirection);
    Penjin::Vector2d<float> const& getVelocity() const;

private:
    Penjin::Vector2d<float> velocity;
    float speed;
};

#endif
