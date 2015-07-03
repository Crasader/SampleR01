#include  "TAnimationController.h"


#if 0
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

struct TAnimationDataSpriteName
{
	int32_t _spriteNameSize;
};

struct TAnimationData
{
	int32_t _dataId;
	int32_t _chunkNum;
	int32_t _spriteNum;
	int32_t _padding[5];
};

class TAnimationController : public Node
{
	virtual void update(float delta);

	virtual void playAnimation(int32_t animId);
	virtual void stopAnimation();

private:
	TAnimationCore* _animationCore;
	std::vector<TSprite*> _spriteList;

	float _count;
	int32_t _animationId;
};

#endif

TAnimationCore::TAnimationCore()
{

}

TAnimationCore::~TAnimationCore()
{

}

TAnimationCore* TAnimationCore::createAnimationData(std::string fileName)
{
	TAnimationCore* animationCore = new TAnimationCore();

	if (animationCore && !animationCore->init(fileName)) {
		CC_SAFE_DELETE(animationCore);
	}

	return animationCore;
}

bool TAnimationCore::init(std::string fileName)
{

	Data data = FileUtils::getInstance()->getDataFromFile(fileName);
	ssize_t size = data.getSize();

	TAnimationData* animData = (TAnimationData*)data.getBytes();
	if (animData && (animData->_dataId == 0x01111111)) {
		int32_t spriteNum = animData->_spriteNum;
		int32_t chunkNum = animData->_chunkSize;
		if (spriteNum <= 0 || chunkNum <= 0) {
			CC_ASSERT(false);
			return false;
		}

		_animetionDataCunkList._spriteNameList.reserve(spriteNum);
		_animetionDataCunkList._animationDataChunkList.reserve(chunkNum);

		// chunk buffer
		unsigned char* address = data.getBytes() + sizeof(TAnimationData);
		for (int i = 0; i < chunkNum; ++i) {
			TAnimationDataChunkData* chunkData = (TAnimationDataChunkData*)address;
			TAnimationDataChunk chunk;
			chunk._loop = chunkData->_loop;
			chunk._animationdataCore.reserve(chunkData->_chunkNum);

			for (int ch = 0; ch < chunkData->_chunkNum; ch++) {
				TAnimationDataCore animDataCore = *(TAnimationDataCore*)(address + sizeof(TAnimationDataChunkData));
				chunk._animationdataCore.push_back(animDataCore);
			}

			_animetionDataCunkList._animationDataChunkList.push_back(chunk);

			address += (sizeof(TAnimationDataChunkData) + sizeof(TAnimationDataCore) * chunkData->_chunkNum);
		}

		// sprite name buffer
		address = data.getBytes() + sizeof(TAnimationData) + animData->_chunkSize;
		for (int i = 0; i < spriteNum; ++i) {
			TAnimationDataSpriteNameData* spriteNameData = (TAnimationDataSpriteNameData*)address;

			std::string spriteName = spriteNameData->_buffer;
			_animetionDataCunkList._spriteNameList.push_back(spriteName);

			address += (sizeof(int32_t) + spriteNameData->_spriteNameSize);
		}


		return true;
	}

	return false;
}

const TAnimationDataChunk& TAnimationCore::getAnimationData(int32_t animId)
{
	return _animetionDataCunkList._animationDataChunkList[animId];
}


TAnimationController::TAnimationController()
{}

TAnimationController::~TAnimationController()
{}

TAnimationController* TAnimationController::create(std::string fileName)
{
	TAnimationController* animationController = new TAnimationController();
	if (animationController && !animationController->init(fileName)) {
		CC_SAFE_DELETE(animationController);
	}
	return animationController;
}

bool TAnimationController::init(std::string fileName)
{
	_animationCore = TAnimationCore::createAnimationData(fileName);

	return (_animationCore != NULL);
}

void TAnimationController::update(float delta)
{

}

void TAnimationController::playAnimation(int32_t animId)
{

}

void TAnimationController::stopAnimation()
{

}

