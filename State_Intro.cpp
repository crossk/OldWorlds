#include "State_Intro.h"



State_Intro::State_Intro(GameEngine *engine, ResourceManager *rm) {
	ptrGameEngine = engine;

	//background
	background = new sf::Sprite();
	background->setTexture(*(rm->getTexture("background_intro")));
	float scale_x = ptrGameEngine->getActualScreenWidth() / background->getTexture()->getSize().x;
	float scale_y = ptrGameEngine->getActualScreenHeight() / background->getTexture()->getSize().y;
	std::cout << "ScreenWidth = " << ptrGameEngine->getActualScreenWidth() << std::endl;
	std::cout << "ScreenHeight = " << ptrGameEngine->getActualScreenHeight() << std::endl;
	std::cout << "scale_x = " << scale_x << std::endl;
	std::cout << "scale_y = " << scale_y << std::endl;
	background->setScale(scale_x, scale_y);

	//logo text
	logo = new sf::Text();
	font = new sf::Font();
	font->loadFromFile("Thor.ttf");
	logo->setFont(*font);
	logo->setString("Old Worlds");
	logo->setCharacterSize(72);
	logo->setOrigin(logo->getGlobalBounds().width / 2, logo->getGlobalBounds().height / 2);
	logo->setPosition(ptrGameEngine->getActualScreenWidth() / 2, ptrGameEngine->getActualScreenHeight() / 2);
}


State_Intro::~State_Intro() {
	delete ptrGameEngine;
	delete font;
	delete logo;
	delete background;
}

//Inherited methods from GameState
void State_Intro::handleEvents() {
	//handle key inputs to skip intro and get to main menu
	
}

void State_Intro::update() {
	//no updates needed
}

void State_Intro::render() {
	ptrGameEngine->getMainWindow()->draw(*background);
	ptrGameEngine->getMainWindow()->draw(*logo);
}
