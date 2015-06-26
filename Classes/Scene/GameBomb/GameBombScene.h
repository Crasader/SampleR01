#ifndef __GAME_BOMB_SCENE_H__
#define __GAME_BOMB_SCENE_H__

#include "TLib/TScene.h"

class GameBombLayer;

class GameBombScene : public TScene
{
private:
	GameBombScene();
	~GameBombScene();

	bool init();

public:
	CREATE_FUNC(GameBombScene);

private:
	GameBombLayer* createLayer();

private:
	GameBombLayer* _layer;

};


#endif // __GAME_BOMB_SCENE_H__
