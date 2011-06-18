#ifndef PENJINOID_H
#define PENJINOID_H

#include "Game2d.h"

class Penjinoid : public Penjin::Game2d
{
public:
  Penjinoid();

  enum States { STATE_GAME };
};

#endif
