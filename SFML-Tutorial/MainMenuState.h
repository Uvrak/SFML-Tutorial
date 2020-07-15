#pragma once
#include "State.h"
#include "Button.h"

class MainMenuState :
    public State
{
private:
    sf::RectangleShape background;
    sf::Font font;

    Button* gameStateButton;

    //Functions
    void initFonts();
    void initKeybinds();
public:
    //Constructors /Desturctors
    MainMenuState(sf::RenderWindow* pWindow, std::map<std::string, int>* pSupportedKeys);
    ~MainMenuState();

    //Functions
    
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* pTarget);

};

