#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n; //查找次数
	int a[11]={}; //初始化为0 表示狐狸没有搜索的地方
//	a[10]=1; //10号洞出发
//	a[1]=1; //1号洞找我
	a[10]=a[1]=1; //1号洞找我 10号洞出发
	int k=1;//隔k个洞穴寻找
	for(int i=1;i<n;i++){
		k=(k+i)%10+1;
		a[k]=1; //已搜索
	}
	for(int i=1;i<=10;i++){
		if(a[i]==0)	cout<<i<<' ';
	}
	return 0;
}
