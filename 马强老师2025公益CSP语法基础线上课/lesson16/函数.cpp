/*
  max min
 */
#include<bits/stdc++.h>
using namespace std;
int a[11]={0,11,22,4,8,9,34,56,7,8,10};//全局变量
int sum(){//自定义函数
	int s=0;//局部变量
	for(int i=1;i<=10;i++)
		s+=a[i];
	return s;
	
}
int main(){	
	int maxn=-1,minn=10000;//局部变量
	for(int i=1;i<=10;i++){
		maxn=max(maxn,a[i]);//系统函数
		minn=min(minn,a[i]);
	}
	cout<<maxn<<' '<<minn<<endl;
	cout<<sum()<<endl;
	for(int i=1;i<=10;i++) cout<<a[i]<<' ';
	cout<<endl;
	sort(a+1,a+1+10);
	for(int i=1;i<=10;i++) cout<<a[i]<<' ';
	return 0;
}
