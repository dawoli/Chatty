#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,a[500010],pre[500010],ans=0,maxn=LONG_LONG_MIN,flagA=1,cnt_0=0,cnt_1=0;
int xingzhiA(){
	return n;
}
int xingzhiB(){
	int tmp=0;
	if(m==1)return cnt_1;
	else return cnt_0/2+cnt_1;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			flagA=0;
			break;
		}
	}
	if(flagA){
		cout<<xingzhiA();
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0)cnt_0++;
		if(a[i]==1)cnt_1++;
	}
	if(cnt_0+cnt_1==n){
		cout<<xingzhiB();
		return 0;
	}
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			if((pre[j]^pre[i-1])==m)ans++;
		}
		maxn=max(ans,maxn);
	}
	cout<<maxn/2;
	return 0;
}
