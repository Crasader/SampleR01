#ifndef __T_ANIMATION_CONTROLLER_H__
#define __T_ANIMATION_CONTROLLER_H__

#include "cocos2d.h"
#include <map>

USING_NS_CC;
using namespace std;

class TSprite;

// とりあえず同一テクスチャ内でのアニメーションを想定
// 

struct TAnimationDataCore
{
	int32_t _spriteNameID;
	int32_t _animType;
	float _startFrame;
	float _endFrame;

	Vec2 _fromPos;
	Vec2 _toPos;

	float _fromRotation;
	float _toRotation;
	float _fromScale;
	float _toScale;

	int32_t _padding[8];
};

struct TAnimationDataChunk
{
	int32_t _loop;
	std::vector<TAnimationDataCore> _animationdataCore;
};

struct TAnimationDataCunkList
{
	std::vector<std::string> _spriteNameList;
	std::vector<TAnimationDataChunk> _animationDataChunkList;
};

struct TAnimationDataSpriteNameData
{
	int32_t _spriteNameSize;
	char*	_buffer;
};

struct TAnimationDataChunkData
{
	int32_t _chunkNum;
	int32_t _loop;
};

struct TAnimationData
{
	int32_t _dataId;
	int32_t _chunkNum;
	int32_t _chunkSize;
	int32_t _spriteNum;
	int32_t _spriteSize;
	int32_t _padding[3];
};

class TAnimationCore : public Node
{
protected:
	TAnimationCore();
	virtual ~TAnimationCore();

	bool init(std::string fileName);

public:
	static TAnimationCore* createAnimationData(std::string fileName);

	const TAnimationDataCunkList& getAnimationDataChunkList() { return _animetionDataCunkList; }
	const TAnimationDataChunk& getAnimationData(int32_t animId);

private:
	TAnimationDataCunkList _animetionDataCunkList;
};

class TAnimationController : public Node
{
protected:
	TAnimationController();
	virtual ~TAnimationController();

	bool init(std::string fileName);

public:
	static TAnimationController* create(std::string fileName);

	virtual void update(float delta);

	virtual void playAnimation(int32_t animId);
	virtual void stopAnimation();

private:
	TAnimationCore* _animationCore;
	std::vector<TSprite*> _spriteList;

	float _count;
	int32_t _animationId;
};

#endif // __T_ANIMATION_CONTROLLER_H__

