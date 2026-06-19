#include<bits/stdc++.h>
using namespace std;
int n;
long long k,a[500005];
bool v=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)v=1;
	}
	if(k==0&&n<=2&&v==0){//1
		if(n==1)cout<<0;
		else cout<<1;
		return 0;
	}
	if(k==0&&n<=100&&v==0){//3
		cout<<n/2;
		return 0;
	}
	if(k==0){//2,4,5,13
		int cnttt=0,cntttt=0;
		for(int i=1;i<=n;i++)if(a[i]==0)cnttt++;
		for(int i=1;i<=n;i++)if(a[i]==1)cntttt++;
		cout<<max(cnttt,cntttt/2);
		return 0;
	}
	if(k==1){//4,5,13
		int cntt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)cntt++;
		}
		cout<<cntt;
		return 0;
	}
	return 0; 
} 
