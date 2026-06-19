#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
const int N=1e4+100,M=1e6+100;

//struct edge{
//	ll v,next,w;
//}e[M<<1];
//int head[N],tot;
//il void addedge(int u,int v,int w){
//	e[++tot].v=v,
//	e[tot].w=w,
//	e[tot].next=head[u];
//	head[u]=tot;
//} 

//For:56pts

ll n,m,k,lm;
ll c[20],a[12][N],ans,zans=1ll<<60;
int loc[12];
struct ee{
	ll u,v,w;
}e[M<<1];
bool ok[12];
bool cmp(ee x,ee y){
	return x.w<y.w;
}

int fa[N<<1],siz[N<<1];
int fnd(int x){
	return fa[x]==x?x:fa[x]=fnd(fa[x]);
}
il void merg(int x,int y){
	x=fnd(x),y=fnd(y);
	if(siz[x]>siz[y]){
		fa[y]=x;
		siz[x]+=siz[y],siz[y]=0;
	}
	else{
		fa[x]=y;
		siz[y]+=siz[x],siz[x]=0;
	}
}

ee te[M<<1];
il void solve1(){
	for(int i=1;i<=m;i++)te[i]=e[i];
	sort(te+1,te+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	for(int i=1;i<=m && cnt<n-1;i++){
		if(fnd(te[i].u)==fnd(te[i].v))continue;
		merg(te[i].u,te[i].v);
		ans+=te[i].w,cnt++;
	}
}

void dfs(int nw){
	if(nw>k){
		ans=0;
		m=lm;
		int op=0;
		for(int i=1;i<=k;i++){
			if(ok[i]){
				op++;
				ans+=c[i];
				for(int j=1;j<=n;j++){
					e[++m].u=j,e[m].v=n+op,e[m].w=a[i][j];
				}
			}
		}
		n+=op;
		solve1();
		n-=op;
//		cout<<ans<<'\n';
		zans=min(zans,ans);
		return;
	}
	dfs(nw+1);
	ok[nw]=1;
	dfs(nw+1);
	ok[nw]=0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
//		addedge(u[i],v[i],w[i]);
//		add
	}
	bool flga=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0)loc[i]=j;
		}
		if(c[i]!=0 || loc[i]==0)flga=0;
	}
	
	if(k==0){
		solve1();
		cout<<ans;
	}
	else if(flga){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e[++m].u=j,e[m].v=loc[i],e[m].w=a[i][j];
			}
		}
		solve1();
		cout<<ans;
	}
	else{
		lm=m;
		dfs(1);
		cout<<zans;
//		solve1();
//		cout<<ans;
	}
	
	return 0;
}
