#include "stdafx.h"
#include "MainMenuState.h"


void MainMenuState::initKeybinds()
{
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");

	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2) {
			this->keybinds[key] = this->pSupportedKeys->at(key2);
		}
	}
	ifs.close();

}

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(300.f, 480.f, 250.f, 50.f,
		&this->font, "New Game",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)
	);

	this->buttons["SETTINGS_STATE"] = new Button(300.f, 580.f, 250.f, 50.f,
		&this->font, "Settings",
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)
	);

	this->buttons["EXIT_STATE"] = new Button(300.f, 780.f, 250.f, 50.f,
		&this->font, "Quit",
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)
	);
}

void MainMenuState::initVariables()
{
}

void MainMenuState::initBackground()
{
	this->background.setSize(sf::Vector2f(
		static_cast<float>(this->pWindow->getSize().x),
		static_cast<float>(this->pWindow->getSize().y)
	));
	if (!this->backgroundTexture.loadFromFile("Ressources/Images/Backgrounds/bg1.png"))
		throw("ERROR::MAINMENUSTATE::INITBACKGROUND LOAD BACKGROUNDFILE");
	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
}

MainMenuState::MainMenuState(sf::RenderWindow* pWindow, std::map<std::string, int>* pSupportedKeys, std::stack<State*>* states)
	: State(pWindow, pSupportedKeys, states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();

}

MainMenuState::~MainMenuState()
{
	for (auto i : this->buttons) {
		delete i.second;
	}
}

void MainMenuState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}

void MainMenuState::updateButtons()
{
	//this->gameStateButton->update(this->mousePosView);
	for (auto &i : this->buttons) {
		i.second->update(this->mousePosView);
	}
	
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		
		this->states->push(new GameState(this->pWindow, this->pSupportedKeys, this->states));
	}

	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->endState();
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();
	

	system("cls");
	std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";
}

void MainMenuState::renderButtons(sf::RenderTarget* pTarget)
{
	for (auto& i : this->buttons) {
		i.second->render(pTarget);
	}
}

void MainMenuState::render(sf::RenderTarget* pTarget)
{
	if (!pTarget)
		pTarget = this->pWindow;
	pTarget->draw(background);

	this->renderButtons(pTarget);

	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x + 20, this->mousePosView.y - 20);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());
	pTarget->draw(mouseText);
}
