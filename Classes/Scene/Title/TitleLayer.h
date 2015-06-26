#ifndef __TITLE_LAYER_H__
#define __TITLE_LAYER_H__

#include "cocos2d.h"
#include "TLib/TLayer.h"

class TitleLayer : public TLayer
{
private:
	TitleLayer();
	~TitleLayer();

	bool init();

public:
	CREATE_FUNC(TitleLayer);

private:
	void callBackStartBtn(Ref* pSender);
	void callBackOptionBtn(Ref* pSender);
};

#endif // __TITLE_LAYER_H__
