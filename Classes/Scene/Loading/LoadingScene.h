#ifndef __LOADING_SCENE_H__
#define __LOADING_SCENE_H__

#include "TLib/TScene.h"


class LoadingLayer;

class LoadingScene : public TScene
{
public:
	LoadingScene();
	~LoadingScene();

	CREATE_FUNC(LoadingScene);
	bool init();
	void update(float delta);

	void set(int32_t nextSceneId);

	bool isLoaded();
	void setEnd();

private:
	LoadingLayer* createLayer();

	void sampleFunc();

private:
	LoadingLayer* _layer;
	int32_t _nextSceneId;

	std::thread* _thread;
	std::mutex _asyncMutex;
	std::mutex _sleepMutex;
	std::condition_variable _sleepCondition;
	bool _end;

	// sample
	float _count;
};


#endif // __LOADING_SCENE_H__
