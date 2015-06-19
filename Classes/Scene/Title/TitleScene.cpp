#include "Scene/SceneManager.h"
#include "TitleScene.h"
#include "TitleLayer.h"

TitleScene::TitleScene()
{}
TitleScene::~TitleScene()
{}

bool TitleScene::init()
{
	if (!TScene::init())
	{
		return false;
	}

	// 'layer' is an autorelease object
	createLayer();

	// add layer as a child to scene
	this->addChild(_layer);

	return true;
}

void TitleScene::update(float delta)
{
	TScene::update(delta);
}

TitleLayer* TitleScene::createLayer()
{
	_layer = TitleLayer::create();
	return _layer;
}
