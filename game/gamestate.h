#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "ApplicationState.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"

#include <vector>

class GameState: public Penjin::ApplicationState
{
public:
    GameState();

    ~GameState();
    void init();
    void render();
    void update();
    void input();
    void clear();

private:
    Paddle paddle;
    Ball ball;
    std::vector<Brick*> bricks;
};

#endif
