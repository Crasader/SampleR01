#include "Scene/SceneManager.h"
#include "TitleLayer.h"
#include "Common/CommonTextureManager.h"
#include "Common/CommonDialog.h"
#include "Sound/SoundManager.h"


USING_NS_CC;

// TTouchSprite Sample
class TouchSprite : public TTouchSprite {
public:
	TouchSprite();
	~TouchSprite();

	static TouchSprite* createWithSpriteFrame(SpriteFrame *spriteFrame);

	bool initWithSpriteFrame(SpriteFrame *spriteFrame);

	bool onTouchBegan(Touch *pTouch, Event *pEvent);
	void onTouchEnded(Touch *pTouch, Event *pEvent);
};

TouchSprite::TouchSprite()
{
}


TouchSprite::~TouchSprite()
{
}

TouchSprite* TouchSprite::createWithSpriteFrame(SpriteFrame *spriteFrame)
{
	TouchSprite* sprite = new TouchSprite();
	if (spriteFrame && sprite && sprite->initWithSpriteFrame(spriteFrame)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

bool TouchSprite::initWithSpriteFrame(SpriteFrame *spriteFrame)
{
	if (TSprite::initWithSpriteFrame(spriteFrame)) {
		auto dispatcher = Director::getInstance()->getEventDispatcher();
		_listener = EventListenerTouchOneByOne::create();
		_listener->onTouchBegan = CC_CALLBACK_2(TouchSprite::onTouchBegan, this);
		_listener->onTouchEnded = CC_CALLBACK_2(TouchSprite::onTouchEnded, this);
		dispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
		return true;
	}
	return false;
}

bool TouchSprite::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	return TTouchSprite::onTouchBegan(pTouch, pEvent);
}
void TouchSprite::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	SceneManager::changeScene(SceneManager::SCENE_HOME, true);
}

// TTouchSprite Sample


TitleLayer::TitleLayer()
{
}
TitleLayer::~TitleLayer()
{
}

bool TitleLayer::init()
{
	if (!TLayer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// TTouchSprite Sample
	TouchSprite* sprite = CommonTextureManager::getSprite<TouchSprite>("HelloWorld.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	TSprite* spriteStart = CommonTextureManager::getSprite<TSprite>("bt_option01.png");
	TSprite* spriteStartSelected = CommonTextureManager::getSprite<TSprite>("bt_option02.png");
	MenuItemSprite* btnItem = MenuItemSprite::create(spriteStart, spriteStartSelected, CC_CALLBACK_1(TitleLayer::callBackOptionBtn, this));
	Menu* btn = Menu::create(btnItem, NULL);
	btn->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 300));
	this->addChild(btn, 5);

	return true;
}

void TitleLayer::callBackStartBtn(Ref* pSender)
{
	log("callBackStartBtn");
#if 0
	// メンテナンス中か
	if (0) {
		CommonDialog::create(CommonDialog::Ok, "メンテナンス中です", NULL, NULL);
	}
	// ユーザー登録しているか
	else if (!GET_USER_DATA().isValid()) {
		SceneManager::changeScene(SceneManager::SCENE_USERREGIST, true);
	}
	else {
	}
#else
#if 0
	{
		SceneManager::changeScene(SceneManager::SCENE_HOME, true);
	}
#endif
#endif
}

void TitleLayer::callBackOptionBtn(Ref* pSender)
{
	// sample
	static int bgmID = 0;
	BGM_MANAGER()->play(bgmID, true);
	bgmID = (bgmID == 0) ? 1 : 0;
}


