#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int maxn=0,sumn=0;
		for(int i=1;i<=3;i++){
			sumn+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(sumn>maxn*2)cout<<1;
		else cout<<0;
	}
	
	if(n==4){
		int ans=0;
		int maxn=0,sumn=0;
		for(int i=1;i<=3;i++){
			sumn+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(sumn>maxn*2)ans++;
		maxn=0,sumn=0;
		for(int i=2;i<=4;i++){
			sumn+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(sumn>maxn*2)ans++;
		maxn=0,sumn=0;
		sumn=a[1]+a[3]+a[4];
		maxn=max(a[1],max(a[3],a[4]));
		if(sumn>maxn*2)ans++;
		maxn=0,sumn=0;
		sumn=a[1]+a[2]+a[4];
		maxn=max(a[1],max(a[2],a[4]));
		if(sumn>maxn*2)ans++;
		cout<<ans;
	}
	
	return 0;
}
