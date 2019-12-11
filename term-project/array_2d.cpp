#include <iostream>
#include "array_2d.h"
#include "tree_block.h"
#include "fold_block.h"
#include "cross_block.h"

int array_2d::color_array[HEIGHT][WIDTH];
//생성자 구현
array_2d::array_2d() {
	std::srand((unsigned)time(0));
	init_map();
}
void array_2d::init_map() {
	for (int y = 0; y < HEIGHT; ++y)
		memset(color_array[y], 0, sizeof(int) * WIDTH);
}
//map 배열에 접근 가능한 배열
int array_2d::get_color(int x, int y) {
	return color_array[y][x];
}
void array_2d::set_color(int x, int y,int color) {
	color_array[y][x] = color;
}

//public 함수 구현
bool array_2d::make_block(){
	int block_shape = rand() % 3;

	if (block_shape == big_block::TREE && color_array[1][2] == 0 && color_array[0][2] == 0 && color_array[2][2] == 0) {
		_block = new tree_block(rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1);
		return true;
	}
	else if (block_shape == big_block::FOLD &&color_array[1][2] == 0 && color_array[0][2] == 0 && color_array[1][3] == 0) {
		_block = new fold_block(rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1);
		return true;
	}
	else if (block_shape == big_block::CROSS && color_array[1][2] == 0 && color_array[0][2] == 0 && color_array[1][3] == 0 && color_array[2][2] == 0 && color_array[1][3] == 0) {
		_block =  new cross_block(rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1);
		return true;
	}
	return false;
}
void array_2d::down(){
	this->_block->down();
}
void array_2d::left() {
	this->_block->left();
}
void array_2d::right() {
	this->_block->right();
}
void array_2d::rotate() {
	this->_block->rotate();
}
void array_2d::down_all() {
	for (int x = 0; x < WIDTH; x++) {
		int tempy = HEIGHT - 1;
		for (int y = HEIGHT - 1 ; y >= 0; y--) {
			if(color_array[y][x] == 0){
				continue;
			}
			else if (color_array[y][x] != 0&&tempy == y) {
				color_array[tempy][x] = color_array[y][x];
				tempy--;
			}
			else if(color_array[y][x] != 0 && tempy != y) {
				color_array[tempy][x] = color_array[y][x];
				color_array[y][x] = 0;
				tempy--;
			}
		}
	}
}
bool array_2d::destruction() {	//원래는 false를 반환한다. 근데 can_down불가? -> 쪼개져야함 
	return _block->destruction();
}