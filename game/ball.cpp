#include "ball.h"

Ball::Ball() :
        Penjin::Sprite(),
        velocity(1.0, 1.0), speed(1.0)
{
    load("img/ball.png");
}

void Ball::update()
{
    position += velocity;
    speed += 0.001;
}

void Ball::setDirection(Penjin::Vector2d<float> const& newDirection)
{
    velocity = newDirection;
    velocity = velocity.unit();
    velocity *= speed;
}

Penjin::Vector2d<float> const& Ball::getVelocity() const
{
    return velocity;
}
