#pragma once

#include "State.h"
#include "GameState.h"

class Game
{
private:
	//Variables
	sf::RenderWindow* pWindow;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

public:
	//Constructors /Destructors
	Game();
	virtual ~Game();

	//Initializer Functions
	void initWindow();
	void initStates();

	//Functions
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

