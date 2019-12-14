#include "big_block.h"

big_block::big_block(){
	center_x = 2;
	center_y = 1; 
	block_destruction_check = false;
}

bool big_block::destruction() {
	if (!can_down())	//내려갈 수 없을 때 
		block_destruction_check = true;
	return block_destruction_check;		//평상시에는 false
}
