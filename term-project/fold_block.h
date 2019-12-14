#pragma once
#include "big_block.h"
class fold_block : public big_block {
private:
	enum all_status {
		UR,RD,DL,LU
	};
	int status = 0;
public:
	fold_block(int c1, int c2, int c3);
	bool can_left();
	bool can_right();
	bool can_down();
	
	void left();
	void right();
	bool down();

	bool destruction();
	bool rotate();
};
