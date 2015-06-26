#ifndef __SOUND_TEST_LAYER_H__
#define __SOUND_TEST_LAYER_H__

#include "TLib/TLayer.h"

class SoundTestLayer : public TLayer
{
public:
	SoundTestLayer();
	~SoundTestLayer();

	CREATE_FUNC(SoundTestLayer);
	bool init();

private:
	void callBackOptionBtn(Ref* pSender);
};

#endif // __SOUND_TEST_LAYER_H__
