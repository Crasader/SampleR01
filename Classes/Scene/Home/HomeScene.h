#ifndef __HOME_SCENE_H__
#define __HOME_SCENE_H__

#include "TLib/TScene.h"

class HomeLayer;

class HomeScene : public TScene
{
private:
	HomeScene();
	~HomeScene();

	bool init();

public:
	CREATE_FUNC(HomeScene);

private:
	HomeLayer* createLayer();

private:
	HomeLayer* _layer;

};


#endif // __HOME_SCENE_H__
