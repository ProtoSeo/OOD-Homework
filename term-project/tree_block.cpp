#include "tree_block.h"
#include "array_2d.h"

tree_block::tree_block(int c1, int c2, int c3) {
	array_2d::color_array[center_y][center_x] = c1;
	array_2d::color_array[center_y-1][center_x] = c2;
	array_2d::color_array[center_y+1][center_x] = c3;	
}

bool tree_block::can_left() {
	if (row && center_x - 2 >= 0) 
		return array_2d::color_array[center_y][center_x - 2] == 0;
	else if(!row && center_x-1 >= 0)
		return array_2d::color_array[center_y-1][center_x - 1] == 0;
	return false;
}

bool tree_block::can_right() {
	if (row && center_x + 2 < WIDTH) {
		return array_2d::color_array[center_y][center_x + 2] == 0;
	}
	else if (!row && center_x +1 <WIDTH) {
		return array_2d::color_array[center_y - 1][center_x + 1] == 0;
	}
	return false;
}

bool tree_block::can_down() {
	if (row && center_y + 1 < HEIGHT) {
		return array_2d::color_array[center_y + 1][center_x+1] == 0&& array_2d::color_array[center_y + 1][center_x - 1]==0;
	}
	else if (!row && center_y + 2 < HEIGHT) {
		return array_2d::color_array[center_y + 2][center_x] == 0;
	}
	return false;
}

void tree_block::left() {
	if (can_left()) {
		int temp_color = array_2d::color_array[center_y][center_x];
		array_2d::color_array[center_y][center_x] = 0;
		for (int i = 0; i < 4; i++) {
			if (row && i % 2 == 0) {
				array_2d::color_array[center_y + y[i]][center_x + x[i] - 1] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
			else if (!row && i % 2 == 1) {
				array_2d::color_array[center_y + y[i]][center_x + x[i] - 1] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
		}
		array_2d::color_array[center_y][center_x - 1] = temp_color;
		center_x--;
	}
}

void tree_block::right() {
	if (can_right()) {
		int temp_color = array_2d::color_array[center_y][center_x];
		array_2d::color_array[center_y][center_x] = 0;
		for (int i = 0; i < 4; i++) {
			if (row && i % 2 == 0) {
				array_2d::color_array[center_y + y[i]][center_x + x[i] + 1] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
			else if (!row && i % 2 == 1) {
				array_2d::color_array[center_y + y[i]][center_x + x[i] + 1] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
		}
		array_2d::color_array[center_y][center_x + 1] = temp_color;
		center_x++;
	}
}

bool tree_block::down() {
	if (can_down()) {
		int temp_color = array_2d::color_array[center_y][center_x];
		array_2d::color_array[center_y][center_x] = 0;
		for (int i = 0; i < 4; i++) {
			if (row && i % 2 == 0) {
				array_2d::color_array[center_y + y[i]+1][center_x + x[i]] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
			else if (!row && i % 2 == 1) {
				array_2d::color_array[center_y + y[i]+1][center_x + x[i]] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
		}
		array_2d::color_array[center_y+1][center_x] = temp_color;
		center_y++;
		return true;
	}
	return false;
}

bool tree_block::rotate() {
	if (row && center_y + 1 < HEIGHT) {
		if (array_2d::color_array[center_y + 1][center_x] == 0) {
			for (int i = 0; i < 4; i += 2) {
				array_2d::color_array[center_y + y[i + 1]][center_x + x[i + 1]] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
			row = !row;
			return true;
		}
	}
	else if (!row && (center_x - 1 >= 0 && center_x + 1 < WIDTH)) {
		if (array_2d::color_array[center_y][center_x - 1] == 0 && array_2d::color_array[center_y][center_x + 1] == 0) {
			for (int i = 1; i < 4; i += 2) {
				array_2d::color_array[center_y + y[(i + 1) % 4]][center_x + x[(i + 1) % 4]] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
			row = !row;
			return true;
		}
	}
	return false;
}
