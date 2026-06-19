#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5;
int a[N][15],n,m,k,u,v,w,c[15];
ll ans;
bool st[15],vst[N];
map<pair<int,int>,int>dis;
void dfs(int u,int fa,int s){
	if(s==n)return;
	ll money=-1,next=-1;
	for(int i=1;i<=n;i++){
		if(i==fa||i==u||vst[i])continue;
		int t=dis[{u,v}];
		if((money==-1||money>t)&&dis[{u,i}])
			next=i,money=t;
	}
	bool flag=false;
	int b=0;
	for(int i=1;i<=n;i++){
		if(i==fa||i==u||vst[i])continue;
		for(int j=1;j<=k;j++){
			ll temp=(ll)a[j][i]+(ll)a[j][u];
			if(!st[j])temp+=(ll)c[j];
			if(money==-1||temp<money)next=i,money=temp,b=j,flag=true;
		}
	}
	if(flag)st[b]=true;
	vst[next]=true;
	ans+=(ll)money;
	dfs(next,u,s+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		dis[{u,v}]=w,dis[{v,u}]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		st[i]=false;
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
