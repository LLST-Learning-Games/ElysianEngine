#include "AnimatedSpriteComponent.h"

AnimatedSpriteComponent::AnimatedSpriteComponent(GameObject& parent) :
    SpriteComponent(parent)
{
}

void AnimatedSpriteComponent::UpdateOutput(const float deltaTime)
{
    int size = _animTextures.size();
    if (size < 1) {
        return;
    }

    _currentFrame += _animFps * deltaTime;

    while (_currentFrame >= size) {
        _currentFrame -= size;
    }

    SetTexture(_animTextures[static_cast<int>(_currentFrame)]);
    Draw();
}

void AnimatedSpriteComponent::SetAnimTextures(std::vector<SDL_Texture*> textures)
{
    _animTextures = textures;
}

float AnimatedSpriteComponent::GetAnimFPS() const
{
    return _animFps;
}

void AnimatedSpriteComponent::SetAnimFPS(float fps)
{
    _animFps = fps;
}
