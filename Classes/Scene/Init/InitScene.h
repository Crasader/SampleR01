#ifndef __INIT_SCENE_H__
#define __INIT_SCENE_H__

#include "TLib/TScene.h"

class InitLayer;

class InitScene : public TScene
{
public:
	InitScene();
	~InitScene();

	CREATE_FUNC(InitScene);
	bool init();

private:
	InitLayer* createLayer();

private:
	InitLayer* _layer;

};


#endif // __INIT_SCENE_H__
