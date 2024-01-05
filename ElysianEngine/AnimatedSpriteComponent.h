#pragma once
#include "SpriteComponent.h"
class AnimatedSpriteComponent :
    public SpriteComponent
{
public:
    AnimatedSpriteComponent(GameObject& parent);
    AnimatedSpriteComponent(GameObject& parent, const float animFps);
    void UpdateOutput(const float deltaTime) override;
    void SetAnimTextures(const std::vector<SDL_Texture*> textures);

    const float GetAnimFPS() const;
    void SetAnimFPS(const float fps);

    AnimatedSpriteComponent* Clone() const override;

private:
    std::vector<SDL_Texture*> _animTextures;
    float _currentFrame;
    float _animFps;
};

