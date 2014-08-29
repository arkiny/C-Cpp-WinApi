struct ENEMY
{
	const float speed = 30.0f;
	const int radius = 20;
	POINT pos;
	ENEMY()
	{
		pos.x = 100;
		pos.y = 40;
	}
	void Move(float delta)
	{
		pos.x += speed * delta;
	}
	void Render(HDC hdc)
	{
		::Rectangle(hdc,
			pos.x - radius,
			pos.y - radius,
			pos.x + radius,
			pos.y + radius);
	}
};

struct PLAYER
{
	const float speed = 90.0f;
	const int radius = 20;
	POINT pos;
	BOOL bRight;
	BOOL bLeft;
	PLAYER()
	{
		pos.x = 100;
		pos.y = 500;
	}
	void Move(float delta)
	{
		if (bRight)
		{
			pos.x += delta * speed;
		}
		if (bLeft)
		{
			pos.x -= delta * speed;
		}
	}
	void Render(HDC hdc)
	{
		::Rectangle(hdc,
			pos.x - radius,
			pos.y - radius,
			pos.x + radius,
			pos.y + radius);
	}
	void OnKeyDown(DWORD dwKey)
	{
		if (dwKey == VK_RIGHT)
			bRight = true;
		if (dwKey == VK_LEFT)
			bLeft = true;
	}
	void OnKeyUp(DWORD dwKey)
	{
		if (dwKey == VK_RIGHT)
			bRight = false;
		if (dwKey == VK_LEFT)
			bLeft = false;
	}
};

struct BULLET
{
	const float speed = 130.0f;
	const int radius = 10;
	POINT pos;
	bool bVisible;
	BULLET()
	{
		bVisible = false;
		pos.x = 0;
		pos.y = 0;
	}
	void Fire(int x, int y)
	{
		if (bVisible) return;

		bVisible = true;
		pos.x = x;
		pos.y = y;
	}
	void Move(float delta)
	{
		if (bVisible)
		{
			pos.y -= speed * delta;

			if (pos.y + radius < 0)
				bVisible = false;

		}
	}
	void Render(HDC hdc)
	{
		if (bVisible)
		{
			::Rectangle(hdc,
				pos.x - radius,
				pos.y - radius,
				pos.x + radius,
				pos.y + radius);
		}
		
	}
};