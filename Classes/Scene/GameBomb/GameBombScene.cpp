#include "Scene/SceneManager.h"
#include "GameBombScene.h"
#include "GameBombLayer.h"

GameBombScene::GameBombScene()
: _layer(NULL)
{
#ifdef DISP_SCENE_NAME
	_sceneName = "GameBombScene";
#endif // DISP_SCENE_NAME
}
GameBombScene::~GameBombScene()
{}

bool GameBombScene::init()
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

GameBombLayer* GameBombScene::createLayer()
{
	_layer = GameBombLayer::create();
	return _layer;
}
