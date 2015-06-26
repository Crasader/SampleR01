#include "Scene/SceneManager.h"
#include "HomeScene.h"
#include "HomeLayer.h"

HomeScene::HomeScene()
: _layer(NULL)
{
#ifdef DISP_SCENE_NAME
	_sceneName = "HomeScene";
#endif // DISP_SCENE_NAME
}
HomeScene::~HomeScene()
{}

bool HomeScene::init()
{
	if (!TScene::init())
	{
		return false;
	}

	// 'layer' is an autorelease object
	createLayer();

	// add layer as a child to scene
	this->addChild(_layer);

	//	this->scheduleUpdate();

	return true;
}

HomeLayer* HomeScene::createLayer()
{
	_layer = HomeLayer::create();
	return _layer;
}
