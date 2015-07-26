#include "TUtility.h"

namespace t_utility {

	/////////////////////////////////////////////
	// DrawNode関連
	DrawNode* createDrawNode(const Rect& rect, const Color4F& color, float borderWidth, const Color4F& borderColor)
	{
		DrawNode *node = DrawNode::create();
		Vec2 verts[] = { Vec2(rect.origin.x, rect.origin.y), Vec2(rect.origin.x + rect.size.width, rect.origin.y),
			Vec2(rect.origin.x + rect.size.width, rect.origin.y + rect.size.height), Vec2(rect.origin.x, rect.origin.y + rect.size.height) };
		if (node) {
			node->drawPolygon(verts, 4, color, borderWidth, borderColor);
		}
		return node;
	}

	/////////////////////////////////////////////
	// random関連
	static uint32_t x = 123456789;
	static uint32_t y = 362436069;
	static uint32_t z = 521288629;
	static uint32_t w = 88675123;

	uint32_t randomXorShift()
	{
		uint32_t t;

		t = x ^ (x << 11);
		x = y; y = z; z = w;
		return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
	}
	void setRandomSeed(uint32_t seed)
	{
		w = seed;
	}

	/////////////////////////////////////////////
	// time関連
	double getSecond()
	{
		struct timeval tv;
		gettimeofday(&tv, NULL);
		return tv.tv_sec;
	}

	/////////////////////////////////////////////
	// 便利関数
	bool isContainPoint(const Vec2& position, const Size& size, const Vec2& location)
	{
		Rect rect(position.x, position.y, size.width, size.height);
		return rect.containsPoint(location);
	}

	/////////////////////////////////////////////
	// Json関連
	extern bool readJson(const char* jsonFileName, char*& buffer, rapidjson::Document& reader)
	{
		Data data = FileUtils::getInstance()->getDataFromFile(jsonFileName);
		ssize_t size = data.getSize();

		if (size <= 0) {
			assert(0);
			return false;
		}

		// json need null-terminated string.
		buffer = new char[size + 1];
		memcpy(buffer, data.getBytes(), size);
		(buffer)[size] = '\0';
		if (reader.ParseInsitu<0>(buffer).HasParseError())
		{
			assert(0);
			CC_SAFE_DELETE_ARRAY(buffer);
			return false;
		}
		return true;
	}
}
