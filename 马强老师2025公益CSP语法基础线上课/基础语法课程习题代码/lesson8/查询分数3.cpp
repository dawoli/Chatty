#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[100]={};
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ave=0,sum=0;
	for(int i=0;i<n;i++)
		sum+=a[i];
	ave=sum/n;
	cout<<ave<<endl;
	for(int i=0;i<n;i++)
		if(a[i]>ave)
			cout<<i+1<<' ';//id==下标+1
	return 0;
}
