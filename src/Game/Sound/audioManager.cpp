#include "audioManager.h"

namespace gameAudio
{
	AudioManager audio;

	void InitAudio()
	{
		float musicVolume = 0.5f;
		
		audio.menuMusic = LoadMusicStream("res/Audio/Nighttime-Escape_LoFi.mp3");
		audio.gameplayMusic = LoadMusicStream("res/Audio/Nighttime-Escape.mp3");
		
		SetMusicVolume(audio.menuMusic, musicVolume);
		SetMusicVolume(audio.gameplayMusic, musicVolume);

		audio.currentMusic = MusicType::MENU;
		PlayMusicStream(audio.menuMusic);
	}

	void UpdateAudio()
	{
		UpdateMusicStream(audio.menuMusic);
		UpdateMusicStream(audio.gameplayMusic);
	}

	void SwitchMusic(MusicType newMusic)
	{
		float timePlayed = 0.0f;

		if (audio.currentMusic == newMusic)
			return;

		if (audio.currentMusic == MusicType::MENU)
		{
			timePlayed = GetMusicTimePlayed(audio.menuMusic);
			PauseMusicStream(audio.menuMusic);
		}
		else
		{
			timePlayed = GetMusicTimePlayed(audio.gameplayMusic);
			PauseMusicStream(audio.gameplayMusic);
		}

		audio.currentMusic = newMusic;

		if (newMusic == MusicType::MENU)
		{
			SeekMusicStream(audio.menuMusic, timePlayed);
			PlayMusicStream(audio.menuMusic);
		}
		else
		{
			SeekMusicStream(audio.gameplayMusic, timePlayed);
			PlayMusicStream(audio.gameplayMusic);
		}
	}

	void PlaySFX(Sound& sfx)
	{
		PlaySound(sfx);
	}

	void UnloadAudio()
	{
		UnloadMusicStream(audio.menuMusic);
		UnloadMusicStream(audio.gameplayMusic);
		UnloadSound(audio.clickSound);
		UnloadSound(audio.enemyDestroySound);
		UnloadSound(audio.loseLifeSound);
		UnloadSound(audio.overSound);
		UnloadSound(audio.shootSound);

		CloseAudioDevice();
	}
}