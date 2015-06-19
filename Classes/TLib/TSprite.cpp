#include "TSprite.h"


TSprite::TSprite()
{
}


TSprite::~TSprite()
{
}

TSprite* TSprite::createWithSpriteFrame(SpriteFrame *spriteFrame)
{
	TSprite* sprite = new TSprite();
	if (spriteFrame && sprite && sprite->initWithSpriteFrame(spriteFrame)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

bool TSprite::init()
{
	return Sprite::init();
}

void TSprite::update(float delta)
{
	Sprite::update(delta);
}

void TSprite::onEnter()
{
	Sprite::onEnter();
}
void TSprite::onExit()
{
	Sprite::onExit();
}

void TSprite::onEnterTransitionDidFinish()
{
	Sprite::onEnterTransitionDidFinish();
}
void TSprite::onExitTransitionDidStart()
{
	Sprite::onExitTransitionDidStart();
}
