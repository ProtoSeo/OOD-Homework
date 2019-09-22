#include<iostream>
using namespace std;
int main(){
	char * a = "ABC";
	char b[] = "ABC";
	
	a[0] = 'b';
	cout << a << '\n';
	cout << b << '\n';
}
