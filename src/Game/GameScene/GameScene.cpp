#include "Game/GameScene/GameScene.h"

#include "Game/Entities/Bird/Bird.h"
#include "Game/Entities/Obstacle/Obstacle.h"
#include "Game/Screen/Screen.h"
#include "Game/Button/Button.h"
#include "Game/Entities/Background/Background.h"

namespace gameScene
{

	namespace mainMenu
	{
		enum class MainMenuScenes
		{
			MainMenu = -1,
			OnePlayer,
			TwoPlayers,
			Rules,
			Credits,
			Exit
		};

		static MainMenuScenes currentMainMenuScene = MainMenuScenes::MainMenu;

		namespace credits
		{
			static const Color bckgColor = BLACK;

			static const button::Button backButtonConfig =
			{
				{
					85.0f,							//Width	
					25.0f,							//Height
					{300.0f, 700.0f}				//Pos
				},
				//Text
				{
					{0.0f,0.0f},					//Pos
					"Atras",							//Text
					30,								//FontSize
					2,								//Spacing
					WHITE							//Color
				},

				RED,								//Color
				false								//isPressed
			};

			static const int maxCreditsLines = 3;
			static const text::Text creditsLines[maxCreditsLines] =
			{
				//Line1
				{
				{405, 80},								//Pos
				"Creditos",						//Text
				55.0f,									//FontSize
				2.0f,									//Spacing
				WHITE									//Color
},
{
				{425, 350},								//Pos
				"Agustin Laure",						//Text
				25.0f,									//FontSize
				2.0f,									//Spacing
				WHITE									//Color
},

{
				{410, 450},								//Pos
				"Jonas Francisco",						//Text
				25.0f,									//FontSize
				2.0f,									//Spacing
				WHITE
}
			};

			static void creditsScene();
			static button::Button initButton();
			static void update();
			static void draw();
			static void drawCredits();

			static button::Button backButton = initButton();

			static void creditsScene()
			{
				update();
				draw();
			}

			static button::Button initButton()
			{
				button::Button newButton = {};

				float width = backButtonConfig.body.width;
				float height = backButtonConfig.body.height;
				Vector2 pos = backButtonConfig.body.pos;
				std::string text = backButtonConfig.text.text;
				float fontSize = backButtonConfig.text.fontSize;
				float spacing = backButtonConfig.text.spacing;
				Color textColor = backButtonConfig.text.color;
				Color buttonBckgColor = backButtonConfig.color;

				newButton = button::init(width, height, pos, text, fontSize, spacing, textColor, buttonBckgColor);

				return newButton;
			}

			static void update()
			{
				button::update(backButton);

				if (backButton.isPressed)
				{
					currentMainMenuScene = MainMenuScenes::MainMenu;
				}
			}

			static void draw()
			{
				BeginDrawing();

				ClearBackground(bckgColor);

				drawCredits();

				button::draw(backButton);

				EndDrawing();
			}

			static void drawCredits()
			{
				for (int i = 0; i < maxCreditsLines; i++)
				{
					std::string text = creditsLines[i].text;
					int posX = static_cast<int>(creditsLines[i].pos.x);
					int posY = static_cast<int>(creditsLines[i].pos.y);
					int fontSize = static_cast<int>(creditsLines[i].fontSize);
					Color color = creditsLines[i].color;

					DrawText(text.c_str(), posX, posY, fontSize, color);
				}
			}
		}

		namespace rules
		{
			static const Color bckgColor = BLACK;

			static const button::Button backButtonConfig =
			{
				{
					85.0f,							//Width	
					25.0f,							//Height
					{300.0f, 700.0f}				//Pos
				},
				//Text
				{
					{0.0f,0.0f},					//Pos
					"Atras",							//Text
					30,								//FontSize
					2,								//Spacing
					WHITE							//Color
				},

				RED,								//Color
				false								//isPressed
			};

