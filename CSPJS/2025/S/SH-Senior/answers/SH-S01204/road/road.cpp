#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn=1e4+5;
const int maxm=1e6+5;
bool vis[maxn];
int dis[maxn];
long long ans;
struct node{
	int cnt;
	int p[maxn];
	int c[maxn];
}e[maxn];

void f(int now){
	vis[now]=1;
	int minn=0x3f3f3f3f,minp=0;
	for(int i=1;i<=e[now].cnt;i++){
		dis[e[now].p[i]]=min(dis[e[now].p[i]],e[now].c[i]);
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			flag=0;
			if(minn>dis[i]){
				minn=dis[i];
				minp=i;
			}
		}
	}
	if(flag==1) return;
	ans+=minn;
	f(minp);
	
}

void solve14(){
	memset(dis,0x3f,sizeof(dis));
	f(1);
	cout<<ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].cnt++;
		e[u].p[e[u].cnt]=v;
		e[u].c[e[u].cnt]=w;
		e[v].cnt++;
		e[v].p[e[v].cnt]=u;
		e[v].c[e[v].cnt]=w;
	}
	if(k==0){
		solve14();
	}
	
	return 0;
}
