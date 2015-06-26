#ifndef __T_TOUCH_SPRITE_H__
#define __T_TOUCH_SPRITE_H__

#include "TSprite.h"

class TTouchSprite : public TSprite
{
protected:
	TTouchSprite();
	virtual ~TTouchSprite();

	virtual bool initWithSpriteFrame(SpriteFrame *spriteFrame);

public:
	CREATE_FUNC(TTouchSprite);
	static TTouchSprite* createWithSpriteFrame(SpriteFrame *spriteFrame);

	virtual void update(float delta);

	virtual void onEnter();
	virtual void onExit();

	virtual void onEnterTransitionDidFinish();
	virtual void onExitTransitionDidStart();

	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
	virtual void onTouchCancelled(Touch *pTouch, Event *pEvent);

	virtual bool isContainedLocation(Touch *pTouch);

protected:
	EventListenerTouchOneByOne* _listener; 

private:
#if 0
	bool m_regist;
	int m_nTouchPriority;
#endif
};

#endif // __T_TOUCH_SPRITE_H__
