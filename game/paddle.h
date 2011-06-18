#ifndef PADDLE_H
#define PADDLE_H

#include "Sprite.h"

class Paddle : public Penjin::Sprite
{
public:
  Paddle();

  void moveLeft();
  void moveRight();

private:

};

#endif
