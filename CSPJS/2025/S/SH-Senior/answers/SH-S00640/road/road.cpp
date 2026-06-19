#include<bits/stdc++.h>
#define N ((int)(2e6)+10)
using namespace std;
typedef long long ll;
struct node{
	int u,v,c;
};
int n,m,k;
node e[N],h[N];
int c[20],a[20][N];
int height[N];
int fa[N];
bool vis[N];
ll ans=INT64_MAX;
inline bool operator < (node x,node y){
	return x.c<y.c;
}
int find(int x){
	if(x==fa[x])return x;
	else return fa[x]=find(fa[x]);
}
inline ll solve(){
	for(int i=1;i<=m;i++)h[i]=e[i];
	int cnt=m;
	ll res=0;
	for(int i=1;i<=k;i++){
		if(!vis[i])continue;
		res+=c[i];
		for(int j=1;j<=n;j++)h[++cnt]={n+i,j,a[i][j]};
	}
	for(int i=1;i<=cnt;i++)fa[i]=i,height[i]=1;
	sort(h+1,h+cnt+1);
	for(int i=1;i<=cnt;i++){
		int u=h[i].u,v=h[i].v,c=h[i].c;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			res+=c;
			if(height[fu]<height[fv])fa[fu]=fv;
			else if(height[fu]>height[fv])fa[fv]=fu;
			else fa[fu]=fv,height[fv]++;
		}
		if(res>ans)return res;
	}
	return res;
}
inline int read(){
	int res=0;
	char c;
	c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')res=res*10+(c-'0'),c=getchar();
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u,v,c_;
		u=read(),v=read(),c_=read();
		e[i]={u,v,c_};
	}
	bool flag=0;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i])flag=1;
		for(int j=1;j<=n;j++)a[i][j]=read();
	}
	if(!flag){
		for(int i=1;i<=k;i++)vis[i]=i;
		printf("%lld",solve());
		return 0;
	}
	for(int S=0;S<(1<<k);S++){
		if(m>100000&&S>5)break;
		for(int i=1;i<=k;i++)vis[i]=(S&(1<<(i-1)));
		ans=min(ans,solve());
	}
	printf("%lld",ans);
}

