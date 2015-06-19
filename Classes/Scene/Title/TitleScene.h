#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "TLib/TScene.h"

class TitleLayer;

class TitleScene : public TScene
{
public:
	TitleScene();
	~TitleScene();

	CREATE_FUNC(TitleScene);
	bool init();
	void update(float delta);

private:
	TitleLayer* createLayer();

private:
	TitleLayer* _layer;

};


#endif // __TITLE_SCENE_H__
