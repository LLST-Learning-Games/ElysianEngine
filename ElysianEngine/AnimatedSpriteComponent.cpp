#include "AnimatedSpriteComponent.h"

AnimatedSpriteComponent::AnimatedSpriteComponent(const GameObject& parent) :
    AnimatedSpriteComponent(parent, 0.0f)
{
}
AnimatedSpriteComponent::AnimatedSpriteComponent(const GameObject& parent, const float animFps) :
    SpriteComponent(parent),
    _animFps(animFps)
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

const float AnimatedSpriteComponent::GetAnimFPS() const
{
    return _animFps;
}

void AnimatedSpriteComponent::SetAnimFPS(float fps)
{
    _animFps = fps;
}

AnimatedSpriteComponent* AnimatedSpriteComponent::Clone() const
{
    return nullptr;
}
