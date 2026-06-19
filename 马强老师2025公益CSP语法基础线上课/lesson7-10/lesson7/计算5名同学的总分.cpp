#include<iostream>
using namespace std;
int main(){
	int a[5];
	for(int i=0;i<=4;i++)
		cin>>a[i];
	int sum=0;
	for(int i=0;i<=4;i++)
		sum+=a[i];
	
//	sum=a[0]+a[1]+a[2]+a[3]+a[4];
	cout<<sum;
	return 0;
}
