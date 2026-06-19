#include<bits/stdc++.h>
using namespace std;
int all_the(int a[],int x,int y){
	int k=0;
	for(int i=x;i<=y;i++){
		k+=a[i];
	}
	return k;
}
int max_the(int a[],int x,int y){
	int k=-1;
	for(int i=x;i<=y;i++){
		if(k<a[i])k=a[i];
	}
	return k;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,r=2;
	long long m=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(r<=n){
		for(int i=0;i<n-r;i++){
			if(all_the(a,i,i+r)>max_the(a,i,i+r)*2){
				m++;
			}
		}
		r++;
	}
	cout<<m%998244353;
	return 0;
}
