#include "TScene.h"

TScene::TScene()
{
}

TScene::~TScene()
{
}

bool TScene::init()
{
	if (Scene::init()) {
#ifdef DISP_SCENE_NAME
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();

		auto label = Label::createWithSystemFont(_sceneName.c_str(), "Arial", 24);
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));
		this->addChild(label, 100);
#endif // DISP_SCENE_NAME
		return true;
	}

	return false;
}
void TScene::update(float delta)
{
	Scene::update(delta);
}


void TScene::onEnter(){ Scene::onEnter(); }
void TScene::onExit(){ Scene::onExit(); }

void TScene::onEnterTransitionDidFinish(){ Scene::onEnterTransitionDidFinish(); }
void TScene::onExitTransitionDidStart(){ Scene::onExitTransitionDidStart(); }

