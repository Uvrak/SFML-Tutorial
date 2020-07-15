#pragma once

#include "State.h"
#include "GameState.h"
#include "MainMenuState.h"

class Game
{
private:
	//Variables
	sf::RenderWindow* pWindow;
	sf::Event sfEvent;

	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

public:
	//Constructors /Destructors
	Game();
	virtual ~Game();

	//Initializer Functions
	void initVariables();
	void initWindow();
	void initKeys();
	void initStates();
	

	//Functions
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

