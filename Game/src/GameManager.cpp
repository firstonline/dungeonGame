#include "stdafx.h"
#include "GameManager.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "Ball.h"
#include "AiPaddle.h"
#include "SFMLSoundProvider.h"
#include "ServiceLocator.h"

void GameManager::Start(void)
{
	if (ms_gameState != Uninitialized)
		return;

	ms_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pang!");

	SFMLSoundProvider soundProvider;
	ServiceLocator::RegisterServiceLocator(&soundProvider);
	// soundProvider.PlaySong("audio/Soundtrack.ogg", true);

	Player *player = new Player();
	player->SetPosition((1024 / 2) - 45, 700);

	AiPaddle * ai = new AiPaddle();
	ai->SetPosition((SCREEN_WIDTH / 2), 40);

	Ball *ball = new Ball();
	ball->SetPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) - 15);

	ms_gameObjectManager.Add("Player", player);
	ms_gameObjectManager.Add("AiPlayer", ai);
	ms_gameObjectManager.Add("Ball", ball);

	ms_gameState = GameManager::ShowingSplash;

	while (!IsExiting())
	{
		GameLoop();
	}

	ms_mainWindow.close();
}

const bool GameManager::GetIfPressed(sf::Keyboard::Key key)
{
	return ms_keyBoard.isKeyPressed(key);
}

bool GameManager::IsExiting()
{
	if (ms_gameState == GameManager::Exiting)
		return true;
	else
		return false;
}

void GameManager::GameLoop()
{
	switch (ms_gameState)
	{
		case GameManager::ShowingMenu:
		{
			ShowMainMenu();
			break;
		}
		case GameManager::ShowingSplash:
		{
			ShowSplashScreen();
			break;
		}
		case GameManager::Playing:
		{
			ms_mainWindow.clear(sf::Color(255, 0, 0));
			ms_gameObjectManager.UpdateAll(ms_clock.restart().asSeconds());
			ms_gameObjectManager.DrawAll(ms_mainWindow);
			ms_mainWindow.display();
			sf::Event currentEvent;
			while (ms_mainWindow.pollEvent(currentEvent))
			{
				if (currentEvent.type == sf::Event::Closed)
				{
					ms_gameState = GameManager::Exiting;
				}

				if (currentEvent.type == sf::Event::KeyPressed)
				{
					if (currentEvent.key.code == sf::Keyboard::Escape)
					{
						ShowMainMenu();
					}
				}

				break;
			}
		}
	}
}

void GameManager::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(ms_mainWindow);
	ms_gameState = GameManager::ShowingMenu;
}

void GameManager::ShowMainMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(ms_mainWindow);
	switch (result)
	{
	case MainMenu::Exit:
		ms_gameState = GameManager::Exiting;
		break;
	case MainMenu::Play:
		ms_gameState = GameManager::Playing;
		break;
	}
}

GameManager::GameState GameManager::ms_gameState = Uninitialized;
sf::RenderWindow GameManager::ms_mainWindow;
sf::Keyboard GameManager::ms_keyBoard;
sf::Clock GameManager::ms_clock;
ObjectsManager GameManager::ms_gameObjectManager;
