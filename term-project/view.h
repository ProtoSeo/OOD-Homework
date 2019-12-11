#pragma once

#include<iostream>
#include "array_2d.h"
class view {
public:
	//생성자 소멸자 생성
	view() {};
	~view() {};

	//message를 출력하는 함수
	void show_message(const char* message)
	{
		std::cout<< message<< std::endl;
	}
	void show_message_int(int message)
	{
		std::cout << message <<std::endl;
	}
	//message를 출력하지만 endl출력 안함
	void show_message_ln(const char* message)
	{
		std::cout << message;
	}
	//명령어를 입력받는 함수
	char input_command()
	{
		while (1) {
			char temp;
			std::cin >> temp;
			if (temp == 'q' || temp == 'w' || temp == 'e' || temp == 'a' || temp == 's' || temp == 'd' || temp == 'x') 
				return temp;
			else 
				std::cout << "잘못된 명령어를 입력하였습니다. 다시 입력해주세요 : ";
		}
	}
	bool input_y_or_not() {
		char temp;
		std::cin >> temp;
		if (temp == 'Y' || temp == 'y') 
			return true;
		else 
			return false;
	}
};
