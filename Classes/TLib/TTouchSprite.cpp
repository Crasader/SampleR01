#include "TTouchSprite.h"


TTouchSprite::TTouchSprite()
//: m_regist(false)
{
}


TTouchSprite::~TTouchSprite()
{
//	unregisterScriptTouchHandler();
}

TTouchSprite* TTouchSprite::createWithSpriteFrame(SpriteFrame *spriteFrame)
{
	TTouchSprite* sprite = new TTouchSprite();
	if (spriteFrame && sprite && sprite->initWithSpriteFrame(spriteFrame)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

bool TTouchSprite::initWithSpriteFrame(SpriteFrame *spriteFrame)
{
	if (TSprite::initWithSpriteFrame(spriteFrame)) {
#if 0
		// sample
		auto dispatcher = Director::getInstance()->getEventDispatcher();
		_listener = EventListenerTouchOneByOne::create();
		_listener->onTouchBegan = CC_CALLBACK_2(TTouchSprite::onTouchBegan, this);
		_listener->onTouchMoved = CC_CALLBACK_2(TTouchSprite::onTouchMoved, this);
		_listener->onTouchEnded = CC_CALLBACK_2(TTouchSprite::onTouchEnded, this);
		_listener->onTouchCancelled = CC_CALLBACK_2(TTouchSprite::onTouchCancelled, this);
		dispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
#endif
		return true;
	}
	return false;
}

void TTouchSprite::update(float delta)
{
	TSprite::update(delta);
}

void TTouchSprite::onEnter()
{
	TSprite::onEnter();
}
void TTouchSprite::onExit()
{
	TSprite::onExit();
}

void TTouchSprite::onEnterTransitionDidFinish()
{
	TSprite::onEnterTransitionDidFinish();
}
void TTouchSprite::onExitTransitionDidStart()
{
	TSprite::onExitTransitionDidStart();
}

bool TTouchSprite::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	//	Log("onTouchBegan");

	// 親がvisibleかは自前でチェック
	for (Node *c = this->_parent; c != NULL; c = c->getParent()) {
		if (c->isVisible() == false) {
			return false;
		}
	}
	if (!isContainedLocation(pTouch)) return false;

	return true;
}
void TTouchSprite::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	//if (!isContainedLocation(pTouch)) return;
}
void TTouchSprite::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	//if (!isContainedLocation(pTouch)) return;
}
void TTouchSprite::onTouchCancelled(Touch *pTouch, Event *pEvent)
{
	//if (!isContainedLocation(pTouch)) return;
}

bool TTouchSprite::isContainedLocation(Touch *pTouch)
{
	Vec2 touchLocation = pTouch->getLocation();

	if (isVisible()) {
		Vec2 local = convertToNodeSpace(touchLocation);
		Rect r = Rect(getPositionX() - getContentSize().width * getAnchorPoint().x,
			getPositionY() - getContentSize().height * getAnchorPoint().y,
			getContentSize().width, getContentSize().height);
		r.origin = Vec2::ZERO;
		if (r.containsPoint(local)) {
			return true;
		}
	}

	return false;
}
