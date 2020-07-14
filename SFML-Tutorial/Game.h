#pragma once
class Game
{
private:
	//Variables
	sf::RenderWindow* pWindow;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

public:
	//Constructors /Destructors
	Game();
	virtual ~Game();

	//Initializer Functions
	void initWindow();

	//Functions
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

