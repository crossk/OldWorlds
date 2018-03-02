#include "Tile.h"



Tile::Tile(ResourceManager *rm, sf::String textureFileName, float scale) {
	undergroundSprite = new sf::Sprite();
	undergroundSprite->setTexture(*(rm->getTexture(textureFileName)));
	undergroundSprite->setScale(scale, scale);
}


Tile::~Tile() {
	delete undergroundSprite;

	undergroundSprite = nullptr;
}

void Tile::update(float frametime) {
	//to do
}

void Tile::handle() {
	//evtl maus events
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	undergroundSprite->setPosition(posX, posY);
	target.draw(*undergroundSprite);
}

void Tile::setPosition(float x, float y) {
	undergroundSprite->setPosition(x, y);
	posX = x;
	posY = y;
}

float Tile::getTextureSize() {
	return undergroundSprite->getTexture()->getSize().x;
}

//Debug Info
void Tile::getTextureInfo() {
	std::cout << "texture_x: " << undergroundSprite->getTexture()->getSize().x << std::endl;
	std::cout << "texture_y: " << undergroundSprite->getTexture()->getSize().y << std::endl;
	std::cout << "scale_x: " << undergroundSprite->getScale().x << std::endl;
	std::cout << "scale_y: " << undergroundSprite->getScale().y << std::endl;
}