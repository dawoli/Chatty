#include<iostream>
using namespace std;
int n,mini=100000,maxi;
int main(){	
	cin>>n;
	int a[n+1],b[n],c[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int i=1;i<=n;i++){
		b[i]=true;
		c[i]=0;
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]<=a[j]&&i!=j&&b[j]&&b[i]&&c[j]==0){
				if(mini>a[i]){
					mini=i;
					maxi=j;
				}
			}
		}
		if(a[maxi]>a[mini]){
			b[mini]=false;
		}
		c[maxi]=1;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(b[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
