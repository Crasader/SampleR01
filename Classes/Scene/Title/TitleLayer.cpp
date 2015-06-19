#include "Scene/SceneManager.h"
#include "TitleLayer.h"
#include "Common/CommonTextureManager.h"
#include "Common/CommonDialog.h"
#include "Sound/SoundManager.h"


USING_NS_CC;

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


	TSprite* sprite = CommonTextureManager::getSprite<TSprite>("HelloWorld.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	TSprite* spriteStart = CommonTextureManager::getSprite<TSprite>("bt_option01.png");
	TSprite* spriteStartSelected = CommonTextureManager::getSprite<TSprite>("bt_option02.png");
	MenuItemSprite* btnItem = MenuItemSprite::create(spriteStart, spriteStartSelected, CC_CALLBACK_1(TitleLayer::callBackStartBtn, this));
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
#else
	{
#endif
#if 0
		SceneManager::changeScene(SceneManager::SCENE_HOME, true);
#else
		// sample
		static int bgmID = 0;
		BGM_MANAGER()->play(bgmID, true);
		bgmID = (bgmID == 0) ? 1 : 0;
#endif
	}
}

void TitleLayer::callBackOptionBtn(Ref* pSender)
{
}


