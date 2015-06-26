#ifndef __T_SPRITE_H__
#define __T_SPRITE_H__

#include "cocos2d.h"
USING_NS_CC;

class TSprite : public cocos2d::Sprite
{
protected:
	TSprite();
	virtual ~TSprite();

	virtual bool init();

public:
	CREATE_FUNC(TSprite);
	static TSprite* createWithSpriteFrame(SpriteFrame *spriteFrame);

	virtual void update(float delta);

	virtual void onEnter();
	virtual void onExit();

	virtual void onEnterTransitionDidFinish();
	virtual void onExitTransitionDidStart();
};

#endif // __T_SPRITE_H__
