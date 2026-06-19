#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb emplace_back 
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair 
int read(){
	int x=0;char ch=getchar();
	while(ch<'0' || ch>'9')ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
} 
int fa[20005];
void init(int n){
	for(int i=1;i<=n;i++)fa[i]=i;
}
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]); 
}
void myunion(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
bool connected(int x,int y){
	return find(x)==find(y);
} 
int n,m,k;
int val[15];
vector<pii> a[15];
struct edge{
	int u,v,w;
}e[1000005],wk[200005];
int cnt,ct[15];
bool vis[1000005];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
ll res;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+1+m,cmp);
	init(n);
	for(int i=1;i<=m;i++)
		if(!connected(e[i].u,e[i].v)){
			myunion(e[i].u,e[i].v);
			res+=e[i].w;
			vis[i]=1;
		}
//	printf("%lld\n",res);
	for(int i=1;i<=m;i++)
		if(vis[i])
			e[++cnt]=e[i];
	m=cnt;
	for(int i=1;i<=k;i++){
		val[i]=read();
		for(int j=1;j<=n;j++){
			int p;p=read();
			a[i].pb(mp(p,j));
		} 
		sort(a[i].begin(),a[i].end());
	} 
	for(int i=1;i<(1<<k);i++){
		ll sum=0,sum_e=m,coun=0;
		vector<int> id;
		for(int j=1;j<=k;j++)if((i>>j-1)&1){
			sum+=val[j];
			id.pb(j);sum_e+=n;coun++;
		}
		cnt=0;
		for(int j=0;j<=k;j++)ct[j]=1;
		for(int j=1;j<=sum_e;j++){
			int mn=1e9,mnid=-1;
			for(int p:id){
				if(ct[p]==n+1)continue;
				if(mn>a[p][ct[p]-1].fi){
					mn=a[p][ct[p]-1].fi;
					mnid=p;
				}
			}
			if(ct[0]<=m){
				if(mn>e[ct[0]].w){
					mn=e[ct[0]].w;
					mnid=0;
				}
			}
			if(mnid==0)wk[j]=e[ct[0]],ct[0]++;
			else wk[j]=edge{n+mnid,a[mnid][ct[mnid]-1].se,mn},ct[mnid]++;
		}
		init(n+k);
		for(int j=1;j<=sum_e;j++)
			if(!connected(wk[j].u,wk[j].v)){
				sum+=wk[j].w;
				myunion(wk[j].u,wk[j].v);
			} 
		res=min(res,sum);
	} 
	printf("%lld\n",res);
	return 0;
}
