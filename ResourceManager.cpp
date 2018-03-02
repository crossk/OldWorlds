#include "ResourceManager.h"



ResourceManager::ResourceManager()
{
	textureMap = new std::map<sf::String, sf::Texture*>();
	remove("deconstructor_resourcemanager.txt");
}


ResourceManager::~ResourceManager()
{
	std::ofstream outputFile;
	outputFile.open("deconstructor_resourcemanager.txt", std::ofstream::app);
	outputFile << "Dekonstruiere ResourceManager\n";
	if (!textureMap->empty()) {
		for (std::map<sf::String, sf::Texture*>::iterator it = textureMap->begin(); it != textureMap->end(); it++) {
			outputFile << "Textur <" << it->first.toUtf8().c_str() << "> geloescht\n";
			delete it->second;
			it->second = nullptr;
		}
	}
	delete textureMap;
	textureMap = nullptr;
	outputFile << "Fertig dekonstruiert";
	outputFile.close();
}

void ResourceManager::addTexture(sf::String path, sf::String name) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	textureMap->insert(std::make_pair(name, texture));
	std::cout << "texture <" << name.toUtf8().c_str() << "> added\n";
}

sf::Texture* ResourceManager::getTexture(sf::String name) {
	if (textureMap->find(name) != textureMap->end()) {
		return textureMap->at(name);
	}
	else {
		return NULL;
	}
}



//Basically, every texture has a standard resolution of 512x512 pixels.
//Do we need smaller textures, e.g. for a 64x64 tile, we just need to divide the
//texture's resolution by a divider that is a number with the power of 2, so we can
//just shift right the binary values for n times.
void ResourceManager::scaleTexture(char divider) {
	/*
		PROTOTYPE UNDER CONSTRUCTION
	*/
}