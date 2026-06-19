#include<iostream>
using namespace std;
int main(){
	int year;
	cin>>year;
	/*
	  两个条件：
	  1、4的倍数，并且不是100的倍数；
	  2、是400的倍数
	 */
	if(year%4==0 && year%100!=0 || year%400==0 ){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}
