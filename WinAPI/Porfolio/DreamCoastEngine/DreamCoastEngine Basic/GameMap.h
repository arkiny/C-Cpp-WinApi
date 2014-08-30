#pragma once

struct MapSize{
	int _x = 0;
	int _y = 0;
};

class GameMap{
public:
	GameMap(){
		// Ȥ�� �𸣴� Double Checking
		_size._x = 0;
		_size._y = 0;
		_tileSize = 50;
	}

	GameMap(int x, int y, int tilesize){
		_size._x = x;
		_size._y = y;
		_tileSize = tilesize;
	}

	//getter
	MapSize getMapSize(){
		return _size;
	}

	int getTileSize(){
		return _tileSize;
	}

	//setter
	void setMapSize(int x, int y){
		_size._x = x;
		_size._y = y;
	}

	void getTileSize(int in){
		_tileSize = in;
	}

	
	POINT isoTo2D(POINT in){
		POINT ret = { 0, 0 };
		ret.x = (2 * in.y + in.x) / 2;
		ret.y = (2 * in.y - in.x) / 2;
		return ret;
	}

	// cartesian coordinate.
	// x is not row
	// ������ �������� ��ġ�� �������ش�.
	// @param ��ũ������ ǥ�õ� �ٵ����� ����ǥ
	// @return ī�׽þ� (����, ����)������ ��ǥ
	POINT TwoDtoISO (POINT in){
		POINT ret = { 0, 0 };
		ret.x = in.x - in.y;
		// ������ �����κе� �� üũ�ؼ� �����������
		ret.y = (in.x + in.y)/2;
		return ret;
	}

	// �Է� �޴� Ÿ���� ��ǥ�� db������ ��ǥ	
	// �̷��� �Ǹ� Ŭ���Ҷ����� ��ǥ�� �ѹ��� �� ��ĵ�ϰ� �Ǵµ�....
	POINT twoDtoISOcheck(POINT tile, POINT cur){
		
		// db������ ��ǥ�� ȭ����ǥ�� ��ȯ�ϰ�,
		// �� ȭ�� ��ǥ�� �߽����� �簢���� �����Ѵ�.
		RECT tileArea = { 
			tile.x - _tileSize ,
			tile.y - _tileSize ,
			tile.x + _tileSize ,
			tile.y + _tileSize };

		POINT ret = tile;

		int xFromTilePos = cur.x - tile.x;
		int yFromTilePos = cur.y - tile.y;

		// Ŀ�� ��ǥ�� �޾ƿͼ� ������ Ȯ���Ѵ�.
		if ( tileArea.left >= cur.x && tileArea.right <= cur.x &&
			tileArea.top >= cur.y && tileArea.bottom<= cur.y){
			if (yFromTilePos < xFromTilePos){
				if (yFromTilePos < (-xFromTilePos)) --ret.y;
				else ++ret.x;
			}
			else if (yFromTilePos > xFromTilePos){
				if (yFromTilePos < (-xFromTilePos)) --ret.x;
				else ++ret.y;
			}
			// Ŀ���� tile ����Ʈ�� ���� �ȿ� ������
			// ���� ���� ���� �� ���� ��ġ�� -1, -1
			// ������ ���� ������ ���� ��ġ�� 0, -1
			// ���� �Ʒ��� ������ ���� ��ġ�� -1, 1
			// ������ �Ʒ��� ������ ���� ��ġ�� 0, 1			
			// ��Ȯ�ϰ� ������ �ȿ� ������ 0, 0
		};
		return ret;
	}

private:
	MapSize _size;
	//���� database �߰�
	int _tileSize = 50;
};