#pragma once

class callback
{
public:
	virtual ~callback() {}
	virtual void call(void* pdat) = 0;
};

//template <typename T>
class callbackFunction : public callback
{
public:
	callbackFunction(void (*func)(void*)){
		pfunc = func;
	}

	void call(void* pdat){
		(*pfunc)(pdat);
	}

private:
	void(*pfunc)(void*);

};

