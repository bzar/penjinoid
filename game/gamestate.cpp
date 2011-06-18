#include "gamestate.h"
#include <iostream>

GameState::GameState() :
        Penjin::ApplicationState(),
        paddle(), ball(), bricks()
{

}

GameState::~GameState()
{

}

void GameState::init()
{
    paddle.setPosition(168, 216);
    ball.setPosition(184, 140);

    for(int y = 0; y < 6; ++y) {
        for(int x = 0; x < 10; ++x) {
            Brick* brick = new Brick();
            brick->setPosition(x*40, y*16);
            bricks.push_back(brick);
        }
    }
}

void GameState::render()
{
    Penjin::GFX::getInstance()->clear();
    paddle.render();
    ball.render();
    for(std::vector<Brick*>::iterator i = bricks.begin(); i != bricks.end(); ++i)
    {
        (*i)->render();
    }
}

void GameState::update()
{
    paddle.update();
    ball.update();

    Penjin::CollisionRegion* paddleCollisionRegion = paddle.getCollisionRegion();
    Penjin::CollisionRegion* ballCollisionRegion = ball.getCollisionRegion();
    Penjin::CollisionInfo ballPaddleCollision = ballCollisionRegion->hitTest(paddleCollisionRegion, true);

    Penjin::Vector2d<float> newDirection = ball.getVelocity();

    if(ballPaddleCollision.hasCollided)
    {
        newDirection.setX(((ball.getPosition().x + ball.getWidth()/2) - (paddle.getPosition().x + paddle.getWidth()/2))/10.0);
        newDirection.setY(-1.0);
    }

    if((ballCollisionRegion->hitTest(0, ball.getPosition().y, true) && newDirection.x < 0) ||
       (ballCollisionRegion->hitTest(Penjin::GFX::getInstance()->getWidth(), ball.getPosition().y, true) && newDirection.x > 0))
    {
        newDirection.setX(-newDirection.x);
    }
    if(ballCollisionRegion->hitTest(ball.getPosition().x, 0, true) && newDirection.y < 0)
    {
        newDirection.setY(-newDirection.y);
    }

    if(ballCollisionRegion->hitTest(ball.getPosition().x, Penjin::GFX::getInstance()->getHeight(), true) && newDirection.y > 0)
    {
           std::cout << "You lose!" << endl;
           shouldQuit = true;
    }

    for(std::vector<Brick*>::iterator i = bricks.begin(); i != bricks.end(); ++i)
    {
        Penjin::CollisionRegion* brickCollisionRegion = (*i)->getCollisionRegion();
        Penjin::CollisionInfo ballBrickCollision = ballCollisionRegion->hitTest(brickCollisionRegion, true);
        if(ballBrickCollision.hasCollided)
        {
            switch(ballBrickCollision.direction.value)
            {
                case Penjin::diTOP:
                case Penjin::diBOTTOM:
                {
                    newDirection.setY(-newDirection.y);
                    break;
                }
                case Penjin::diLEFT:
                case Penjin::diRIGHT:
                {
                    newDirection.setX(-newDirection.x);
                    break;
                }
                case Penjin::diBOTTOMLEFT:
                case Penjin::diBOTTOMRIGHT:
                case Penjin::diTOPLEFT:
                case Penjin::diTOPRIGHT:
                {
                    newDirection.setX(-newDirection.x);
                    newDirection.setY(-newDirection.y);
                    break;
                }
            }

            i = bricks.erase(i);
            if(i == bricks.end())
            {
                break;
            }
        }

        if(bricks.size() == 0)
        {
            std::cout << "You win!" << endl;
            shouldQuit = true;
        }
    }

    ball.setDirection(newDirection);
}

void GameState::input()
{
    Penjin::SimpleJoy* joy = Penjin::Joy::getInstance();
    Penjin::CollisionRegion* paddleCollisionRegion = paddle.getCollisionRegion();
    if(joy->isLeft() &&
       !paddleCollisionRegion->hitTest(0, paddle.getPosition().y, true))
    {
        paddle.moveLeft();
    }
    if(joy->isRight() &&
       !paddleCollisionRegion->hitTest(Penjin::GFX::getInstance()->getWidth(),
                                       paddle.getPosition().y, true))
    {
        paddle.moveRight();
    }
}

void GameState::clear()
{
    for(std::vector<Brick*>::iterator i = bricks.begin(); i != bricks.end(); ++i)
    {
        delete *i;
        *i = 0;
    }
}

