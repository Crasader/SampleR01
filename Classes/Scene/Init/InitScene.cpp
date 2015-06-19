#include "Scene/SceneManager.h"
#include "InitScene.h"
#include "InitLayer.h"

InitScene::InitScene()
:_layer(NULL)
{}
InitScene::~InitScene()
{}

bool InitScene::init()
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

InitLayer* InitScene::createLayer()
{
	_layer = InitLayer::create();
	return _layer;
}
