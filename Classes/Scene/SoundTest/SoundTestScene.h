#ifndef __SOUND_TEST_SCENE_H__
#define __SOUND_TEST_SCENE_H__

#include "TLib/TScene.h"

class SoundTestLayer;

class SoundTestScene : public TScene
{
private:
	SoundTestScene();
	~SoundTestScene();

	bool init();

public:
	CREATE_FUNC(SoundTestScene);

private:
	SoundTestLayer* createLayer();

private:
	SoundTestLayer* _layer;

};


#endif // __INIT_SCENE_H__
