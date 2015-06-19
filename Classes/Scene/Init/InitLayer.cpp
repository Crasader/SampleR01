#include "InitLayer.h"
#include "Scene/SceneManager.h"
//#include "Data/DataManager.h"
#include "Common/CommonDialog.h"

USING_NS_CC;

InitLayer::InitLayer()
{
}
InitLayer::~InitLayer()
{
}

bool InitLayer::init()
{
	if (!TLayer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = Label::createWithSystemFont("Init Scene", "Arial", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
							origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch *touch, Event*event)->bool{ return true; };
	listener->onTouchEnded = CC_CALLBACK_2(InitLayer::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void InitLayer::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	SceneManager::changeScene(SceneManager::SCENE_TITLE, true);
}