			static const int maxRulesLines = 4;
			static const text::Text rulesLines[maxRulesLines] =
			{
				{
				{415, 80},								//Pos
				"Reglas",						//Text
				55.0f,									//FontSize
				2.0f,									//Spacing
				WHITE},
				//Line1
{
				{145, 200},								//Pos
				"Jugador 1 (pajaro xxxx) use BARRA ESPACIADORA para saltar",						//Text
				25.0f,									//FontSize
				2.0f,									//Spacing
				WHITE},

{
				{165, 300},								//Pos
				"Jugador 2 (pajaro xxxx) use FLECHA ARRIBA para saltar",						//Text
				25.0f,									//FontSize
				2.0f,									//Spacing
				WHITE},

{
				{105, 400},								//Pos
				"Salte para evitar los obstaculos y sobreviva el mayor tiempo posible",						//Text
				25.0f,									//FontSize
				2.0f,									//Spacing
				WHITE
}
			};

			static void rulesScene();
			static button::Button initButton();
			static void update();
			static void draw();
			static void drawRules();

			static button::Button backButton = initButton();

			static void rulesScene()
			{
				update();
				draw();
			}

			static button::Button initButton()
			{
				button::Button newButton = {};

				float width = backButtonConfig.body.width;
				float height = backButtonConfig.body.height;
				Vector2 pos = backButtonConfig.body.pos;
				std::string text = backButtonConfig.text.text;
				float fontSize = backButtonConfig.text.fontSize;
				float spacing = backButtonConfig.text.spacing;
				Color textColor = backButtonConfig.text.color;
				Color buttonBckgColor = backButtonConfig.color;

				newButton = button::init(width, height, pos, text, fontSize, spacing, textColor, buttonBckgColor);

				return newButton;
			}

			static void update()
			{
				button::update(backButton);

				if (backButton.isPressed)
				{
					currentMainMenuScene = MainMenuScenes::MainMenu;
				}
			}

			static void draw()
			{
				BeginDrawing();

				ClearBackground(bckgColor);

				drawRules();

				button::draw(backButton);

				EndDrawing();
			}

			static void drawRules()
			{
				for (int i = 0; i < maxRulesLines; i++)
				{
					std::string text = rulesLines[i].text;
					int posX = static_cast<int>(rulesLines[i].pos.x);
					int posY = static_cast<int>(rulesLines[i].pos.y);
					int fontSize = static_cast<int>(rulesLines[i].fontSize);
					Color color = rulesLines[i].color;

					DrawText(text.c_str(), posX, posY, fontSize, color);
				}
			}
		}

		static const Color bckgColor = BLACK;

		static const int maxButtons = 5;
		static const button::Button buttonsConfig[maxButtons] =
		{
			{{140.0f,25.0f,	{450.0f, 200.0f}},
			{{0.0f,0.0f},"1 Jugador",30,	2, WHITE}, RED, false},

			{{182.0f,25.0f,	{425.0f, 300.0f}},
			{{0.0f,0.0f},"2 Jugadores",30,	2, WHITE}, RED, false},

			{{95.0f,25.0f,{470.0f, 500.0f}},
			{{0.0f,0.0f},"Reglas",30,2, WHITE},RED,false},
			
			{{125.0f,25.0f,{455.0f, 600.0f}},
			{{0.0f,0.0f},"Creditos",30,2, WHITE},RED,false},

			{{85.0f,25.0f,{50.0f, 700.0f}},
			{{0.0f,0.0f},"Salida",30,2,WHITE},RED,false},
		};

		static void update(GameScene& currentScene);
		static void draw();
		button::Button initButtons(int i);
		static void drawButtons();
		static void updateButtons();

		static button::Button buttons[maxButtons] =
		{
			initButtons(0),
			initButtons(1),
			initButtons(2),
			initButtons(3),
			initButtons(4)
		};

		static void mainMenuScene(GameScene& currentScene)
		{
			update(currentScene);
			draw();
		}

		void mainMenu(GameScene& currentGameScene)
		{
			switch (currentMainMenuScene)
			{
			case MainMenuScenes::MainMenu:
				mainMenuScene(currentGameScene);
				break;

			case MainMenuScenes::Rules:
				rules::rulesScene();
				break;

			case MainMenuScenes::Credits:
				credits::creditsScene();
				break;

			default:
				break;
			}
		}

