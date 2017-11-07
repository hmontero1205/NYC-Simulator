#include "Arduino.h"
#include "Block.h"

Block::Block(int x, int y, int dir, int mode) {
     this->xCoord = x;
     this->yCoord = y;
     this->dir = dir;
     this->bMode = mode;
}

int Block::getX() {
	return xCoord;
}

int Block::getY() {
	return yCoord;
}

int Block::getMode() {
	return bMode;
}

void Block::moveTo(int x, int y) {
	if(x < 0) {
		xCoord = 0;
	} else {
		if(x > 310) {
			xCoord = 310;
		} else {
			xCoord = x;
		}
	}

	if(y < 0) {
		yCoord = 0;
	} else {
		if(y > 230) {
			yCoord = 230;
		} else {
			yCoord = y;
		}
	}

}

void Block::drive() {
	xCoord += (dir * 10);
	if(xCoord < 0) {
		xCoord = 310;
	} else {
		if(xCoord > 310) {
			xCoord = 0;
		}
	}
}