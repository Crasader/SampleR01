#include "CommonDialog.h"
#include "CommonTextureManager.h"

CommonDialog::CommonDialog()
{}
CommonDialog::~CommonDialog()
{
}

CommonDialog* CommonDialog::create(DialogType type, const std::string& text, UPDATE_FUNC_POINTER funcUpdate, FUNC_POINTER funcEnd)
{
	CommonDialog* dialog = new CommonDialog();
	if (dialog && dialog->init(type, text))
	{
		dialog->autorelease();
		dialog->_funcUpdate = funcUpdate;
		dialog->_funcEnd = funcEnd;
	}
	else {
		CC_SAFE_DELETE(dialog);
	}
	return dialog;
}


bool CommonDialog::init(DialogType type, const std::string& text)
{
	if (!TModalDialog::init(type, text))
	{
		return false;
	}

	Size visibleSize = CCDirector::getInstance()->getVisibleSize();
	Vec2 origin = CCDirector::getInstance()->getVisibleOrigin();

	const Color3B fontColor(255, 255, 255);
	{
		auto label = Label::createWithSystemFont(_text.c_str(), "Arial", 24);
		label->setPosition(Vec2((84 + 154) / 2, visibleSize.height / 2 + 150 + 140));
		label->setColor(fontColor);
		this->addChild(label, 3);
	}

	if (_type == Ok) {
		TSprite* pSpriteOk = CommonTextureManager::getSprite("bt_ok01.png");
		TSprite* pSpriteOkSel = CommonTextureManager::getSprite("bt_ok02.png");
		MenuItemSprite* pBtnItem = MenuItemSprite::create(pSpriteOk, pSpriteOkSel, CC_CALLBACK_1(CommonDialog::callBackOkBtn, this));
		Menu* pBtn = Menu::create(pBtnItem, NULL);
		pBtn->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 200));
		this->addChild(pBtn, 4);
#if 0
		listenerOk = EventListenerTouchOneByOne::create();
		listenerOk->onTouchBegan = [](Touch *touch, Event*event)->bool{ return true; };
		listenerOk->onTouchEnded = CC_CALLBACK_2(CommonDialog::onTouchEndedOkBtn, this);
		pBtnItem->getEventDispatcher()->addEventListenerWithFixedPriority(listenerOk, TOUCH_PRIORITY_DIALOG_BUTTON);
#endif
	}
	else if (_type == YesNo) {
		const int32_t buttonSize = 208;
		const int32_t padding = 20;
		TSprite* pSpriteYes = CommonTextureManager::getSprite("bt_yes01.png");
		TSprite* pSpriteYesSel = CommonTextureManager::getSprite("bt_yes02.png");
		MenuItemSprite* pBtnItem = MenuItemSprite::create(pSpriteYes, pSpriteYesSel, CC_CALLBACK_1(CommonDialog::callBackYesBtn, this));
		Menu* pBtn = Menu::create(pBtnItem, NULL);
		pBtn->setPosition(Vec2(visibleSize.width / 2 + origin.x - buttonSize / 2 - padding, visibleSize.height / 2 + origin.y - 200));
		this->addChild(pBtn, 5);

		TSprite* pSpriteNo = CommonTextureManager::getSprite("bt_no01.png");
		TSprite* pSpriteNoSel = CommonTextureManager::getSprite("bt_yes02.png");
		pBtnItem = MenuItemSprite::create(pSpriteNo, pSpriteNoSel, CC_CALLBACK_1(CommonDialog::callBackNoBtn, this));
		pBtn = Menu::create(pBtnItem, NULL);
		pBtn->setPosition(Vec2(visibleSize.width / 2 + origin.x + buttonSize / 2 + padding, visibleSize.height / 2 + origin.y - 200));
		this->addChild(pBtn, 5);
	}
	else if (_type == Controlled) {
		this->scheduleUpdate();
	}

	return true;
}

void CommonDialog::update(float delta)
{
	TModalDialog::update(delta);
}

void CommonDialog::onEnter()
{
	TModalDialog::onEnter();
}

void CommonDialog::onExit()
{
	TModalDialog::onExit();
}

void CommonDialog::callBackOkBtn(Ref* pSender)
{
	if (_funcEnd){
		_funcEnd();
	}
	TModalDialog::callBackOkBtn(pSender);
}

void CommonDialog::callBackYesBtn(Ref* pSender)
{
	if (_funcEnd){
		_funcEnd();
	}
	TModalDialog::callBackYesBtn(pSender);
}

void CommonDialog::callBackNoBtn(Ref* pSender)
{
	TModalDialog::callBackNoBtn(pSender);
}
