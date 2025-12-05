#pragma once

#include "raylib.h"

namespace gameAudio
{
	enum class MusicType
	{
		MENU =1,
		GAMPLAY
	};

	struct AudioManager
	{
		Music menuMusic;
		Music gameplayMusic;
		Sound clickSound;
		Sound overSound;
		Sound shootSound;
		Sound enemyDestroySound;
		Sound loseLifeSound;

		MusicType currentMusic;
	};

	void InitAudio();
	void UpdateAudio();
	void SwitchMusic( MusicType newMusic);
	void PlaySFX( Sound& sfx);
	void UnloadAudio();
}