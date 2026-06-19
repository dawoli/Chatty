#include<iostream> //swap();
using namespace std;
int a[15];
int main(){
	int n; //n个数字进行排序
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	//选择排序模板
	for(int i=1;i<n;i++){ 
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j])	swap(a[i],a[j]);
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
