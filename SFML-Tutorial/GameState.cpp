#include "stdafx.h"
#include "GameState.h"

void GameState::initKeybinds()
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

GameState::GameState(sf::RenderWindow* pWindow, std::map<std::string, int>* pSupportedKeys)
	: State(pWindow, pSupportedKeys)
{
	this->initKeybinds();
}

GameState::~GameState()
{

}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	//std::cout << "Hello from GameState!\n";
}

void GameState::render(sf::RenderTarget* pTarget)
{
	if (!pTarget)
		pTarget = this->pWindow;
}
