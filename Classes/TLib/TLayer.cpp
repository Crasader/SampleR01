#include "TLayer.h"
//#include "TUtility.h"

//using namespace t_utility;

TLayer::TLayer()
{
}

TLayer::~TLayer()
{
}

bool TLayer::init()
{
	return Layer::init();
}

void TLayer::update(float delta)
{
	Layer::update(delta);
}

void TLayer::onEnter()
{
//	Log("onEnter");
	Layer::onEnter();
}
void TLayer::onExit()
{
//	Log("onExit");
	Layer::onExit();
}

void TLayer::onEnterTransitionDidFinish()
{
	//	Log("onEnterTransitionDidFinish");
	Layer::onEnterTransitionDidFinish();
}
void TLayer::onExitTransitionDidStart()
{
	//	Log("onExitTransitionDidStart");
	Layer::onExitTransitionDidStart();
}

bool TLayer::onTouchBegan(Touch *pTouch, Event *pEvent)
{
//	CCLog("ccTouchBegan");
	return true;
//	return tnk_utility::isContainPoint(getPosition(), getContentSize(), pTouch->getLocation());
}
void TLayer::onTouchMoved(Touch *pTouch, Event *pEvent)
{
//	CCLog("ccTouchMoved");
}
void TLayer::onTouchEnded(Touch *pTouch, Event *pEvent)
{
//	CCLog("onTouchended");
}
void TLayer::onTouchCancelled(Touch *pTouch, Event *pEvent)
{
//	CCLog("ccTouchCancelled");
}

void TLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event *pEvent)
{
//	CCLog("onTouchesBegan");
}
void TLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event *pEvent)
{
//	CCLog("onTouchesMoved");
}
void TLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event *pEvent)
{
//	CCLog("onTouchesEnded");
}
void TLayer::onTouchesCancelled(const std::vector<Touch*>& touches, Event *pEvent)
{
//	CCLog("onTouchesCancelled");
}

void TLayer::onAcceleration(Acceleration* pAccelerationValue, Event *pEven)
{
//	CCLog("didAccelerate");
	Layer::onAcceleration(pAccelerationValue, pEven);
}
