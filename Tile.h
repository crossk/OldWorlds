#ifndef TILE_H
#define TILE_H

#include <SFML\Graphics.hpp>
#include "Definitions.h"
#include "ResourceManager.h"

class Tile : public sf::Drawable
{
public:
	Tile(ResourceManager *rm, sf::String textureFileName, float scale = 1);
	~Tile();
	void update(float frametime);
	void handle();
	float getTextureSize();
	void setPosition(float x, float y);

	//Debug Info
	void getTextureInfo();

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Sprite *undergroundSprite;
	float width;
	float height;
	float posX;
	float posY;
};
#endif // !TILE_H