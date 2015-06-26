#include "HomeLayer.h"


USING_NS_CC;

HomeLayer::HomeLayer()
{
}
HomeLayer::~HomeLayer()
{
}

bool HomeLayer::init()
{
	if (!TLayer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_tiledMap = TMXTiledMap::create("isometric_grass_and_water.tmx");
	// スクリーンの中心とマップの中心を合わせる
	Rect mapRect = _tiledMap->getBoundingBox();
	_mapScreenPos = Vec2(visibleSize.width / 2 - mapRect.size.width / 2, visibleSize.height / 2 - mapRect.size.height / 2);
	_tiledMap->setPosition(_mapScreenPos);
	this->addChild(_tiledMap);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch *touch, Event*event)->bool{ return true; };
	listener->onTouchMoved = CC_CALLBACK_2(HomeLayer::onTouchMoved, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

bool HomeLayer::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	return TLayer::onTouchBegan(pTouch, pEvent);
}

void HomeLayer::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	if (pTouch) {
		Vec2 delta = pTouch->getDelta();
		moveMap(delta);
	}
}

void HomeLayer::onTouchEnded(Touch *pTouch, Event *pEvent)
{
}

void HomeLayer::onTouchCancelled(Touch *pTouch, Event *pEvent)
{

}

void HomeLayer::updateMap()
{
}

void HomeLayer::moveMap(Vec2 dir)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Rect mapRect = _tiledMap->getBoundingBox();

	_mapScreenPos.x += dir.x;

	if (_mapScreenPos.x <= -mapRect.size.width + visibleSize.width) {
		_mapScreenPos.x = -mapRect.size.width + visibleSize.width;
	}
	if (_mapScreenPos.x >= 0) {
		_mapScreenPos.x = 0;
	}

	_tiledMap->setPosition(_mapScreenPos);
}
