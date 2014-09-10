1. 이번주 비트맵 배운뒤 보강기간동안 포트폴리오 제작 시작
2. 스프라이트는 비트맵하면서 배우게 될 예정


// bitmap

HDC -> Handler Device Contact?  
출력을 위해 모든 정보를 담고 있는 구조체(Brush, Pen)

화면 출력 DC

프린터 출력 DC

메모리를 출력하는 메모리 DC

SelectObject 
Object- > GDI(Graphic Device Interface) Object

그럼 Bitmap은? Bitmap의 정체는 뭘까 -> 칼라를 비트단위로 저장하고 있는 정보(.bmp)
Bitmap도 하나의 GDI Object
1. HDC가 필요하고
-> Bitmap Load
2. SelectObject Bitmap 
3. 

화면 DC는 제약이 있다 -> Bitmap을 Select할수 없게 되어있음
1. 화면 DC와 호환이 되는 메모리 DC  - 
HDC MemDC = CreateCompatibleDC(hdc);

2. SelectObject(bitmap) - 
HBITMAP oldBitmap = (HBITMAP) SelectObject(MemDC, hBit);

3. 비트 전송
Bitblt(hdc, x, y, width, height, MemDC, 0, 0, SRCCOPY);

4. 비트맵 핸들
SelectObject(MemDC, oldBitmap);
DeleteDC(MemDC);
|메모리 DC                      | <- 2. 호환되는 --       |  1. 화면 DC  |
|3. Bitmap SelectObject    |    -4. Bitblt ->		   |                   |