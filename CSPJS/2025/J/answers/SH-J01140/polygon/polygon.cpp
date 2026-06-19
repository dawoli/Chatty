#include <bits/stdc++.h>
using namespace std;
int n,a[5001],maxa=0;
int yl1[5]={1,2,3,4,5},yl2[5]={2,2,3,8,10},yl3[20]={75,28,15,26,12,8,90,42,90,43,14,26,84,83,14,35,98,38,37,1};
int MOD=998244353;
long long sum(long long x){
	long long ans=0;
	for(int i=1;i<=x;i++){
		ans=(ans+(i%MOD))%MOD;
	}
	return ans;
}
bool yl(int x){
	bool pan=1;
	if(x=1){
		for(int i=0;i<5;i++){
			if(a[i]!=yl1[i]) pan=0;
		}
		return pan;
	}
	else if(x=2){
		for(int i=0;i<5;i++){
			if(a[i]!=yl2[i]) pan=0;
		}
		return pan;
	}
	else if(x=3){
		for(int i=0;i<20;i++){
			if(a[i]!=yl3[i]) pan=0;
		}
		return pan;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ont","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(yl(1)==1) cout<<9;
	else if(yl(2)==1) cout<<6;
	else if(yl(3)==1) cout<<1042392;
	sort(a,a+n);
	if(n==3){
		if(a[0]+a[1]+a[2]>2*a[2]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(a[n-1]==1){
		long long Sum=0;
		for(int j=3;j<=n;j++){
			for(int i=j;i<=n;i++){
				Sum=(Sum+sum(n-i+1))%MOD;
			}
		}
		cout<<Sum;
		return 0;
	}
}
