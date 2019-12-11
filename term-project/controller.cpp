#include "controller.h"
#include <iostream>
//static 변수로 생성

controller::controller() {
	color_array = new array_2d();
	this-> score = 0;
}
int controller::get_score() {
	return this->score;
}
void controller::set_score(int _score) {
	this->score = _score;
}
void controller::run() {	//view 에서 구현할것
	appview->show_message(">>> 뿌요뿌요를 시작합니다. <<<");
	appview->show_message(">>> 게임을 시작합니다. <<<");
	int t = 5;
	while (make_block()) {	//make_block이 불가능하면 게임이 종료된다.
		print_array_2d();
		do{
			appview->show_message_ln("명령을 입력해주세요 : ");
			char command = appview->input_command();
			user_command(command);
			print_array_2d();
			if (command == 'x') break;
		} while (!color_array->destruction());
		if(color_array->destruction())
			color_array->down_all();
		find_explosion();

	}
	appview->show_message(">>> 더 이상 블록을 생성할 수 없습니다. <<<");
	print_array_2d();
	appview->show_message(">>> 게임을 종료합니다. <<<");
}
bool controller::make_block() {
	return color_array->make_block();
}
void controller::user_command(char command) {	//사용자의 입력을 받아 명령을 실행해주는 메서드
	if (command == 'x') 
		color_array->down_all();
	else if (command == 's') 
		color_array->down();
	else if (command == 'd') 
		color_array->right();
	else if (command == 'a') 
		color_array->left();
	else if (command == 'e') 
		color_array->rotate();
}

void controller::print_array_2d() {		//score 출력 및 출력
	appview->show_message_ln("score : ");
	appview->show_message_int(get_score());
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++)
			std::cout << color_array->get_color(x, y)<<'\t';
		appview->show_message_ln("\n");
	}
	appview->show_message_ln("\n");
}

void controller::find_explosion() {		//모든 이중포문을 통해서 
	for (int x = WIDTH-1; x >=0; x--) {
		for (int y = HEIGHT-1 ; y >= 0; y--) {
			if (color_array->get_color(x, y) == 1|| color_array->get_color(x, y) == 0) continue;	//0 or 1이면 볼 필요 x
			int count = 0;
			int visited[HEIGHT][WIDTH] = { 0 };
			std::queue<location> q;
			q.push(location(x, y, color_array->get_color(x, y)));
			visited[y][x] = 1;
		
			while (!q.empty()) {
				location loc = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					int xx = loc.x + x_[i];
					int yy = loc.y + y_[i];
					if (xx >= 0 && xx < WIDTH && yy >= 0 && yy < HEIGHT && visited[yy][xx] == 0) {
						if (color_array->get_color(xx, yy) == loc.color) {
							q.push(location(xx, yy, color_array->get_color(xx, yy)));
							visited[yy][xx] = 1;
							count++;
						}
						if (color_array->get_color(xx, yy) == 1) {	//grey색인 경우 폭발을 같이 해야함
							visited[yy][xx] = 1;
						}
					}
				}
			}
			if (count >= 3) { 
				explosion(visited);
				x = WIDTH - 1;
				y = HEIGHT - 1;
			}
		}
	}
}

void controller::explosion(int visited[][WIDTH]) {	//폭발하고 스코어 계산
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			if(visited[y][x] == 1)
				color_array->set_color(x, y, 0);
		}
	}
	color_array->down_all();
	set_score(get_score()+1);
}
