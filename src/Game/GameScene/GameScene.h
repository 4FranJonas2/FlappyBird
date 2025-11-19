#pragma once

namespace gameScene
{
	enum class GameScene
	{
		MainMenu,
		OnePlayer,
		TwoPlayers,
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

