#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 10010
#define maxm 1000010
#define EIOP (s&(1<<e[i].v-n-1))
using namespace std;
typedef long long ll;
int n,m,k,head[maxn+20],nxt[(maxm<<1)+40*maxn],c[20],a[20][maxn],cnt=0;
int vis[maxn+20];
struct edge{
	int v,w;
	bool operator<(const edge& b)const{
		return w>b.w;
	}
}e[(maxm<<1)+40*maxn];
priority_queue<edge> que;
inline void add(int u,int v,int w){
	e[++cnt].v=v,e[cnt].w=w;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);	
	}
	for(int i=0;i<k;++i){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
			add(n+1+i,j,a[i][j]);
			add(j,n+1+i,a[i][j]);
		}
	}
	ll mina=1e16;
	for(int s=0;s<1<<k;++s){
		memset(vis,0,sizeof(vis));
		que=*(new priority_queue<edge>);
		vis[1]=1;
		int tot=1;ll ans=0;
		for(int i=head[1];i;i=nxt[i]){
			if(e[i].v>n&&!EIOP)continue;
			que.push(e[i]);
		}
		for(int i=0;i<k;++i){
			if(s&(1<<i))ans+=c[i],--tot;
		}
		while(tot<n){
			edge p=que.top();que.pop();
			if(vis[p.v])continue;
			vis[p.v]=1,++tot,ans+=p.w;
			//cout<<p.v<<' '<<p.w<<'\n';
			for(int i=head[p.v];i;i=nxt[i]){
				if(vis[e[i].v]||(e[i].v>n&&!EIOP))continue;
				que.push(e[i]);
			}
		}
		mina=min(mina,ans);
		//cout<<ans<<'\n';
	}
	printf("%lld\n",mina);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13
*/

