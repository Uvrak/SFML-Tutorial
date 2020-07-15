#pragma once
class State
{
private:

protected:
	std::stack<State*> *states;
	sf::RenderWindow* pWindow;
	std::map<std::string, int>* pSupportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Ressources
	std::map<std::string, sf::Texture> textures;

	//Functions
	virtual void initKeybinds() = 0;

public:
	//Constructors /Destructors
	State(sf::RenderWindow* pWindow, std::map<std::string, int>* pSupportedKeys, std::stack<State*>* states);
	virtual ~State();
	
	//Accessors
	const bool& getQuit() const;
	
	//Functions
	void endState();
	virtual void updateMousePositions();

	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* pTarget = nullptr) = 0;

};

