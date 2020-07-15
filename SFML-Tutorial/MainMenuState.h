#pragma once
#include "State.h"
class MainMenuState :
    public State
{
private:
    sf::RectangleShape background;

    //Functions
    void initKeyinds();
public:
    //Constructors /Desturctors
    MainMenuState(sf::RenderWindow* pWindow, std::map<std::string, int>* pSupportedKeys);
    ~MainMenuState();

    //Functions
    void initKeybinds();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* pTarget);

};

