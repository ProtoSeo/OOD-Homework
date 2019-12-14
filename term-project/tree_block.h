#pragma once
#include "big_block.h"
class tree_block : public big_block {
private:
	bool row = false;
public:
	tree_block(int c1, int c2, int c3);
	
	bool can_left();
	bool can_right();
	bool can_down();

	void left();
	void right();
	bool down();

	bool destruction();
	bool rotate();
};
