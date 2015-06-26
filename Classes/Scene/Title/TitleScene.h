#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "TLib/TScene.h"

class TitleLayer;

class TitleScene : public TScene
{
private:
	TitleScene();
	~TitleScene();

	bool init();

public:
	CREATE_FUNC(TitleScene);
	void update(float delta);

private:
	TitleLayer* createLayer();

private:
	TitleLayer* _layer;
};


#endif // __TITLE_SCENE_H__
