#ifndef __INIT_LAYER_H__
#define __INIT_LAYER_H__

#include "TLib/TLayer.h"

class InitLayer : public TLayer
{
private:
	InitLayer();
	~InitLayer();

	bool init();

public:
	CREATE_FUNC(InitLayer);

	void onTouchEnded(Touch *pTouch, Event *pEvent);

private:
	void readJsonTest();
};

#endif // __INIT_LAYER_H__
