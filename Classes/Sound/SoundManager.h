#ifndef __SOUND_MANAGER_H__
#define __SOUND_MANAGER_H__

#include "cocos2d.h"

#include "BGMManager.h"
#include "SEManager.h"


class SoundManager
{
private:
	SoundManager();
	~SoundManager();

public:
	static SoundManager* create();
	void destroy();

	static SoundManager* getInstance() { return s_manager; }

private:
	bool init();

public:
	void pause();
	void resume();

	BGMManager* getBGMManager() { return _bgmManager; }
	SEManager* getSEManager() { return _seManager; }

private:
	static SoundManager* s_manager;

	BGMManager* _bgmManager;
	SEManager* _seManager;
};

#define SOUND_MANAGER()	(SoundManager::getInstance())
#define BGM_MANAGER()	(SoundManager::getInstance()->getBGMManager())
#define SE_MANAGER()	(SoundManager::getInstance()->getSEManager())


#endif // __SOUND_MANAGER_H__
