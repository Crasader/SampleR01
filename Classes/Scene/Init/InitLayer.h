#ifndef __INIT_LAYER_H__
#define __INIT_LAYER_H__

#include "TLib/TLayer.h"

#include "TLib/TUtility.h"

class InitLayer : public TLayer
{
public:
	InitLayer();
	~InitLayer();

	CREATE_FUNC(InitLayer);
	bool init();

	void onTouchEnded(Touch *pTouch, Event *pEvent);
};

#endif // __INIT_LAYER_H__
