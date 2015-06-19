#ifndef __T_SCENE_H__
#define __T_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class TScene : public cocos2d::Scene
{
public:
	TScene();
	virtual ~TScene();

	CREATE_FUNC(TScene);

	virtual bool init();
	virtual void update(float delta);

	virtual void onEnter();
	virtual void onExit();

	virtual void onEnterTransitionDidFinish();
	virtual void onExitTransitionDidStart();

	void setSceneID(int32_t sceneId) { _sceneId = sceneId; }

protected:
	int32_t _sceneId;
};


#endif // __T_SCENE_H__
