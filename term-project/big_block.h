#pragma once

#include <vector>

class big_block {
protected:
	int center_x, center_y;
	int x[4] = { 1,0,-1,0 };
	int y[4] = { 0,1,0,-1 };
	bool block_destruction_check;
public:
	enum _type {
		TREE, FOLD, CROSS
	};
	big_block();
	virtual bool can_left()=0;
	virtual bool can_right()=0;
	virtual bool can_down()=0;

	bool destruction();
	virtual bool down() = 0;
	virtual void left() = 0;
	virtual void right() = 0;
	virtual bool rotate() = 0;
};