#include "AudioManager.h"
#include <Windows.h>

void AudioManager::MakeHitNoise() const
{
	MessageBeep(-_hitNoise);
}
