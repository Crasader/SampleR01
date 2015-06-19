#include "LoadingLayer.h"
#include "Common/CommonTextureManager.h"
#include "TLib/TSprite.h"

//using namespace std;

USING_NS_CC;

LoadingLayer::LoadingLayer()
: _active(false)
{
}
LoadingLayer::~LoadingLayer()
{
}

// on "init" you need to initialize your instance
bool LoadingLayer::init()
{
	if (!TLayer::init())
	{
		return false;
	}

	Director* director = Director::getInstance();
	Size visibleSize = director->getVisibleSize();
	Point origin = director->getVisibleOrigin();

	_sprite = CommonTextureManager::getSprite("icon_processing01.png");
	_sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(_sprite, 0);

	this->scheduleUpdate();

	_active = true;
	_count = 0;

	return true;
}

void LoadingLayer::update(float delta)
{
	TLayer::update(delta);
	if (_active) {
		_count += delta;
		_sprite->setRotation(_count * 360.0f);
	}
}
