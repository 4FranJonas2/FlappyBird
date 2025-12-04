#pragma once

#include "raylib.h"

#include "Game/Entities/Bird/Bird.h"

namespace gameScene
{
	enum class GameScene
	{
		MainMenu,
		OnePlayer,
		TwoPlayers,
		Pause,
		Exit
	};

	namespace mainMenu
	{
		void mainMenu(GameScene& currentScene);
	}

	namespace playing
	{
		void init();
		void playing(float delta, GameScene& currentScene);
	}
}

