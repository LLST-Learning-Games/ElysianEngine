#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include <vector>

#include "GameObject.h"
#include "DataLibrary.h"
#include "BoxColliderComponent.h"


static const int SCREEN_HEIGHT = 768;
static const int SCREEN_WIDTH = 1024;
static const int FRAME_LIMIT_TICKS = 16;
static const float DELTA_TIME_MAX = 0.05f;

class Game
{
public:
	Game();
	Game(std::string id);
	~Game();

	bool Initialize();
	void SetId(std::string id);
	std::string GetId();

	bool LoadData();

	void RunLoop();
	void Shutdown();

	class GameObject* GetGameObject(std::string gameObjectId);

	bool TryAddGameObject(class GameObject* gameObject);
	bool TryRemoveGameObject(class GameObject& gameObject);
	bool TryRemoveGameObject(std::string gameObjectId);

	SDL_Renderer* GetRenderer();
	DataLibrary& GetDataLibary();

	//todo - move to Physics object
	void RegisterCollider(class BoxColliderComponent& collider);

private:
	bool InitSDL();

	void UpdateInput(const float& deltaTime);
	void UpdateState(const float& deltaTime);
	void UpdateOutput(const float& deltaTime);

	float CalculateDeltaTime();
	void HandleCoreInput();
	void MovePendingObjectsToMainList();

	std::string _id;
	std::vector<std::unique_ptr<GameObject>> _gameObjects;
	std::vector<std::unique_ptr<GameObject>> _pendingGameObjects;

	//todo - move to separate PhysicsSimulation object
	std::vector<BoxColliderComponent*> _colliders;

	bool _isRunning;

	Uint32 _ticksCount;
	float _deltaTime;

	const Uint8* _keyboardState;

	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::unique_ptr<DataLibrary> _dataLibrary;

};

