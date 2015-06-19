#include "cocos2d.h"
#include "SEManager.h"
#include "audio/include/AudioEngine.h"

using namespace cocos2d::experimental;


SEManager::SEManager()
: _volume(1.0f)
{
}
SEManager::~SEManager()
{
}

SEManager* SEManager::create()
{
	SEManager* manager = new SEManager();

	if (manager && manager->init()) {
		return manager;
	}
	else {
		if (manager) { delete manager; }
		return NULL;
	}
}

void SEManager::destroy()
{
	delete this;
}

bool SEManager::init()
{
	return true;
}

int32_t SEManager::play(uint32_t seId, bool loop)
{
	int32_t audioID = AudioEngine::play2d("", loop, _volume);
	return audioID;
}

void SEManager::stop(int32_t audioID)
{
	if (audioID != AudioEngine::INVALID_AUDIO_ID) {
		AudioEngine::stop(audioID);
	}
}

void SEManager::pause(int32_t audioID)
{
	if (audioID != AudioEngine::INVALID_AUDIO_ID) {
		AudioEngine::pause(audioID);
	}
}

void SEManager::pause()
{
	AudioEngine::pauseAll();
}

void SEManager::resume(int32_t audioID)
{
	if (audioID != AudioEngine::INVALID_AUDIO_ID) {
		AudioEngine::resume(audioID);
	}
}

void SEManager::resume()
{
	AudioEngine::resumeAll();
}

void SEManager::setVolume(float volume) {
	_volume = volume;
}
