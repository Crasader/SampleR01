#include "TScene.h"

TScene::TScene()
{
}

TScene::~TScene()
{
}

bool TScene::init()
{
	return Scene::init();
}
void TScene::update(float delta)
{
	Scene::update(delta);
}


void TScene::onEnter(){ Scene::onEnter(); }
void TScene::onExit(){ Scene::onExit(); }

void TScene::onEnterTransitionDidFinish(){ Scene::onEnterTransitionDidFinish(); }
void TScene::onExitTransitionDidStart(){ Scene::onExitTransitionDidStart(); }

