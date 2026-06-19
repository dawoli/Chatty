#include<iostream>
using namespace std;
int main(){
	int t; //T恤的质检分数
	int ans=0; //一定要初始化
	while(1){
		cin>>t;
		if(t==0)	break;
		if(t<=60)	ans++;
	}
	cout<<ans; //需要被回收的产品数量
	return 0;
}
