#include "Game.h"
#include "UfoObject.h"
#include "PlayerObject.h"


#pragma region INITIALIZATION
Game::Game(const std::string& id) :
	_ticksCount(0),
	_id(id),
	_dataLibrary(new DataLibrary(*this))
{
}

Game::~Game() {

	_window = nullptr;
}


const bool Game::Initialize()
{	
	_isRunning = InitSDL();

	_isRunning = _isRunning && LoadData();
	
	return _isRunning;
}

bool Game::InitSDL()
{
	// Initialize SDL SDK
	int sdlResult = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	if (sdlResult != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	// Create SDL Window
	_window = SDL_CreateWindow(
		_id.c_str(),
		100,
		100,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		0
	);

	if (!_window)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	// Create SDL renderer
	_renderer = SDL_CreateRenderer(
		_window, // Window to create renderer for
		-1,		 // Usually -1
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!_renderer)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}

	//Init graphics
	IMG_Init(IMG_INIT_PNG);

	//Init audio
	//Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	//Init TrueType Fonts
	//TTF_Init();

}

const bool Game::LoadData()
{
	GameObject* testUfoObject = new UfoObject("testUfo", *this);
	GameObject* testPlayer = new PlayerObject("testPlayer", *this);

	TryAddGameObject(testUfoObject);
	TryAddGameObject(testPlayer);
	
	//TryAddGameObject(UfoObject("testUfo", *this));
	//TryAddGameObject(PlayerObject("testPlayer", *this));
		
	return true;
}


void Game::Shutdown()
{
	_gameObjects.clear();
	_pendingGameObjects.clear();

	SDL_DestroyRenderer(_renderer);
	_renderer = nullptr;

	SDL_DestroyWindow(_window);
	_window = nullptr;

	SDL_Quit();
}

#pragma endregion

#pragma region CORE LOOP
void Game::RunLoop()
{
	while (_isRunning) {

		while (!SDL_TICKS_PASSED(SDL_GetTicks(), _ticksCount + FRAME_LIMIT_TICKS));

		_deltaTime = CalculateDeltaTime();

		UpdateInput(_deltaTime);
		UpdateState(_deltaTime);
		UpdateOutput(_deltaTime);

		MovePendingObjectsToMainList();
	}

	Shutdown();
}

void Game::UpdateInput(const float deltaTime)
{
	HandleCoreInput();

	for (size_t i = 0; i < _gameObjects.size(); i++) {
		_gameObjects[i]->UpdateInput(deltaTime, _keyboardState);
	}
}


void Game::UpdateState(const float deltaTime)
{
	for (size_t i = 0; i < _gameObjects.size(); i++) {
		std::unordered_map<std::string, std::unique_ptr<Command>>* objectCommands;
		objectCommands = _commandStream.GetGameObjectCommandList(_gameObjects[i]->GetId());
		_gameObjects[i]->UpdateState(deltaTime, objectCommands);
	}

	//for (size_t i = 0; i < _colliders.size(); i++) {
	//	for (size_t j = i + 1; j < _colliders.size(); j++) {
	//		BoxColliderComponent* colliderA = _colliders[i];
	//		BoxColliderComponent* colliderB = _colliders[j];

	//	}
	//}
}

void Game::UpdateOutput(const float deltaTime)
{

	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);

	for (size_t i = 0; i < _gameObjects.size(); i++) {
		_gameObjects[i]->UpdateOutput(deltaTime);
	}

	SDL_RenderPresent(_renderer);
	_commandStream.ClearCommands();
}

const float Game::CalculateDeltaTime()
{
	float deltaTime = (SDL_GetTicks() - _ticksCount) / 1000.0f;


	if (deltaTime > DELTA_TIME_MAX) {
		deltaTime = DELTA_TIME_MAX;
	}

	_ticksCount = SDL_GetTicks();
	return deltaTime;
}

void Game::HandleCoreInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			_isRunning = false;
			break;
		}
	}

	_keyboardState = SDL_GetKeyboardState(NULL);

	if (_keyboardState[SDL_SCANCODE_ESCAPE]) {
		_isRunning = false;
	}
}

void Game::MovePendingObjectsToMainList()
{
	for (auto& gameObject : _pendingGameObjects) {
		_gameObjects.emplace_back(std::move(gameObject));
	}
	_pendingGameObjects.clear();
}

#pragma endregion

#pragma region ACCESSORS

GameObject* Game::GetGameObject(const std::string& gameObjectId)
{
	for (auto& gameObject : _gameObjects) {
		if (gameObject->GetId() == gameObjectId) {
			return gameObject.get();
		}
	}

	for (auto& pendingGameObject : _pendingGameObjects) {
		if (pendingGameObject->GetId() == gameObjectId) {
			return pendingGameObject.get();
		}
	}

	return nullptr;
}

const bool Game::TryAddGameObject(GameObject&& gameObject)
{
	_pendingGameObjects.emplace_back(std::make_unique<GameObject>(std::move(gameObject)));
	// todo - error handling
	return true;
}

const bool Game::TryAddGameObject(GameObject* gameObject)
{
	_pendingGameObjects.emplace_back(std::unique_ptr<GameObject>(gameObject));
	// todo - error handling
	return true;
}

const bool Game::TryRemoveGameObject(const GameObject& gameObject)
{
	//todo
	return false;
}

const bool Game::TryRemoveGameObject(const std::string& gameObjectId)
{
	return TryRemoveGameObject(*GetGameObject(gameObjectId));
}

SDL_Renderer* Game::GetRenderer() const
{
	return _renderer;
}

DataLibrary& Game::GetDataLibary() const
{
	return *_dataLibrary;
}

CommandStream& Game::GetCommandStream()
{
	return _commandStream;
}

void Game::RegisterCollider(BoxColliderComponent& collider)
{
	//_colliders.emplace_back(&collider);
}

const std::string& Game::GetId()
{
	return _id;
}

#pragma endregion
