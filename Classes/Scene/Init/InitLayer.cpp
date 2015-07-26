#include "InitLayer.h"
#include "Scene/SceneManager.h"
//#include "Data/DataManager.h"
#include "Common/CommonDialog.h"

USING_NS_CC;

InitLayer::InitLayer()
{
}
InitLayer::~InitLayer()
{
}

bool InitLayer::init()
{
	if (!TLayer::init())
	{
		return false;
	}

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch *touch, Event*event)->bool{ return true; };
	listener->onTouchEnded = CC_CALLBACK_2(InitLayer::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// rapidjson Test
	//readJsonTest();

	return true;
}

void InitLayer::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	SceneManager::changeScene(SceneManager::SCENE_TITLE, true);
}

// json sample
void InitLayer::readJsonTest()
{
	char* buffer = NULL;
	rapidjson::Document reader;
	if (t_utility::readJson("data/data_monster.json", buffer, reader)) {
		rapidjson::Value& monsters = reader["monsters"];
		int i, l = monsters.Size();
		for (i = 0; i < l; i++) {
			log("%s", monsters[rapidjson::SizeType(i)]["Name"].GetString());
		}
		CC_SAFE_DELETE_ARRAY(buffer);
	}
}
