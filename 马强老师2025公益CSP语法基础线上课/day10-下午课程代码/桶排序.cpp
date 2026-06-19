#include<iostream>
using namespace std;
int a[401]; //int 4byte 
/*
8
0 1 8 3 4 0 3 400
*/
int main(){
	int n,m; //n个数字
	cin>>n;
	for(int i=1;i<=n;i++){ //桶排序
		cin>>m; //临时存储
		a[m]++; //插旗子
	}
	for(int i=0;i<=400;i++){ //数据的范围
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++)
				cout<<i<<' ';
		}
	}
	return 0;
}
