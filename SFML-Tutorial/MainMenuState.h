#pragma once
#include "State.h"
#include "Button.h"
#include "GameState.h"

class MainMenuState :
    public State
{
private:
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button*> buttons;



    //Functions
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds();
    void initButtons();
public:
    //Constructors /Desturctors
    MainMenuState(sf::RenderWindow* pWindow, std::map<std::string, int>* pSupportedKeys, std::stack<State*>* states);
    ~MainMenuState();

    //Functions
   
    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* pTarget);
    void render(sf::RenderTarget* pTarget);

};

