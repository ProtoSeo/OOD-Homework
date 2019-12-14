#include "cross_block.h"
#include "array_2d.h"

cross_block::cross_block(int c1, int c2, int c3, int c4, int c5) {
	array_2d::color_array[center_y][center_x] = c1;
	array_2d::color_array[center_y][center_x-1] = c2;
	array_2d::color_array[center_y][center_x+1] = c3;
	array_2d::color_array[center_y-1][center_x] = c4;
	array_2d::color_array[center_y+1][center_x] = c5;
}
bool cross_block::can_left() {
	if (center_x - 2 >= 0)
		return (array_2d::color_array[center_y + 1][center_x-1] == 0 && array_2d::color_array[center_y][center_x - 2] == 0);
	return false;
}
bool cross_block::can_right() {
	if(center_x + 2 < WIDTH)
		return (array_2d::color_array[center_y + 1][center_x+1] == 0 && array_2d::color_array[center_y][center_x + 2] == 0);
	return false;
}
bool cross_block::can_down() {
	if (center_y + 2 < HEIGHT)
		return (array_2d::color_array[center_y + 2][center_x] == 0 && array_2d::color_array[center_y+1][center_x + 1] == 0
					&& array_2d::color_array[center_y + 1][center_x - 1]==0);
	return false;
}
void cross_block::left() {
	if (can_left()) {
		int temp_color = array_2d::color_array[center_y][center_x];
		for (int i = 0; i < 4; i++) {
			array_2d::color_array[center_y + y[i]][center_x + x[i] - 1] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
			array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
		}		
		array_2d::color_array[center_y][center_x - 1] = temp_color;
		center_x--;
	}
}
void cross_block::right() {
	if (can_right()) {
		int temp_color = array_2d::color_array[center_y][center_x];
		for (int i = 0; i < 4; i++) {
			array_2d::color_array[center_y + y[i]][center_x + x[i] + 1] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
			array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
		}
		array_2d::color_array[center_y][center_x + 1] = temp_color;
		center_x++;
	}
}
bool cross_block::down() {
	if (can_down()) {
		int temp_color = array_2d::color_array[center_y][center_x];
		for (int i = 0; i < 4; i++) {
			array_2d::color_array[center_y + y[i]+1][center_x + x[i]] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
			array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
		}
		array_2d::color_array[center_y+1][center_x] = temp_color;
		center_y++;
		return true;
	}
	return false;
}
bool cross_block::rotate() {
	int temp_color = array_2d::color_array[center_y+y[3]][center_x+x[3]];
	for (int i = 3; i >= 1; i--) 
		array_2d::color_array[center_y + y[i]][center_x + x[i]] = array_2d::color_array[center_y + y[i-1]][center_x + x[i-1]];
	array_2d::color_array[center_y + y[0]][center_x + x[0]] = temp_color;
	return true;
}
