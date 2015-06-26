#ifndef __LOADING_LAYER_H__
#define __LOADING_LAYER_H__

//#include "cocos2d.h"
#include "TLib/TLayer.h"

class TSprite;

class LoadingLayer : public TLayer
{
private:
	LoadingLayer();
	~LoadingLayer();

	bool init();

public:
	CREATE_FUNC(LoadingLayer);
	void update(float delta);

	void setActive(bool active) { _active = active;  _count = 0.0f; }

private:
	TSprite* _sprite;
    
	float _count;
	bool _active;
};

#endif // __LOADING_LAYER_H__
