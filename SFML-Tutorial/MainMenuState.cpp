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

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
}

MainMenuState::MainMenuState(sf::RenderWindow* pWindow, std::map<std::string, int>* pSupportedKeys)
	: State(pWindow, pSupportedKeys)
{
	this->initFonts();
	this->initKeybinds();

	this->gameStateButton = new Button(100.f, 100.f, 150.f, 50.f,
		&this->font, "New Game",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)
		);
	background.setSize(sf::Vector2f(pWindow->getSize().x, pWindow->getSize().y));
	background.setFillColor(sf::Color::Blue);
}

MainMenuState::~MainMenuState()
{
	delete this->gameStateButton;
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	
	this->gameStateButton->update(this->mousePosView);

	system("cls");
	std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";
}

void MainMenuState::render(sf::RenderTarget* pTarget)
{
	if (!pTarget)
		pTarget = this->pWindow;
	pTarget->draw(background);

	this->gameStateButton->render(pTarget);
}
