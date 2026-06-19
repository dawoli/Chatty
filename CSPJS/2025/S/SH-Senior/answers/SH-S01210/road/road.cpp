#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5; 
const int M=1e6+5;
const ll inf=1e18;
int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
struct edge{
	int u,v,w;
	friend bool operator < (edge a,edge b){
		return a.w<b.w;
	}
}a[M];
vector<edge> b;
struct Edge{
	int v,w;
	friend bool operator < (Edge a,Edge b){
		return a.w<b.w;
	}
}mp[12][N];
int n,m,k,fa[N*2],cst[12];
ll ans;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int u,int v){
	u=find(u),v=find(v);
	fa[u]=v;
}
void dfs(int p,int sz,vector<edge> x,ll w,ll sum){
	if(p==k+1){
		ans=min(ans,w);
		return;
	}
	dfs(p+1,sz,x,w,sum);
	vector<edge> ret;
	sz++,sum+=cst[p],w=sum;
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	int l=0,r=1;
	for(int i=1;i<=x.size()+n;i++){
		int u,v,val;
		if(l<x.size()&&(r>n||x[l].w<mp[p][r].w)){
			u=x[l].u,v=x[l].v,val=x[l].w;
			l++;
		}else{
			u=n+p,v=mp[p][r].v,val=mp[p][r].w;
			r++;
		}
		if(find(u)!=find(v)){
			merge(u,v);
			w+=val;
			ret.push_back({u,v,val});
		}
		if(ret.size()==sz-1)
			break;
	}
	dfs(p+1,sz,ret,w,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	int u,v,w;
	for(int i=1;i<=m;i++){
		u=read(),v=read(),w=read();
		a[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cst[i]=read();
		for(int j=1;j<=n;j++){
			w=read();
			mp[i][j]={j,w};
		}	
		sort(mp[i]+1,mp[i]+1+n);
	}
	sort(a+1,a+1+m);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		if(find(u)!=find(v)){
			merge(u,v);
			ans+=w;
			b.push_back({u,v,w});
		}
		if(b.size()==n-1)
			break;
	}
	dfs(1,n,b,ans,0);
	cout<<ans<<endl;
}
