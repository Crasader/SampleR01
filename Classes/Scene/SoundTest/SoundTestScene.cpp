#include "Scene/SceneManager.h"
#include "SoundTestScene.h"
#include "SoundTestLayer.h"

SoundTestScene::SoundTestScene()
: _layer(NULL)
{
#ifdef DISP_SCENE_NAME
	_sceneName = "SoundTestScene";
#endif // DISP_SCENE_NAME
}
SoundTestScene::~SoundTestScene()
{}

bool SoundTestScene::init()
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

SoundTestLayer* SoundTestScene::createLayer()
{
	_layer = SoundTestLayer::create();
	return _layer;
}
