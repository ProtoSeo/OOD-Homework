#include<iostream>
int dp[100001]={0,1,1,2,};
int fibo(int i){
	if(i<=2) return dp[i];
	else if (dp[i])return dp[i];
	else return dp[i]=fibo(i-1)+fibo(i-2);
}
int main(){
	int i;
	std::cin>>i;
	int val = fibo(i);
	std::cout<< val<<std::endl;
	return 0;
}

