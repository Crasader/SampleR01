#ifndef __SOUND_TEST_LAYER_H__
#define __SOUND_TEST_LAYER_H__

#include "TLib/TLayer.h"

class SoundTestLayer : public TLayer
{
private:
	SoundTestLayer();
	~SoundTestLayer();

	bool init();

public:
	CREATE_FUNC(SoundTestLayer);

private:
	void callBackOptionBtn(Ref* pSender);
};

#endif // __SOUND_TEST_LAYER_H__
