#include "stdafx.h"
#include "State.h"

State::State(sf::RenderWindow* pWindow, std::map<std::string, int>* pSupportedKeys)
{
	this->pWindow = pWindow;
	this->pSupportedKeys = pSupportedKeys;
}

State::~State()
{
}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->quit = true;
}
