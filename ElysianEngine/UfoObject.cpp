#include "UfoObject.h"

UfoObject::UfoObject(std::string id, Game& game)
	: GameObject(id, game)
{
	Vector2D testPos = Vector2D(200.0f, 384.0f);
	TransformComponent* testTransform = new TransformComponent(testPos, *this);
	
	TryAddComponent(testTransform);

	/*SpriteComponent* testSprite = new SpriteComponent(
		_dataLibrary.GetTexture("Assets/Enemy01.png"),
		testObject
	);*/

	DataLibrary& dataLibrary = game.GetDataLibary();

	AnimatedSpriteComponent* testSprite = new AnimatedSpriteComponent(*this);
	std::vector<SDL_Texture*> textures {
		dataLibrary.GetTexture("Assets/Enemy01.png"),
		dataLibrary.GetTexture("Assets/Enemy02.png"),
		dataLibrary.GetTexture("Assets/Enemy03.png"),
		dataLibrary.GetTexture("Assets/Enemy04.png")
	};

	testSprite->SetRenderer(game.GetRenderer());
	testSprite->SetAnimTextures(textures);
	testSprite->SetAnimFPS(24);
	
	TryAddComponent(testSprite);
}
