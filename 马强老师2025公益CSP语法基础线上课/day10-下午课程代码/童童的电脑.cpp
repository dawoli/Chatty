#include<iostream>
using namespace std;
int a[15]; //商品的价格
int main(){
	int n,sum=0; //n件商品
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	//冒泡排序-降序
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			if(a[j]<a[j+1])	swap(a[j],a[j+1]);
		}
	}
	for(int i=1;i<=n;i++)	cout<<a[i]<<' ';
	cout<<endl<<sum;
	return 0;
}
