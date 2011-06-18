#include "penjinoid.h"
#include "gamestate.h"
#include "StateManager.h"

Penjinoid::Penjinoid()
{
    Penjin::StateManager* stateManager = Penjin::StateMan::getInstance();
    stateManager->addState(STATE_GAME, new GameState());
    stateManager->setNextState(STATE_GAME);
    stateManager->stateManagement();
}
