#include "stdafx.h"
#include "State.h"

State::State(sf::RenderWindow* pWindow, std::map<std::string, int>* pSupportedKeys, std::stack<State*>* states)
{
	this->pWindow = pWindow;
	this->pSupportedKeys = pSupportedKeys;
	this->states = states;
	this->quit = false;
}

State::~State()
{
}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::endState()
{
	this->quit = true;
}

void State::updateMousePositions()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->pWindow);
	this->mousePosView = this->pWindow->mapPixelToCoords(sf::Mouse::getPosition(*this->pWindow));
}
