#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "ObjectsManager.h"

class GameManager
{
public:
	static void Start();
	const static bool GetIfPressed(sf::Keyboard::Key key);
	const static ObjectsManager& GetGameObjectsManager() { return ms_gameObjectManager; }

	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;
private:
	enum GameState 
	{
		Uninitialized, 
		ShowingSplash, 
		Paused,
		ShowingMenu, 
		Playing, 
		Exiting
	};

	static bool IsExiting();
	static void GameLoop();

	static void ShowSplashScreen();
	static void ShowMainMenu();

	static GameState ms_gameState;
	static sf::RenderWindow ms_mainWindow;
	static sf::Keyboard ms_keyBoard;
	static sf::Clock ms_clock;
	static ObjectsManager ms_gameObjectManager;
};

