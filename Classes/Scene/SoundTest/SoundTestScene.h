#ifndef __SOUND_TEST_SCENE_H__
#define __SOUND_TEST_SCENE_H__

#include "TLib/TScene.h"

class SoundTestLayer;

class SoundTestScene : public TScene
{
public:
	SoundTestScene();
	~SoundTestScene();

	CREATE_FUNC(SoundTestScene);
	bool init();

private:
	SoundTestLayer* createLayer();

private:
	SoundTestLayer* _layer;

};


#endif // __INIT_SCENE_H__
