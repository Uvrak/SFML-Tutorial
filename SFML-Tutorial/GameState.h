#pragma once
#include "State.h"

class GameState :
    public State
{
private:
public:
    //Constructors /Desturctors
    GameState(sf::RenderWindow* pWindow);
    virtual ~GameState();

    //Functions
    void endState();
    void update(const float& dt);
    void render(sf::RenderTarget* pTarget);

};

