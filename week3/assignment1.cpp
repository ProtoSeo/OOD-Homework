#include<iostream>
using namespace std;
int BSS;	//초기화 되지 않은 전역변수, static변수를 저장하기 위한 메모리 공간
static int data =1; //전역변수나 static 변수의 영역
void code(){	//실행해야 할 함수와 코드의 영역
	return;
}
int main(){
	const char * rodata = "rodata"; 	// char*을 통해서 "rodata"를 받은경우 상수 "rodata"를 rodata 에서 주소를 참조
	int * heap = new int[2];	//동적 할당 되는 변수를 저장하기 위한 메모리 공간
	int stack = 1;	//함수에서 사용되는 지역 변수를 저장하기 위한 메모리 공간
	heap[0] = 0;
	heap[1] = 1;
	cout << "main\t"<< (void *) main <<'\n';	//main문의 메모리 공간
	cout << "code\t"<< (void *) code <<'\n';
	cout << "rodata\t"<< (void *) rodata <<'\n';
	cout << "data\t"<< &data <<'\n';
	cout << "BSS\t"<< &BSS <<'\n';
	cout << "Heap\t"<< heap <<'\n';
	cout << "Stack\t"<< &stack <<'\n';
}
