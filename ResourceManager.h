#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SFML\Graphics.hpp>
#include <map>
#include <iostream>
#include <fstream>
#include <stdio.h>


class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	void addTexture(sf::String path, sf::String name);
	sf::Texture* getTexture(sf::String name);
	void scaleTexture(char divider);

private:
	std::map<sf::String, sf::Texture*> *textureMap;
};
#endif // !RESOURCE_MANAGER_H