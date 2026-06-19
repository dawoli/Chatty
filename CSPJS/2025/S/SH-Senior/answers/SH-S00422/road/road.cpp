#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
const ll inf=5e9;
int n,m,k,edt,h[M*2],f[N],c[K],br[N];
ll ans,tot[N],a[K][N];
bool usd[K];
struct node{
	int u,v;
	ll w;
}e[M];
struct edge{
	int to,nxt;
	ll w;
}E[M*2];
void add(int x,int y,int z){
	E[++edt]={y,h[x],z},h[x]=edt;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
ll dfs(int x,int fa){
	ll res=0;
	for(int i=h[x];i;i=E[i].nxt){
	  int y=E[i].to;
	  if(y==fa) continue;
	  if(br[x]==0&&br[y]==0) res+=E[i].w;
	  res+=dfs(y,x);
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int cnt=0;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=m;i++){
	  if(find(e[i].u)==find(e[i].v)) continue;
	  add(e[i].u,e[i].v,e[i].w),add(e[i].v,e[i].u,e[i].w);
	  f[find(e[i].u)]=find(e[i].v),cnt++;
	  ans+=e[i].w,tot[e[i].u]+=e[i].w,tot[e[i].v]+=e[i].w;
	  if(cnt==n-1) break;
	}
	if(k==0){
	  cout<<ans;
	  return 0;
	}
	for(int i=1;i<=k;i++){
	  cin>>c[i];
	  for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int i=0;i<(1<<k);i++){
	  ll res=0;
	  for(int j=1;j<=n;j++) br[j]=0;
	  for(int j=1;j<=k;j++) usd[j]=false;
	  for(int j=1;j<=k;j++){
	  	if(!((1<<(j-1))&i)) continue;
	  }
	  for(int j=1;j<=n;j++){
	  	ll val=1e10; int pos=0;
	    for(int l=1;l<=k;l++){
	      if(!((1<<(l-1))&i)) continue;
	      if(a[l][j]<val) val=a[l][j],pos=l;
	    }
	    if(val<=tot[j]) usd[pos]=true,br[j]=pos;
	  }
	  res+=dfs(1,0);
	  for(int j=1;j<=n;j++){
	  	if(!br[j]) continue;
	  	res+=a[br[j]][j];
	  }
	  for(int j=1;j<=k;j++)
	    if(usd[j]) res+=c[j];
	  ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
