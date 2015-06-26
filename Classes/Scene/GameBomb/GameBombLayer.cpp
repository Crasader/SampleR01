#include "GameBombLayer.h"
#include "Scene/SceneManager.h"

USING_NS_CC;

GameBombLayer::GameBombLayer()
{
}
GameBombLayer::~GameBombLayer()
{
}

bool GameBombLayer::init()
{
	if (!TLayer::init())
	{
		return false;
	}

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch *touch, Event*event)->bool{ return true; };
	listener->onTouchEnded = CC_CALLBACK_2(GameBombLayer::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void GameBombLayer::onTouchEnded(Touch *pTouch, Event *pEvent)
{
}
