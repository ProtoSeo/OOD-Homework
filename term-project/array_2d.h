#pragma once

#include <iostream>
#include<string.h>
#include<ctime>
#include "big_block.h"

#define WIDTH 5
#define HEIGHT 12

class array_2d{
private:
	void init_array();
public:
	static int color_array[HEIGHT][WIDTH];	//y,x
	//생성자
	array_2d();
	big_block* _block;
	//getter와 setter를 생성
	int get_color(int x, int y);
	void set_color(int x, int y,int color);

	//이동에 관한 메서드
	void down_all();
	bool down();
	bool left();
	bool right();
	bool rotate();
	
	bool destruction();
	bool make_block();
};
