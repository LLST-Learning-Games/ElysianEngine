#pragma once
#include "GameObjectComponent.h"
#include "GameObject.h"
#include "Vector2D.h"
#include <SDL_image.h>

class SpriteComponent : public GameObjectComponent
{
public:
	SpriteComponent(SDL_Texture* texture, GameObject& parent);
	SpriteComponent(GameObject& parent);
	~SpriteComponent();

	virtual void UpdateOutput(const float deltaTime) override;
	void SetRenderer(SDL_Renderer* renderer);
	void SetTexture(SDL_Texture* texture);

	int GetTextureHeight() const;
	int GetTextureWidth() const;


	SpriteComponent* Clone() const override;

protected:
	void Draw() const;

	SDL_Texture* _texture;
	SDL_Renderer* _renderer;

	int _textureHeight;
	int _textureWidth;
};

