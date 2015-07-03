#ifndef __T_SCENE_H__
#define __T_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

#if 1
#define DISP_SCENE_NAME
#endif // DEBUG

class TScene : public cocos2d::Scene
{
protected:
	TScene();
	virtual ~TScene();

	virtual bool init();

public:
	CREATE_FUNC(TScene);

	virtual void update(float delta);

	virtual void onEnter();
	virtual void onExit();

	virtual void onEnterTransitionDidFinish();
	virtual void onExitTransitionDidStart();

	void setSceneID(int32_t sceneId) { _sceneId = sceneId; }
	int32_t getSceneID() { return _sceneId; }

private:
	int32_t _sceneId;

#ifdef DISP_SCENE_NAME
protected:
	std::string _sceneName = "";
#endif // DISP_SCENE_NAME
};


#endif // __T_SCENE_H__
