#include<iostream>
using namespace std;
int a[181];
int main(){
	int n,m; //n个人
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		a[m]++; //m=120 a[120]++
	}
	for(int i=110;i<=180;i++){ //根据身高寻找桶的编号
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++){
				cout<<i<<' ';
			}
		}
	}
	return 0;
}
