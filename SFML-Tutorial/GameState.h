#pragma once
#include "State.h"
#include "Entity.h"
#include "Player.h"
class GameState :
    public State
{
private:

    Player* player;
    //Functions
    void initKeyinds();
    void initTextures();
    void initPlayers();

 
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

