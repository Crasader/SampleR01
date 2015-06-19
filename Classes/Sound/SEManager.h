#ifndef __SE_MANAGER_H__
#define __SE_MANAGER_H__

class SEManager
{
public:
	enum SE_ID {
		INVALID_SE_ID = -1,
		SE_DECIDE = 0,

		SE_MAX,
	};

private:
	SEManager();
	~SEManager();

public:
	static SEManager* create();
	void destroy();

private:
	bool init();

public:
	int32_t play(uint32_t seId, bool loop);
	void stop(int32_t audioId);
	void pause(int32_t audioId);
	void pause();
	void resume(int32_t audioId);
	void resume();

	float getVolume() { return _volume; }
	void setVolume(float volume);

private:
	float _volume;
};


#endif // __SE_MANAGER_H__
