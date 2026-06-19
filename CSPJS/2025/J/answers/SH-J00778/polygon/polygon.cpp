#include<bits/stdc++.h>
using namespace std;

#define int long long

const int Maxn=5e4,Mod=998244353;
int n,a[Maxn+5],j[Maxn+5],cnt;
bool v[Maxn+5];

void dfs(int x){
	if(x==n+1){
		int cnt1=0,sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			if(v[i]) cnt1++,sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(cnt1<3) return;
		else if(sum>maxn*2) cnt++,cnt%=Mod;
		return;
	}
	v[x]=true,dfs(x+1);
	v[x]=false,dfs(x+1);
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=true;
	}
	dfs(1);
	cout<<cnt%Mod<<endl;
	return 0;
}
