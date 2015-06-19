#include "SceneManager.h"
#include "TLib/TScene.h"
#include "Scene/Init/InitScene.h"
#include "Scene/Title/TitleScene.h"
#include "./Scene/Loading/LoadingScene.h"
#if 0
#include "./Scene/UserRegist/UserRegistScene.h"
#include "./Scene/Option/OptionScene.h"
#include "./Scene/Home/HomeScene.h"
#include "./Scene/Battle/BattleScene.h"
#endif

list<SceneManager::SCENE_ID> SceneManager::_listSceneId;

TScene* SceneManager::createScene(SCENE_ID sceneId)
{
	TScene* scene = NULL;
	switch (sceneId) {
	case SCENE_INIT:
		scene = InitScene::create();
		break;
	case SCENE_TITLE:
		scene = TitleScene::create();
		break;
	case SCENE_HOME:
//		scene = HomeScene::create();
		break;
//	case SCENE_BATTLE:
//		scene = BattleScene::create();
		break;
	case SCENE_LOADING:
		scene = LoadingScene::create();
		break;
//	case SCENE_USERREGIST:
//		scene = UserRegistScene::create();
//		break;
	case SCENE_OPTION:
//		scene = OptionScene::create();
		break;
	default:
		break;
	}
	scene->setSceneID(sceneId);

	return scene;
}

TScene* SceneManager::initScene()
{
	TScene *scene = createScene(SCENE_INIT);
	_listSceneId.push_back(SCENE_INIT);

	return scene;
}

TScene* SceneManager::changeScene(SCENE_ID sceneId, bool load)
{
	if (_listSceneId.size() == 0 || sceneId == (SCENE_ID)(*_listSceneId.rbegin())) {
		return NULL;
	}

	Director* pDirector = Director::getInstance();

	if (load) {
		LoadingScene* scene = (LoadingScene*)createScene(SCENE_LOADING);
		if (scene == NULL) {
			return NULL;
		}

		scene->set(sceneId);
		pDirector->replaceScene(scene);
		return NULL;
	}

	TScene* scene = createScene(sceneId);
	if (scene == NULL) {
		return NULL;
	}

	pDirector->replaceScene(scene);

	_listSceneId.pop_back();
	_listSceneId.push_back(sceneId);

	return scene;
}

TScene* SceneManager::pushScene(SCENE_ID sceneId)
{
	TScene* scene = createScene(sceneId);
	if (scene == NULL) {
		return NULL;
	}
	Director::getInstance()->pushScene(scene);

	_listSceneId.push_back(sceneId);

	return NULL;
}

TScene* SceneManager::popScene()
{
	Director::getInstance()->popScene();
	_listSceneId.pop_back();

	return NULL;
}


