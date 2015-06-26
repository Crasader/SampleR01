#ifndef __HOME_LAYER_H__
#define __HOME_LAYER_H__

#include "TLib/TLayer.h"



class HomeLayer : public TLayer
{
private:
	HomeLayer();
	~HomeLayer();

	bool init();

public:
	CREATE_FUNC(HomeLayer);

	bool onTouchBegan(Touch *pTouch, Event *pEvent);
	void onTouchMoved(Touch *pTouch, Event *pEvent);
	void onTouchEnded(Touch *pTouch, Event *pEvent);
	void onTouchCancelled(Touch *pTouch, Event *pEvent);

private:
	void updateMap();
	void moveMap(Vec2 dir);

private:
	TMXTiledMap* _tiledMap;
	Vec2 _mapScreenPos;
};

#endif // __HOME_LAYER_H__
