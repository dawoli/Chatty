#include<iostream>
using namespace std;
int main(){
	int n;
	int a[1005]={};
	cin>>n;//数组元素的数量
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int c; //相加次数
	if(n%2==0)	c=n/2; 
	else		c=n/2+1;
	for(int i=1,j=n;i<=c;i++,j--){//将对应位置上的元素相加
		cout<<a[i]+a[j]<<' ';
	}
	return 0;
}
