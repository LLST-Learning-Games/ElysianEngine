#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include <vector>

#include "GameObject.h"
#include "DataLibrary.h"
#include "BoxColliderComponent.h"
#include "CommandStream.h"


static const int SCREEN_HEIGHT = 768;
static const int SCREEN_WIDTH = 1024;
static const int FRAME_LIMIT_TICKS = 16;
static const float DELTA_TIME_MAX = 0.05f;

class Game
{
public:
	Game(const std::string& id);
	~Game();

	const bool Initialize();
	const std::string& GetId();

	const bool LoadData();

	void RunLoop();
	void Shutdown();

	class GameObject* GetGameObject(const std::string& gameObjectId);

	const bool TryAddGameObject(class GameObject&& gameObject);
	const bool TryAddGameObject(class GameObject* gameObject);
	const bool TryRemoveGameObject(const class GameObject& gameObject);
	const bool TryRemoveGameObject(const std::string& gameObjectId);

	SDL_Renderer* GetRenderer() const;
	DataLibrary& GetDataLibary() const;
	CommandStream& GetCommandStream();

private:
	bool InitSDL();

	void UpdateInput(const float deltaTime);
	void UpdateState(const float deltaTime);
	void UpdateOutput(const float deltaTime);

	const float CalculateDeltaTime();
	void HandleCoreInput();
	void MovePendingObjectsToMainList();

	const std::string _id;
	std::vector<std::unique_ptr<GameObject>> _gameObjects;
	std::vector<std::unique_ptr<GameObject>> _pendingGameObjects;

	bool _isRunning;

	Uint32 _ticksCount;
	float _deltaTime;

	const Uint8* _keyboardState;

	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::unique_ptr<DataLibrary> _dataLibrary;
	CommandStream _commandStream;

};

