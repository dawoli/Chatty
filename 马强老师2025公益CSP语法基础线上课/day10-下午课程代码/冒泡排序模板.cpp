#include<iostream>
using namespace std;
int a[105];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	//冒泡排序核心代码
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			if(a[j]<a[j+1])	swap(a[j],a[j+1]);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	return 0;
}
/*
5
3 1 2 5 4
*/
