#include "SoundTestLayer.h"
#include "Scene/SceneManager.h"
#include "Common/CommonTextureManager.h"
#include "Sound/SoundManager.h"

USING_NS_CC;

SoundTestLayer::SoundTestLayer()
{
}
SoundTestLayer::~SoundTestLayer()
{
}

bool SoundTestLayer::init()
{
	if (!TLayer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	TSprite* spriteStart = CommonTextureManager::getSprite<TSprite>("bt_option01.png");
	TSprite* spriteStartSelected = CommonTextureManager::getSprite<TSprite>("bt_option02.png");
	MenuItemSprite* btnItem = MenuItemSprite::create(spriteStart, spriteStartSelected, CC_CALLBACK_1(SoundTestLayer::callBackOptionBtn, this));
	Menu* btn = Menu::create(btnItem, NULL);
	btn->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 300));
	this->addChild(btn, 5);


	return true;
}

void SoundTestLayer::callBackOptionBtn(Ref* pSender)
{
	// sample
	static int bgmID = 0;
	BGM_MANAGER()->play(bgmID, true);
	bgmID = (bgmID == 0) ? 1 : 0;
}