		static void update(GameScene& currentGameScene)
		{
			updateButtons();

			if (buttons[static_cast<int>(MainMenuScenes::OnePlayer)].isPressed)
			{
				currentGameScene = GameScene::OnePlayer;
			}
			else if (buttons[static_cast<int>(MainMenuScenes::TwoPlayers)].isPressed)
			{
				currentGameScene = GameScene::TwoPlayers;
			}
			else if (buttons[static_cast<int>(MainMenuScenes::Rules)].isPressed)
			{
				currentMainMenuScene = MainMenuScenes::Rules;
			}
			else if (buttons[static_cast<int>(MainMenuScenes::Credits)].isPressed)
			{
				currentMainMenuScene = MainMenuScenes::Credits;
			}
			else if (buttons[static_cast<int>(MainMenuScenes::Exit)].isPressed)
			{
				currentGameScene = GameScene::Exit;
			}
		}

		static void draw()
		{
			BeginDrawing();
			ClearBackground(bckgColor);

			drawButtons();
			DrawText("Flappy Bird", 400,  50, 40, WHITE);
			DrawText("V1.0", screen::screenWidth - 100, screen::screenHeight - 50, 25, WHITE);

			EndDrawing();
		}

		button::Button initButtons(int i)
		{
			button::Button newButton = {};

			float width = buttonsConfig[i].body.width;
			float height = buttonsConfig[i].body.height;
			Vector2 pos = buttonsConfig[i].body.pos;
			std::string text = buttonsConfig[i].text.text;
			float fontSize = buttonsConfig[i].text.fontSize;
			float spacing = buttonsConfig[i].text.spacing;
			Color textColor = buttonsConfig[i].text.color;
			Color buttonBckgColor = buttonsConfig[i].color;

			newButton = button::init(width, height, pos, text, fontSize, spacing, textColor, buttonBckgColor);

			return newButton;
		}

		static void drawButtons()
		{
			for (int i = 0; i < maxButtons; i++)
			{
				button::draw(buttons[i]);
			}
		}

		static void updateButtons()
		{
			for (int i = 0; i < maxButtons; i++)
			{
				button::update(buttons[i]);
			}
		}
	}

	namespace playing
	{
		GameScene actualScene;

		static const text::Text loseText =
		{
			{295, 400},																//Pos
			"R para reiniciar, E para salir al menu",								//Text
			25.0f,																	//FontSize
			2.0f,																	//Spacing
			WHITE																	//Color
		};

		static const text::Text pauseTitle =
		{
			{470, 100},																//Pos
			"PAUSA",								                                //Text
			55.0f,																	//FontSize
			2.0f,																	//Spacing
			WHITE																	//Color
		};

		static const text::Text gameEndTitle =
		{
			{300, 100},																//Pos
			"FIN DEL JUEGO",								                                //Text
			55.0f,																	//FontSize
			2.0f,																	//Spacing
			WHITE																	//Color
		};
		
		static const text::Text pauseContinue =
		{
			{215, 500},																//Pos
			"Pulse cualquier tecla de movimiento para continuar",								                                //Text
			25.0f,																	//FontSize
			2.0f,																	//Spacing
			WHITE																	//Color
		};

		static void update(float delta, GameScene& currentScene);
		static void draw(GameScene currentScene);
		static void resetGame();

		namespace lost
		{
			static void update(GameScene& currentScene);
			static void draw();
		}
		namespace pause
		{
			static void update(GameScene lastScene, GameScene& currentScene);
			static void draw(GameScene lastScene);
		}

		//Entitites
		static bird::Bird bird = bird::init(KEY_SPACE, RED);
		static bird::Bird bird2 = bird::init(KEY_UP, BLUE);
		static obstacle::Obstacle obstacle = obstacle::init(65.0f, 3000.0f, { screen::screenWidth,screen::screenHeight / 2 }, RED);
		static background::BackgroundElement background[background::backgroundElements] = {};

		static const Color bckgColor = BLACK;

		static void update(float delta, GameScene& currentScene)
		{

			if (currentScene == gameScene::GameScene::OnePlayer)
			{
				if (!bird.hasLost)
				{
					obstacle::update(obstacle, bird, delta);
					background::update(background, delta);
					bird::update(bird, delta);
				}

				if (IsKeyDown(KEY_ENTER) && !bird.hasLost)
				{
					actualScene = currentScene;
					currentScene = GameScene::Pause;
				}

				else
				{
					lost::update(currentScene);
				}
			}

			if (currentScene == gameScene::GameScene::TwoPlayers)
			{
				if (!bird.hasLost || !bird2.hasLost)
				{
					obstacle::update(obstacle, bird, delta);
					obstacle::update(obstacle, bird2, delta);
					background::update(background, delta);

					if (!bird.hasLost)
					{
						bird::update(bird, delta);
					}

					if (!bird2.hasLost)
					{
						bird::update(bird2, delta);
					}

					if (IsKeyDown(KEY_ENTER) && !bird.hasLost && !bird2.hasLost)
					{
						actualScene = currentScene;
						currentScene = GameScene::Pause;
					}
				}

				else
				{
					lost::update(currentScene);
				}
			}

			if (currentScene == gameScene::GameScene::Pause)
			{
				pause::update(actualScene, currentScene);
			}
		}

