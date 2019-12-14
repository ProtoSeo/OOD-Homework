#pragma once
#include "big_block.h"
class cross_block : public big_block {
public:
	cross_block(int c1, int c2, int c3, int c4, int c5 );
	bool can_left();
	bool can_right();
	bool can_down();
	
	void left();
	void right();
	bool down();
	
	bool destruction();
	bool rotate();
};
