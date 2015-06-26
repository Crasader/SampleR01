#ifndef __GAME_BOMB_LAYER_H__
#define __GAME_BOMB_LAYER_H__

#include "TLib/TLayer.h"

class GameBombLayer : public TLayer
{
public:
	GameBombLayer();
	~GameBombLayer();

	CREATE_FUNC(GameBombLayer);
	bool init();

	void onTouchEnded(Touch *pTouch, Event *pEvent);
};

#endif // __GAME_BOMB_LAYER_H__
