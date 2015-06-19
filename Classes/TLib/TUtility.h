#ifndef __T_UTILITY_H__
#define __T_UTILITY_H__


#include "cocos2d.h"
//#include "json/rapidjson.h"
#include "json/document.h"

USING_NS_CC;

namespace t_utility
{
	/////////////////////////////////////////////
	// sprite�֘A
	template<class T>
	static T* createWithSpriteFrame(SpriteFrame *pSpriteFrame)
	{
		return T::createWithSpriteFrame(pSpriteFrame);
	}
	template<class T>
	static T* createWithSpriteFrameName(const char *pszSpriteFrameName)
	{
		SpriteFrame *pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pszSpriteFrameName);

		return createWithSpriteFrame<T>(pFrame);
	}

	/////////////////////////////////////////////
	// DrawNode�֘A
	extern DrawNode* createDrawNode(const Rect& rect, const Color4F& color, float borderWidth, const Color4F& borderColor);

	/////////////////////////////////////////////
	// random�֘A
	extern uint32_t randomXorShift();
	extern void setRandomSeed(uint32_t seed);

	/////////////////////////////////////////////
	// time�֘A
	extern double getSecond();

	/////////////////////////////////////////////
	// �֗��֐�
	extern bool isContainPoint(const Vec2& position, const Size& size, const Vec2& location);

	/////////////////////////////////////////////
	// Json�֘A
	extern bool readJson(const char* jsonFileName, char* buffer, rapidjson::Document& reader);
}

#endif // __T_UTILITY_H__
