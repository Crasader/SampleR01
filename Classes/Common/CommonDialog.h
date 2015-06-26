#ifndef __COMMON_DIALOG_H__
#define __COMMON_DIALOG_H__

#include "TLib/TModalDialog.h"

class CommonDialog : public TModalDialog
{
private:
	CommonDialog();
	~CommonDialog();

	bool init(DialogType type, const std::string& text);

public:
	static CommonDialog* create(DialogType type, const std::string& text, UPDATE_FUNC_POINTER funcUpdate, FUNC_POINTER funcEnd);

	void update(float delta);

	void onEnter();
	void onExit();

private:
	void callBackOkBtn(Ref* pSender);
	void callBackYesBtn(Ref* pSender);
	void callBackNoBtn(Ref* pSender);
};


#endif // __COMMON_DIALOG_H__
