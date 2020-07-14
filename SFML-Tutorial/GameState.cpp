#include "stdafx.h"
#include "GameState.h"

GameState::GameState(sf::RenderWindow* pWindow)
	: State(pWindow)
{
}

GameState::~GameState()
{

}

void GameState::endState()
{
}

void GameState::update(const float& dt)
{
	std::cout << "Hello from GameState!\n";
}

void GameState::render(sf::RenderTarget* pTarget = nullptr)
{
}
