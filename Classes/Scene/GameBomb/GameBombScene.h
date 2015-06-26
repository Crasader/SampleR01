#ifndef __GAME_BOMB_SCENE_H__
#define __GAME_BOMB_SCENE_H__

#include "TLib/TScene.h"

class GameBombLayer;

class GameBombScene : public TScene
{
public:
	GameBombScene();
	~GameBombScene();

	CREATE_FUNC(GameBombScene);
	bool init();

private:
	GameBombLayer* createLayer();

private:
	GameBombLayer* _layer;

};


#endif // __GAME_BOMB_SCENE_H__
