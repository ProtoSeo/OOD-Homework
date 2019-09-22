#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	char target[] = "SeoSeunghun";
	long b[012];
	int a= 18;
	int i = 117;
	int *c = new int[602];
    char * copy = "is no no";
	char name ='a';
	printf("target :\t%p\n",target);
	printf("name   :\t%p\n",&name);
	printf("&name+i:\t%p\n",&name+i);
	cout << &name+i << endl;
}
