#include "DataLibrary.h"

#include "Game.h"

DataLibrary::DataLibrary(class Game& game) :
	_game(game)
{

}

DataLibrary::~DataLibrary()
{
	for (auto i : _textureDictionary)
	{
		SDL_DestroyTexture(i.second);
	}
	_textureDictionary.clear();
}

SDL_Texture* DataLibrary::GetTexture(const std::string& fileName)
{
	std::unordered_map<std::string, SDL_Texture*>::iterator texture_lookup 
		= _textureDictionary.find(fileName);
	
	if(texture_lookup != _textureDictionary.end())
	{
		return texture_lookup->second;
	}
	else 
	{
		return LoadSDLTexture(fileName);
	}
}


SDL_Texture* DataLibrary::LoadSDLTexture(const std::string& fileName)
{
	SDL_Surface* surface = IMG_Load(fileName.c_str());
	
	if (!surface) {
		SDL_Log("[DataLibrary] Could not find image at %s", fileName.c_str());
		return nullptr;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(_game.GetRenderer(), surface);
	
	SDL_FreeSurface(surface);

	if (!texture) {
		SDL_Log("[DataLibrary] Could not create texture from surface at %s", fileName.c_str());
		return nullptr;
	}

	_textureDictionary.emplace(fileName, texture);
	return texture;
}
