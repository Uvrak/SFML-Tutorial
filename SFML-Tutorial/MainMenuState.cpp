#include "stdafx.h"
#include "MainMenuState.h"


void MainMenuState::initKeybinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2) {
			this->keybinds[key] = this->pSupportedKeys->at(key2);
		}
	}
	ifs.close();

}

MainMenuState::MainMenuState(sf::RenderWindow* pWindow, std::map<std::string, int>* pSupportedKeys)
	: State(pWindow, pSupportedKeys)
{
	this->initKeybinds();
	background.setSize(sf::Vector2f(pWindow->getSize().x, pWindow->getSize().y));
	background.setFillColor(sf::Color::Blue);
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void MainMenuState::update(const float& dt)
{
	this->updateInput(dt);
	//std::cout << "Hello from GameState!\n";
}

void MainMenuState::render(sf::RenderTarget* pTarget)
{
	if (!pTarget)
		pTarget = this->pWindow;
	pTarget->draw(background);
}
