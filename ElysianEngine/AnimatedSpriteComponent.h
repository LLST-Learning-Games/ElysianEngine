#pragma once
#include "SpriteComponent.h"
class AnimatedSpriteComponent :
    public SpriteComponent
{
public:
    AnimatedSpriteComponent(GameObject& parent);
    void UpdateOutput(const float deltaTime) override;
    void SetAnimTextures(std::vector<SDL_Texture*> textures);

    float GetAnimFPS() const;
    void SetAnimFPS(float fps);

private:
    std::vector<SDL_Texture*> _animTextures;
    float _currentFrame;
    float _animFps;
};

