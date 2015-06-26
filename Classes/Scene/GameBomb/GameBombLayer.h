#ifndef __GAME_BOMB_LAYER_H__
#define __GAME_BOMB_LAYER_H__

#include "TLib/TLayer.h"

class GameBombLayer : public TLayer
{
private:
	GameBombLayer();
	~GameBombLayer();

	bool init();

public:
	CREATE_FUNC(GameBombLayer);

	void onTouchEnded(Touch *pTouch, Event *pEvent);
};

#endif // __GAME_BOMB_LAYER_H__
