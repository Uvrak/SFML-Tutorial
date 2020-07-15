#include "stdafx.h"
#include "GameState.h"

void GameState::initKeyinds()
{
	this->keybinds.emplace("MOVE_UP", this->supportedKeys->at("W"));
	this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("A"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("S"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("S"));
	this->keybinds.emplace("CLOSE", this->supportedKeys->at("ESCAPE"));
}

GameState::GameState(sf::RenderWindow* pWindow, std::map<std::string, int>* pSupportedKeys)
	: State(pWindow, supportedKeys)
{
	this->initKeybinds();
}

GameState::~GameState()
{

}

void GameState::initKeybinds()
{
}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void GameState::update(const float& dt)
{
	this->updateInput(dt);
	std::cout << "Hello from GameState!\n";
}

void GameState::render(sf::RenderTarget* pTarget)
{
}
