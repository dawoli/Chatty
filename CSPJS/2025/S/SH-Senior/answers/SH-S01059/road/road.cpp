#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000005
#define N 100005
int n,m,k;
ll ans,CNT;
struct e_info{
	int u,v,w;
}e0[M],e[2][N*11];
int tot,sg;
bool comp(e_info xx,e_info yy){
	return xx.w<yy.w;
}
int fa[N];
int find(int x){
	return x==fa[x]?x:(fa[x]=find(fa[x]));
}
int cst[11];
e_info chg[11][N];
void add(int x){
	int tt=0,p=0;
	for(int i=1;i<=tot;i++){
		while(p<n&&chg[x][p+1].w<=e[sg][i].w)
			e[sg^1][++tt]=chg[x][++p];
		e[sg^1][++tt]=e[sg][i];
	}
	for(int i=p+1;i<=n;i++)
		e[sg^1][++tt]=chg[x][p];
	tot=tt;
	sg^=1;
}
void del(int x){
	int tt=0;
	for(int i=1;i<=tot;i++)
		if(e[sg][i].u!=n+x)
			e[sg^1][++tt]=e[sg][i];
	tot=tt;
	sg^=1;
}
void dfs(int pos,int cnt,ll sum){
	if(pos>k){
		if(!cnt) return;
		for(int i=1;i<=n+k;i++)
			fa[i]=i;
		ll res=sum,con=0;
		for(int i=1;i<=tot&&con<n+cnt;i++){
			int u=e[0][i].u,v=e[0][i].v,w=e[0][i].w;
			int fu=find(u),fv=find(v);
			if(fu!=fv){
				con++;
				fa[fu]=fv;
				res+=w;
			}
		}
		ans=min(ans,res);
		return;
	}
	dfs(pos+1,cnt,sum);
	add(pos);
	dfs(pos+1,cnt+1,sum+cst[pos]);
	del(pos);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e0[i].u,&e0[i].v,&e0[i].w);
	sort(e0+1,e0+m+1,comp);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=e0[i].u,v=e0[i].v,w=e0[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fu]=fv;
			ans+=w;
			e[0][++tot]={u,v,w};
		}
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&cst[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&chg[i][j].w),
			chg[i][j].u=n+i,
			chg[i][j].v=j;
		sort(chg[i]+1,chg[i]+n+1,comp);
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
