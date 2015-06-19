#ifndef __T_LAYER_H__
#define __T_LAYER_H__

#include "cocos2d.h"
USING_NS_CC;

class TLayer : public cocos2d::Layer
{
public:
	TLayer();
	virtual ~TLayer();

	CREATE_FUNC(TLayer);

	virtual bool init();
	virtual void update(float delta);

	virtual void onEnter();
	virtual void onExit();

	virtual void onEnterTransitionDidFinish();
	virtual void onExitTransitionDidStart();

	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
	virtual void onTouchCancelled(Touch *pTouch, Event *pEvent);

	virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *pEvent);
	virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *pEvent);
	virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *pEvent);
	virtual void onTouchesCancelled(const std::vector<Touch*>& touches, Event *pEvent);

	virtual void onAcceleration(Acceleration* pAccelerationValue, Event *pEven);
};

#endif // __T_LAYER_H__