		static void draw(GameScene currentScene)
		{
			BeginDrawing();
			ClearBackground(bckgColor);

			if (currentScene == gameScene::GameScene::OnePlayer)
			{
				if (!bird.hasLost)
				{
					background::draw(background);
					obstacle::draw(obstacle);
					bird::draw(bird);
				}

				else
				{
					lost::draw();
				}
			}

			if (currentScene == gameScene::GameScene::TwoPlayers)
			{
				if (!bird.hasLost || !bird2.hasLost)
				{
					background::draw(background);
					obstacle::draw(obstacle);

					if (!bird.hasLost)
					{
						bird::draw(bird);
					}
					if (!bird2.hasLost)
					{
						bird::draw(bird2);
					}
				}

				else
				{
					lost::draw();
				}
			}

			if (currentScene == gameScene::GameScene::Pause)
			{
				pause::draw(currentScene);
			}

			EndDrawing();
		}

		void init()
		{
			for (int i = 0; i < background::backgroundElements; i++)
			{
				background[i] = background::initBackground(i);
			}
		}

		void playing(float delta, GameScene& currentScene)
		{
			update(delta, currentScene);
			draw(currentScene);
		}

		static void resetGame()
		{
			bird::reset(bird);
			bird::reset(bird2);
			obstacle::reset(obstacle);
			background::reset(background);
		}

		namespace lost
		{
			static void update(GameScene& currentScene)
			{
				if (IsKeyDown(KEY_R))
				{
					resetGame();
				}

				if (IsKeyDown(KEY_E))
				{
					resetGame();

					currentScene = GameScene::MainMenu;
				}
			}

			static void draw()
			{
				DrawText(gameEndTitle.text.c_str(), static_cast<int>(gameEndTitle.pos.x), static_cast<int>(gameEndTitle.pos.y), static_cast<int>(gameEndTitle.fontSize), gameEndTitle.color);
				DrawText(loseText.text.c_str(), static_cast<int>(loseText.pos.x), static_cast<int>(loseText.pos.y), static_cast<int>(loseText.fontSize), loseText.color);
			}
		}

		namespace pause
		{
			static void update(GameScene lastScene, GameScene& currentScene)
			{
				GameScene auxScene;
				auxScene = lastScene;

				if (IsKeyDown(KEY_R))
				{
					currentScene = auxScene;
					resetGame();
				}

				if (IsKeyDown(KEY_E))
				{
					resetGame();

					currentScene = GameScene::MainMenu;
				}

				if (IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_UP))
				{
					currentScene = auxScene;
				}
			}

			static void draw(GameScene lastScene)
			{
				GameScene auxScene;
				auxScene = lastScene;

				background::draw(background);
				obstacle::draw(obstacle);

				if (auxScene == gameScene::GameScene::OnePlayer)
				{
					bird::draw(bird);
				}

				if (auxScene == gameScene::GameScene::TwoPlayers)
				{
					if (!bird.hasLost)
					{
						bird::draw(bird);
					}
					if (!bird2.hasLost)
					{
						bird::draw(bird2);
					}
				}

				DrawText(pauseTitle.text.c_str(), static_cast<int>(pauseTitle.pos.x), static_cast<int>(pauseTitle.pos.y), static_cast<int>(pauseTitle.fontSize), pauseTitle.color);
				
				DrawText(loseText.text.c_str(), static_cast<int>(loseText.pos.x), static_cast<int>(loseText.pos.y), static_cast<int>(loseText.fontSize), loseText.color);

				DrawText(pauseContinue.text.c_str(), static_cast<int>(pauseContinue.pos.x), static_cast<int>(pauseContinue.pos.y), static_cast<int>(pauseContinue.fontSize), pauseContinue.color);
			}
		}
	}
}