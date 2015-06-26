#ifndef __T_MODAL_DIALOG_H__
#define __T_MODAL_DIALOG_H__

#include "TLib/TLib.h"

typedef bool(*UPDATE_FUNC_POINTER)(float);
typedef void(*FUNC_POINTER)(void);

// Modal DialogÇÃZorderÅ@ëºÇÕäÓñ{ìIÇ…Ç±ÇÍñ¢ñû
#define Z_ORDER_MODAL_DIALOG	(1000)


class TModalDialog : public TLayer
{
public:
	enum DialogType{
		Controlled,
		Ok,
		YesNo,
	};

protected:
	TModalDialog();
	virtual ~TModalDialog();

	virtual bool init(DialogType type, const std::string& text);

public:
	static TModalDialog* create(DialogType type, const std::string& text, UPDATE_FUNC_POINTER funcUpdate, FUNC_POINTER funcEnd);

	virtual void update(float delta);

	virtual void onEnter();
	virtual void onExit();

protected:
	virtual void callBackOkBtn(Ref* pSender);
	virtual void callBackYesBtn(Ref* pSender);
	virtual void callBackNoBtn(Ref* pSender);

protected:
	DialogType _type;

	FUNC_POINTER _funcEnd;
	UPDATE_FUNC_POINTER _funcUpdate;

	std::string _text;
};


#endif // __T_MODAL_DIALOG_H__
