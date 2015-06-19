#ifndef __T_UTILITY_H__
#define __T_UTILITY_H__


#include "cocos2d.h"
//#include "json/rapidjson.h"
#include "json/document.h"

USING_NS_CC;

namespace t_utility
{
	/////////////////////////////////////////////
	// sprite関連
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
	// DrawNode関連
	extern DrawNode* createDrawNode(const Rect& rect, const Color4F& color, float borderWidth, const Color4F& borderColor);

	/////////////////////////////////////////////
	// random関連
	extern uint32_t randomXorShift();
	extern void setRandomSeed(uint32_t seed);

	/////////////////////////////////////////////
	// time関連
	extern double getSecond();

	/////////////////////////////////////////////
	// 便利関数
	extern bool isContainPoint(const Vec2& position, const Size& size, const Vec2& location);

	/////////////////////////////////////////////
	// Json関連
	extern bool readJson(const char* jsonFileName, char* buffer, rapidjson::Document& reader);
}

#endif // __T_UTILITY_H__
