#include "GameEngine.h"
#include "State_Intro.h"

GameEngine::GameEngine() {
	//create member
	mainWindow = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Old Worlds");
	event = new sf::Event();
	clock = new sf::Clock();
	rm = new ResourceManager();

	//get actual screen size
	actualScreenWidth = mainWindow->getSize().x;
	actualScreenHeight = mainWindow->getSize().y;

	//Load textures with resource manager
	rm->addTexture("tile_GreenGrass.png", "tile_Grass");
	rm->addTexture("tile_FrozenGround.png", "tile_FrozenGround");
	rm->addTexture("tile_SeamlessGrass.png", "tile_SeamlessGrass");
	rm->addTexture("background_SnowLongGrass_3200x2400.png", "background_intro");

	currentState = new State_Intro(this, rm);

	mainWindow->setFramerateLimit(60);
	isRunning = true;

	//test area
	for (int i = 0; i < 5; i++) {
		sf::Texture* t = new sf::Texture();
		std::cout << "Address of texture object #" << i << ": " << &(*t) << std::endl;
	}

}


GameEngine::~GameEngine() {
	delete clock;
	delete event;
	delete mainWindow;
	delete rm;

	clock = nullptr;
	event = nullptr;
	mainWindow = nullptr;
	rm = nullptr;
}

void GameEngine::run() {
	while (isRunning == true) {
		calculateFrametime();

		//swap handleEvents() and update(...) ?
		handleEvents();
		update(calculatedFrametime);		
		render();

		quit();
	}
}

void GameEngine::quit() {
	if (isRunning == false) {
		mainWindow->close();
	}
}



void GameEngine::update(float frametime) {
	//update current state's entities
	currentState->update();
}

void GameEngine::handleEvents() {
	while (mainWindow->pollEvent(*event)) {
		//now handle all incoming events
		switch (event->type) {
			case sf::Event::Closed:
				isRunning = false;
				break;

			case sf::Event::Resized:
				actualScreenWidth = mainWindow->getSize().x;
				actualScreenHeight = mainWindow->getSize().y;
				std::cout << "screen_x = " << actualScreenWidth << "\nscreen_y = " << actualScreenHeight << std::endl;
		}
		//now handle the current state's events
		currentState->handleEvents();
	}
}

void GameEngine::render() {
	mainWindow->clear(sf::Color(80, 110, 80));

	//render your stuff
	currentState->render();

	//test
	sf::Texture tex;
	tex.loadFromFile("leaf.png");
	sf::Vector2u texSize = tex.getSize();
	float rectX = static_cast<float>(texSize.x);
	float rectY = static_cast<float>(texSize.y);
	sf::RectangleShape shape(sf::Vector2f(rectX, rectY));
	shape.setTexture(&tex);

	mainWindow->draw(shape);
	
	mainWindow->display();
}

void GameEngine::calculateFrametime() {
	calculatedFrametime = clock->getElapsedTime().asSeconds();
	clock->restart();
}