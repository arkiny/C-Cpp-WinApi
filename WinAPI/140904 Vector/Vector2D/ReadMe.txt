0904----------------------------------------------------------------------------------------
2D API

스칼라(좌표) / 벡터 (크기와 방향)

↑  y축
→  x축

위치 성분은 2가지 (x축 성분과, y축 성분) -> 를 가지고 2D화면에 뿌릴수 있게 되는 것

벡터의 성분은 2가지(크기와 방향)

힘 : 날아간 만큼 거리(x거리)
방향 : 원점에서부터 시작해서 위로 올라가는 힘(y거리)

벡터 연산
벡터 + 벡터 -> 성분 끼리 더한다.
벡터 + 벡터 = 벡터
V3.X = V1.X + V2.X;
V3.Y = V1.Y + V2.Y;

-> 벡터의 성질이 대단히 중요하다.
-> 벡터를 이용하여 두벡터의 합의 중간값(?)을 구할때 쓴다.

벡터 - 벡터
V3.X = V1.X - V2.X;
V3.Y = V1.Y - V2.Y;

-> 벡터 성분끼리 빼서 세로운 백터
-> 벡터 1에서 벡터2로 이동하고 싶다.(같은 값의 힘과 방향을 구하고 싶다)
-> V2에서 V1를 뺀후, 그 값을 V1에서 더하면 된다. (나갈 방향에 있는 값) = 벡터2

시작점이 원점이 아닌 벡터는 업ㅂ다.
벡터는 무조건 2차원

벡터의 길이 * 스칼라 = 벡터의 크기를 스칼라만큼 콥해진다

단위벡터라는 것을 만들면 단위벡터

--------

reflection vector (반사에서 쓸수 있음)










typedef struct Vector2D{
public:
	Vector2D(float x, float y){
		_x = x;
		_y = x;
	}

	Vector2D operator-(const Vector2D& vec) const{
		Vector2D ret(_x - vec._x, _y - vec._y);
		return ret;	
	}

	Vector2D operator+(const Vector2D& vec) const{
		Vector2D ret(_x + vec._x, _y + vec._y);
		return ret;
	}

private:
	float _x;
	float _y;
}VECTOR2D;