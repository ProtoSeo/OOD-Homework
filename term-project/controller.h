#pragma once

#include <queue>
#include "array_2d.h"
#include "big_block.h"
#include "view.h"
#include "location.h"
class controller {
private:
	array_2d* color_array;
	view* appview = new view();
	void set_score(int _score);
	int score;
	int x_[4] = { 1,0,-1,0 };
	int y_[4] = { 0,1,0,-1 };
public:
	//appview를 생성
	controller();
	int get_score();

	void run();	//작동

	void print_array_2d();
	bool make_block();

	void user_command(char command);

	void find_explosion();
	void explosion(int visited[][WIDTH]);
};
