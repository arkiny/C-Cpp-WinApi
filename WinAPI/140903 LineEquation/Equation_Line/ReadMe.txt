웨이브는 Sin 값 혹은 Cos 값으로 만들수 있다

중력 처리?

타겟 레이저 포인트 만들기
레이저 포인트를 만들고 싶당...->

직선을 쏴서 충돌 지점에 장애물이 있는지 미리

아이소 메트릭 안에 마름모가 그려져 있고, 
클릭한 좌표랑 직선과의 관계를 통해서 

3D는 평면과 직선이 닿느냐 에 따라서

-----------------직선의 방정식 ----------------

y = mx + b 

y-b = mx
m = (y-b)/x

m : 기울기
b : y절편

ax + by = c

기울기 = 높기 /  밑변

-----------------인수분해 몰라도 할수 있는거라함 ------------------

두선의 접점 구하는 법

y = mx + b
y 절편만 구하면 댐

임의의 점 X1, Y1 (선위의 점)
y-mx = b
b= Y1 - m*X1

Y= mX + (Y1 - mX1)
Y = mX + Y1 -mX1
Y=mX -mX1+y1

Y = m(X-X1)+Y1

------------------
float GetY(float x, POINT src, POINT target){
	float m = (float)(target.y - src.y) / (float)(target.x - src.x);
	float y = m * (x - src.x) + src.y ;
	return y;
}