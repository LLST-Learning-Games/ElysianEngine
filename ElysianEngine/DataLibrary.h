#pragma once
#include "SDL.h"
#include "SDL_image.h"

#include <iostream>
#include <unordered_map>



class DataLibrary
{
public:
	DataLibrary(const class Game& game);
	~DataLibrary();

	SDL_Texture* GetTexture(const std::string& fileName);

private:
	std::unordered_map<std::string, SDL_Texture*> _textureDictionary;
	const class Game& _game;

	SDL_Texture* LoadSDLTexture(const std::string& fileName);
};

