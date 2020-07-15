#pragma once
#include "State.h"

class GameState :
    public State
{
private:

    //Functions
    void initKeyinds();
public:
    //Constructors /Desturctors
    GameState(sf::RenderWindow* pWindow, std::map<std::string, int>* pSupportedKeys);
    ~GameState();

    //Functions
    void initKeybinds();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* pTarget);

};

