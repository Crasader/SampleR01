//
//  CommonTextureManager.cpp
//

#include "cocos2d.h"
#include "CommonTextureManager.h"
#include "TLib/TUtility.h"

USING_NS_CC;

CommonTextureManager* CommonTextureManager::s_manager = NULL;

CommonTextureManager::CommonTextureManager(){
}
CommonTextureManager::~CommonTextureManager()
{
}

CommonTextureManager* CommonTextureManager::create()
{
	if (!s_manager){
		s_manager = new CommonTextureManager();

		if (s_manager && s_manager->init()){
			return s_manager;
        }
		else if (s_manager){
            destroy();
        }
    }
	return s_manager;
}

void CommonTextureManager::destroy()
{
	if (s_manager) {
		delete s_manager;
		s_manager = NULL;
    }
}

bool CommonTextureManager::init()
{
	SpriteFrameCache* spriteFrameCache = SpriteFrameCache::getInstance();
	spriteFrameCache->addSpriteFramesWithFile("common.plist");
	return true;
}

TSprite* CommonTextureManager::getSprite(string filename)
{
	return getSprite<TSprite>(filename.c_str());
}

