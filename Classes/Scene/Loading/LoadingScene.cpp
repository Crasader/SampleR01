#include "Scene/SceneManager.h"
#include "LoadingScene.h"
#include "LoadingLayer.h"

LoadingScene::LoadingScene()
: _thread(NULL)
{}
LoadingScene::~LoadingScene()
{
	CC_SAFE_DELETE(_thread);
}

bool LoadingScene::init()
{
	if (!TScene::init())
	{
		return false;
	}

	// 'layer' is an autorelease object
	createLayer();

	// add layer as a child to scene
	this->addChild(_layer);
	this->scheduleUpdate();

	return true;
}

LoadingLayer* LoadingScene::createLayer()
{
	_layer = LoadingLayer::create();
	return _layer;
}

void LoadingScene::update(float delta)
{
	TScene::update(delta);
	if (isLoaded()) {
		SceneManager::changeScene((SceneManager::SCENE_ID)_nextSceneId, false);
		this->unscheduleUpdate();
		return;
	}
	// sample
	_count += delta;

//	_sleepCondition.notify_one();
}

void LoadingScene::set(int32_t nextSceneId)
{
	_nextSceneId = nextSceneId;
	_end = false;

	// sample
	if (_nextSceneId == SceneManager::SCENE_TITLE) {
		sampleFunc();
	}
	if (_nextSceneId == SceneManager::SCENE_HOME) {
		setEnd();
	}

//	_sleepCondition.notify_one();
}

bool LoadingScene::isLoaded()
{
	return _end;
}

void LoadingScene::setEnd()
{
	std::lock_guard<std::mutex> lg(_asyncMutex);
	_end = true;

	if (_thread) {
		_thread->join();
	}
}

void LoadingScene::sampleFunc()
{
	_count = 0;

	_thread = new std::thread([this](){
		while (true)
		{
			std::lock_guard<std::mutex> lg(_asyncMutex);
			if (_count >= 1.5f) {
				break;
			}
			else {
				int k = 0;
				while (k <= 100) {
					++k;
					log("%d", k);
				}

//				std::unique_lock<std::mutex> lk(_sleepMutex);
//				_sleepCondition.wait(lk);
				continue;
			}
		}

		Director::getInstance()->getScheduler()->performFunctionInCocosThread(CC_CALLBACK_0(LoadingScene::setEnd, this));
	});
}
