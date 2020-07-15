#pragma once
#include "State.h"
#include "Entity.h"
class GameState :
    public State
{
private:

    Entity player;
    //Functions
    void initKeyinds();
public:
    //Constructors /Desturctors
    GameState(sf::RenderWindow* pWindow, std::map<std::string, int>* pSupportedKeys, std::stack<State*>* states);
    ~GameState();

    //Functions
    void initKeybinds();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* pTarget);

};

