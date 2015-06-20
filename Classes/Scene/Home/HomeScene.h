#ifndef __HOME_SCENE_H__
#define __HOME_SCENE_H__

#include "TLib/TScene.h"

class HomeLayer;

class HomeScene : public TScene
{
public:
	HomeScene();
	~HomeScene();

	CREATE_FUNC(HomeScene);
	bool init();

private:
	HomeLayer* createLayer();

private:
	HomeLayer* _layer;

};


#endif // __HOME_SCENE_H__
