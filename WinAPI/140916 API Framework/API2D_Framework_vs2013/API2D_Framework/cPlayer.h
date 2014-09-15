#pragma once
class cPlayer
{
public:
	cPlayer()
	{
		x = 0;
	}
	~cPlayer(){}
	void Render(HDC hdc)
	{
		//
		Rectangle(hdc,x,100,x+100,200);
	}
	void Update(float deltaTime)
	{
		static float accumTime = 0.0f;
		accumTime += deltaTime;
		x = static_cast<int>(x + (230.0f * deltaTime));
	}
	int x;
};
