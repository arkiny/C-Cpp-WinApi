#pragma once

#include <math.h>
#include <Windows.h>

typedef class VECTOR2D
{
public:
	float x;
	float y;

	VECTOR2D()
	{
		x = 0.0f;
		y = 0.0f;
	}

	VECTOR2D(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
	VECTOR2D operator+(const VECTOR2D& vec) const{
		return VECTOR2D(x + vec.x, y + vec.y);
	}
	VECTOR2D operator-(const VECTOR2D& vec) const{
		return VECTOR2D(x - vec.x, y - vec.y);
	}

	float Length()
	{
		return sqrt(x * x + y * y);
	}

	void Normalize()
	{
		float vLen = Length();
		this->x = x / vLen;
		this->y = y / vLen;
	}

	VECTOR2D operator*(float scalar) const
	{
		return VECTOR2D(x * scalar, y * scalar);
	}

	void DrawVector(HDC hdc, int x, int y, COLORREF color)
	{
		HPEN hPen = ::CreatePen(PS_SOLID, 3, color);
		HPEN oldPen = (HPEN)::SelectObject(hdc, hPen);

		::MoveToEx(hdc, 0, 0, NULL);
		::LineTo(hdc, x, y);

		::DeleteObject(::SelectObject(hdc, oldPen));

	}
}*LPVECTOR2D;


