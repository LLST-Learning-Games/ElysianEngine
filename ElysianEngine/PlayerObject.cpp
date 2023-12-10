#include "PlayerObject.h"

PlayerObject::PlayerObject(std::string id, Game& game) :
	GameObject(id, game)
{
	Vector2D testPos = Vector2D(100.0f, 384.0f);
	TransformComponent* testTransform = new TransformComponent(testPos, *this);

	TryAddComponent(testTransform);

	/*SpriteComponent* testSprite = new SpriteComponent(
		_dataLibrary.GetTexture("Assets/Enemy01.png"),
		testObject
	);*/

	DataLibrary& dataLibrary = game.GetDataLibary();

	AnimatedSpriteComponent* testSprite = new AnimatedSpriteComponent(*this);
	std::vector<SDL_Texture*> textures{
		dataLibrary.GetTexture("Assets/Character01.png"),
		dataLibrary.GetTexture("Assets/Character02.png"),
		dataLibrary.GetTexture("Assets/Character03.png"),
		dataLibrary.GetTexture("Assets/Character04.png"),
		dataLibrary.GetTexture("Assets/Character05.png"),
		dataLibrary.GetTexture("Assets/Character06.png")
	};

	testSprite->SetRenderer(game.GetRenderer());
	testSprite->SetAnimTextures(textures);
	testSprite->SetAnimFPS(24);

	TryAddComponent(testSprite);
	
	InputComponent* input = new InputComponent(*this);

	TryAddComponent(input);
}
