//
//  CommonTextureManager.h
//

#ifndef __COMMON_TEXTURE_MANAGER_H__
#define __COMMON_TEXTURE_MANAGER_H__

#include "TLib/TLib.h"

class CommonTextureManager : TTextureManager
{
private:
    CommonTextureManager();
    ~CommonTextureManager();
    
public:
    static CommonTextureManager* create();
    static void destroy();

	static TSprite* getSprite(string filename);

	template<class T>
	static T* getSprite(string filename)
	{
		return t_utility::createWithSpriteFrameName<T>(filename.c_str());
	}

private:
	bool init();

private:
	static CommonTextureManager* s_manager;
};


#endif // __COMMON_TEXTURE_MANAGER_H__
