#include "fold_block.h"
#include "array_2d.h"

fold_block::fold_block(int c1, int c2, int c3) {
	status = 0;
	array_2d::color_array[center_y][center_x] = c1;
	array_2d::color_array[center_y + y[3]][center_x + x[3]] = c2;
	array_2d::color_array[center_y + y[0]][center_x + x[0]] = c3;
}
bool fold_block::can_left() {
	if (status == 0 && center_x - 1 >=0) {
		return (array_2d::color_array[center_y][center_x-1] == 0);
	}
	else if (status == 1 && center_x - 1 >= 0) {
		return (array_2d::color_array[center_y+1][center_x-1] == 0);
	}
	else if (status == 2 && center_x - 2 >= 0) {
		return (array_2d::color_array[center_y + 1][center_x-1] == 0&& array_2d::color_array[center_y][center_x - 2] == 0);
	}
	else if (status == 3 && center_x -2 >= 0) {
		return (array_2d::color_array[center_y][center_x - 2] == 0);
	}
	return false;
}
bool fold_block::can_right() {	
	if (status == 0 && center_x +2 <WIDTH) {
		return (array_2d::color_array[center_y][center_x - 1] == 0);
	}
	else if (status == 1 && center_x + 2 < WIDTH) {
		return (array_2d::color_array[center_y + 1][center_x - 1] == 0);
	}
	else if (status == 2 && center_x + 1 < WIDTH) {
		return (array_2d::color_array[center_y + 1][center_x - 1] == 0 && array_2d::color_array[center_y][center_x - 2] == 0);
	}
	else if (status == 3 && center_x + 1 < WIDTH) {
		return (array_2d::color_array[center_y][center_x - 2] == 0);
	}
	return false;
}
bool fold_block::can_down() {
	if (status == 0&& center_y + 1 < HEIGHT) {
		return (array_2d::color_array[center_y + 1][center_x] == 0&& array_2d::color_array[center_y + 1][center_x+1] == 0);
	}
	else if (status == 1&& center_y + 2 < HEIGHT) {
		return (array_2d::color_array[center_y + 2][center_x] == 0 && array_2d::color_array[center_y + 1][center_x+1] == 0);
	}
	else if (status == 2&& center_y + 2 < HEIGHT) {
		return (array_2d::color_array[center_y + 2][center_x] == 0 && array_2d::color_array[center_y + 1][center_x-1] == 0);
	}
	else if (status == 3&& center_y + 1 < HEIGHT) {
		return (array_2d::color_array[center_y + 1][center_x] == 0&& array_2d::color_array[center_y + 1][center_x-1] == 0);
	}
	return false;
}

void fold_block::left() {
	if (can_left()) {
		int temp_color = array_2d::color_array[center_y][center_x];
		array_2d::color_array[center_y][center_x] = 0;
		for (int i = 0; i < 4; i++) {
			if (status == 0&&(i == 0 || i == 3)) {
				array_2d::color_array[center_y + y[i]][center_x + x[i] - 1] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
			else if (status == 1&& (i==0||i==1)) {
				array_2d::color_array[center_y + y[i]][center_x + x[i] - 1] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
			else if (status == 2&& (i == 1 || i == 2)) {
				array_2d::color_array[center_y + y[i]][center_x + x[i] - 1] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
			else if (status == 3&&(i == 2 || i == 3)) {
				array_2d::color_array[center_y + y[i]][center_x + x[i] - 1] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
		}
		array_2d::color_array[center_y][center_x - 1] = temp_color;
		center_x--;
	}
}
void fold_block::right() {
	if (can_right()) {
		int temp_color = array_2d::color_array[center_y][center_x];
		array_2d::color_array[center_y][center_x] = 0;
		for (int i = 0; i < 4; i++) {
			if (status == 0 && (i == 0 || i == 3)) {
				array_2d::color_array[center_y + y[i]][center_x + x[i] + 1] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
			else if (status == 1 && (i == 0 || i == 1)) {
				array_2d::color_array[center_y + y[i]][center_x + x[i] + 1] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
			else if (status == 2 && (i == 1 || i == 2)) {
				array_2d::color_array[center_y + y[i]][center_x + x[i] + 1] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
			else if (status == 3 && (i == 2 || i == 3)) {
				array_2d::color_array[center_y + y[i]][center_x + x[i] + 1] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
		}
		array_2d::color_array[center_y][center_x + 1] = temp_color;
		center_x++;
	}
}
bool fold_block::down() {
	if (can_down()) {
		int temp_color = array_2d::color_array[center_y][center_x];
		array_2d::color_array[center_y][center_x] = 0;
		for (int i = 0; i < 4; i++) {
			if (status == 0 && (i == 0 || i == 3)) {
				array_2d::color_array[center_y + y[i]+1][center_x + x[i]] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
			else if (status == 1 && (i == 0 || i == 1)) {
				array_2d::color_array[center_y + y[i]+1][center_x + x[i]] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
			else if (status == 2 && (i == 1 || i == 2)) {
				array_2d::color_array[center_y + y[i]+1][center_x + x[i]] = array_2d::color_array[center_y + y[i]][center_x + x[i]];
				array_2d::color_array[center_y + y[i]][center_x + x[i]] = 0;
			}
			else if (status == 3 && (i == 2 || i == 3)) {
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
bool fold_block::rotate() {
	if (status == 0&&array_2d::color_array[center_y + 1][center_x] == 0) {
		array_2d::color_array[center_y + y[1]][center_x + x[1]] = array_2d::color_array[center_y + y[0]][center_x + x[0]];
		array_2d::color_array[center_y + y[0]][center_x + x[0]] = array_2d::color_array[center_y + y[3]][center_x + x[3]];
		array_2d::color_array[center_y + y[3]][center_x + x[3]] = 0;
		status++;
		return true;
	}
	else if (status == 1 &&center_x-1>=0&& array_2d::color_array[center_y][center_x-1] == 0) {
		array_2d::color_array[center_y + y[2]][center_x + x[2]] = array_2d::color_array[center_y + y[1]][center_x + x[1]];
		array_2d::color_array[center_y + y[1]][center_x + x[1]] = array_2d::color_array[center_y + y[0]][center_x + x[0]];
		array_2d::color_array[center_y + y[0]][center_x + x[0]] = 0;
		status++;
		return true;
	}
	else if (status == 2) {
		array_2d::color_array[center_y + y[3]][center_x + x[3]] = array_2d::color_array[center_y + y[2]][center_x + x[2]];
		array_2d::color_array[center_y + y[2]][center_x + x[2]] = array_2d::color_array[center_y + y[1]][center_x + x[1]];
		array_2d::color_array[center_y + y[1]][center_x + x[1]] = 0;
		status++;
		return true;
	}
	else if (status == 3 && center_x + 1<WIDTH && array_2d::color_array[center_y][center_x+1] == 0) {
		array_2d::color_array[center_y + y[0]][center_x + x[0]] = array_2d::color_array[center_y + y[3]][center_x + x[3]];
		array_2d::color_array[center_y + y[3]][center_x + x[3]] = array_2d::color_array[center_y + y[2]][center_x + x[2]];
		array_2d::color_array[center_y + y[2]][center_x + x[2]] = 0;
		status = (status+1) % 4;
		return true;
	}
	return false;
}
