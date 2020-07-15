#pragma once
class State
{
private:

protected:
	sf::RenderWindow* pWindow;
	std::map<std::string, int>* pSupportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	//Ressources
	std::vector<sf::Texture>* textures;

	//Functions
	virtual void initKeybinds() = 0;

public:
	//Constructors /Destructors
	State(sf::RenderWindow* pWindow, std::map<std::string, int>* pSupportedKeys);
	virtual ~State();
	
	//Accessors
	const bool& getQuit() const;
	
	//Functions
	virtual void checkForQuit();

	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* pTarget = nullptr) = 0;

};

