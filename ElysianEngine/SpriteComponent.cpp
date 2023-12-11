#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(SDL_Texture* texture, const GameObject& parent) 
    : GameObjectComponent(parent, "sprite"),
    _renderer(nullptr),
    _textureHeight(0),
    _textureWidth(0)
{
    if(texture != nullptr)
    {
        SetTexture(texture);
        //SDL_QueryTexture(_texture, nullptr, nullptr, &_textureWidth, &_textureHeight);
        return;
    }
}

SpriteComponent::SpriteComponent(const GameObject& parent) 
    : SpriteComponent(nullptr, parent)
{
}

SpriteComponent::~SpriteComponent()
{
    _texture = nullptr;
    _renderer = nullptr;
}

void SpriteComponent::UpdateOutput(const float deltaTime)
{
    Draw();
}

void SpriteComponent::SetRenderer(SDL_Renderer* renderer)
{
    _renderer = renderer;
}

void SpriteComponent::SetTexture(SDL_Texture* texture)
{
    _texture = texture;
    SDL_QueryTexture(_texture, nullptr, nullptr, &_textureWidth, &_textureHeight);
}

int SpriteComponent::GetTextureHeight() const
{
    return _textureHeight;
}

int SpriteComponent::GetTextureWidth() const
{
    return _textureWidth;
}

SpriteComponent* SpriteComponent::Clone() const
{
    return nullptr;
}

void SpriteComponent::Draw() const
{
    if (_texture == nullptr) {
        return;
    }

    SDL_Rect r;
    
    r.h = static_cast<int>(_textureWidth * _parent.GetTransform().GetScale().y);
    r.w = static_cast<int>(_textureHeight * _parent.GetTransform().GetScale().x);
    r.y = static_cast<int>(_parent.GetTransform().GetPosition().y - r.w / 2);
    r.x = static_cast<int>(_parent.GetTransform().GetPosition().x - r.h / 2);

    SDL_RenderCopyEx(
        _renderer,
        _texture,
        nullptr,
        &r, 
        _parent.GetTransform().GetRotation(),
        nullptr,
        SDL_FLIP_NONE
    );

  
}
