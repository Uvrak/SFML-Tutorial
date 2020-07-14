#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	initWindow();
}

Game::~Game()
{
	delete this->pWindow;
}

//Initializer functions
void Game::initWindow()
{
	sf::VideoMode _window_bounds(800, 600);
	std::string _title = "None";
	unsigned _framerate_limit = 120;
	bool _vertical_sync_enabled = false;

	std::ifstream ifs("Config/window.ini");
	
	if (!ifs) {
		std::cout << "ERROR::GAME::INITWINDOW OPEN Config/window.ini\n";
	}
	
	if (ifs.is_open())
	{
		std::getline(ifs, _title);
		ifs >> _window_bounds.width >>_window_bounds.height;
		ifs >> _framerate_limit;
		ifs >> _vertical_sync_enabled;
	}

	ifs.close();

	this->pWindow = new sf::RenderWindow(_window_bounds, _title);

	this->pWindow->setFramerateLimit(_framerate_limit);
	this->pWindow->setVerticalSyncEnabled(_vertical_sync_enabled);
}

void Game::updateDt()
{
	/*Aktuallisiert die dt variable mit der Zeit die es braucht einden Frame zu updaten und zu rendern.*/
	this->dt = this->dtClock.restart().asSeconds();
	
}

void Game::updateSFMLEvents()
{
	while (this->pWindow->pollEvent(this->sfEvent)) {
		switch (this->sfEvent.type)
		{
		case sf::Event::Closed:
			this->pWindow->close();
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
	this->updateSFMLEvents();
}

void Game::render()
{
	this->pWindow->clear(sf::Color::Red);
	this->pWindow->display();
}

void Game::run()
{
	while (this->pWindow->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
