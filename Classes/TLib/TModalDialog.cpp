#include "TModalDialog.h"



TModalDialog::TModalDialog()
: _funcUpdate(NULL)
, _funcEnd(NULL)
, _type(Controlled)
{}
TModalDialog::~TModalDialog()
{
}

TModalDialog* TModalDialog::create(DialogType type, const std::string& text, UPDATE_FUNC_POINTER funcUpdate, FUNC_POINTER funcEnd)
{
	TModalDialog* dialog = new TModalDialog();
	if (dialog && dialog->init(type, text))
	{
		dialog->autorelease();
		dialog->_funcUpdate = funcUpdate;
		dialog->_funcEnd = funcEnd;
		return dialog;
	}
	else {
		delete dialog;
		dialog = NULL;
		return NULL;
	}
}


bool TModalDialog::init(DialogType type, const std::string& text)
{
	if (!TLayer::init())
	{
		return false;
	}

	_text = text;
	_type = type;

	Director* director = Director::getInstance();
	Scene* scene = director->getRunningScene();
	if (scene) {
		scene->addChild(this, Z_ORDER_MODAL_DIALOG);
	}

	Size visibleSize = director->getVisibleSize();
	Vec2 origin = director->getVisibleOrigin();

	Rect nodeRect(0, 0, visibleSize.width, visibleSize.height);
	const Color4F color(0, 0, 0, 128.0f / 255);
	DrawNode *node = t_utility::createDrawNode(nodeRect, color, 0, color);
	this->addChild(node, 0);

	// cocos2dx 3.0
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = [](Touch *touch, Event*event)->bool{
		return true;
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void TModalDialog::update(float delta)
{
	TLayer::update(delta);
	bool isEnd = false;
	if (_funcUpdate == NULL){
		isEnd = true;
	}
	else {
		isEnd = _funcUpdate(delta);
	}
	if (isEnd) {
		Scene* scene = Director::getInstance()->getRunningScene();
		if (scene) {
			scene->removeChild(this);
		}
		if (_funcEnd){
			_funcEnd();
		}
	}
}

void TModalDialog::onEnter()
{
	TLayer::onEnter();
}

void TModalDialog::onExit()
{
	TLayer::onExit();
}

void TModalDialog::callBackOkBtn(Ref* pSender)
{
	Scene* scene = Director::getInstance()->getRunningScene();
	if (scene) {
		scene->removeChild(this);
	}
}

void TModalDialog::callBackYesBtn(Ref* pSender)
{
	Scene* scene = Director::getInstance()->getRunningScene();
	if (scene) {
		scene->removeChild(this);
	}
}

void TModalDialog::callBackNoBtn(Ref* pSender)
{
	Scene* scene = Director::getInstance()->getRunningScene();
	if (scene) {
		scene->removeChild(this);
	}
}
