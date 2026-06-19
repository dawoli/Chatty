#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[5005];
int res=0;
int n;
void dfs(int i,int cnt,int xuan,int maxx){
	if(i>n){
		if(xuan>=3&&cnt>2*maxx){
			res++;
			return ;
		}
		return ;
	}
	dfs(i+1,cnt+a[i],xuan+1,max(maxx,a[i]));
	dfs(i+1,cnt,xuan,maxx);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx==1){
		int u=1;
		for(int i=1;i<=n;i++){
			u=u*2%mod;
		}
		u=u-1;
		u=u-n;
		u=u-(n-1)*n/2;
		u=u%mod;
		cout<<u;
	}
	else if(n==3){
		if(a[1]+a[2]+a[3]>2*maxx){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		dfs(1,0,0,0);
		cout<<res;
	}
	return 0;
}
