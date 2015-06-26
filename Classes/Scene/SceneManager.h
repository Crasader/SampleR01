#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include "cocos2d.h"
#include <list>


using std::list;
class TScene;

USING_NS_CC;

class SceneManager
{
public:
	enum SCENE_ID {
		SCENE_INIT = 0,
		SCENE_TITLE,
		SCENE_OPENING,
		SCENE_HOME,
		SCENE_LOADING,
		SCENE_OPTION,
		SCENE_GAME_BOMB,
		SCENE_SOUND_TEST,
//		SCENE_USERREGIST,
	};

private:
	static TScene* createScene(SCENE_ID sceneId);

public:
	static TScene* initScene();
	static TScene* changeScene(SCENE_ID sceneId, bool load);
	static TScene* pushScene(SCENE_ID sceneId);
	static TScene* popScene();

private:
	static list<SCENE_ID> _listSceneId;
};



#endif // __SCENE_MANAGER_H__
