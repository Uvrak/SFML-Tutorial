#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	this->initWindow();
	this->initKeys();
	this->initStates();
	
}

Game::~Game()
{
	delete this->pWindow;

	while (!this->states.empty()) 
	{
		delete this->states.top();
		this->states.pop();
	}
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

void Game::initKeys()
{
	this->supportedKeys.emplace("ESCAPE", sf::Keyboard::Key::Escape);
	this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
	this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
	this->supportedKeys.emplace("S", sf::Keyboard::Key::S);
	this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
}

void Game::initStates()
{
	this->states.push(new GameState(this->pWindow, &this->supportedKeys));
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
	
	if (!this->states.empty())
		this->states.top()->update(this->dt);
	
	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);
		if (this->states.top()->getQuit())
		{
			std::cout << "Ending State:\n";
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		this->pWindow->close();
	}
	
}

void Game::render()
{
	this->pWindow->clear(sf::Color::Red);

	if (!this->states.empty()) {
		this->states.top()->render(this->pWindow);
	}
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
