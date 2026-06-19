#include<bits/stdc++.h>  //ÆÀ²â»ú¼ÓÓÍ£¬°ÝÈý°Ý
using namespace std;
const long long N=10005;
long long n,m,k,c[15],a[15][N];
long long ans=1e18,sum;
struct edge{
	long long v,w;
};
struct node{
	long long u,d;
	bool operator<(const node&a)const{return d>a.d;}
};
vector<edge> es[N];
long long cho[15];
long long d[N+15];  //MST
bool vst[N+15];
priority_queue<node> q;
inline void check(){
	long long rtn=0;
	if(n*n<=m){
		for(long long i=1;i<=sum;++i){
			rtn+=c[cho[i]];
		}
		fill(d+1,d+n+sum+1,1e18); fill(vst+1,vst+n+sum+1,0);
		d[1]=0;
		for(register long long mm=0;mm<=n;){  //n^2+m+kn==1000000
			long long u=1,MIN=1e9,v;
			for(long long i=1;i<=n+sum;++i)
				if(d[i]<MIN&&vst[i]==0) MIN=d[u=i];
			vst[u]=1; rtn+=d[u];
			if(u<=n){  //u is city
				mm++; 
				for(register long long i=0;i<es[u].size();++i){
					v=es[u][i].v;
					if(!vst[v]){
						d[v]=min(d[v],es[u][i].w);
					}
				}
				for(long long i=1;i<=sum;++i){
					v=cho[i]+n;
					if(!vst[v]){
						d[v]=min(d[v],a[cho[i]][u]);
					}
				}
			}
			else{  //u isn't city
				for(register long long i=1;i<=n;++i)
					if(!vst[i]) d[i]=min(d[i],a[cho[u-n]][i]);
			}
			if(rtn>ans) return;
		}
		ans=min(ans,rtn);
	} 
	else{
		while(!q.empty()) q.pop();
		for(long long i=1;i<=sum;++i){
			rtn+=c[cho[i]];
		}
		fill(d+1,d+n+sum+1,1e18); fill(vst+1,vst+n+sum+1,0);
		d[1]=0; q.push((node){1,0});
		while(!q.empty()){  //n^2+m+kn==1000000
			long long u=q.top().u,v; q.pop();
			if(vst[u]) continue;
			vst[u]=1; rtn+=d[u];
			if(u<=n){  //u is city
				for(register long long i=0;i<es[u].size();++i){
					v=es[u][i].v;
					if(!vst[v]){
						if(d[v]>es[u][i].w){
							d[v]=es[u][i].w;
							q.push((node){v,d[v]});
						}
					}
				}
				for(long long i=1;i<=sum;++i){
					v=i+n;
					if(!vst[v]){
						if(d[v]>a[cho[i]][u]){
							d[v]=a[cho[i]][u];
							q.push((node){v,d[v]});
						}
					}
				}
			}
			else{  //u isn't city
				for(register long long i=1;i<=n;++i)
					if(!vst[i]){;
						if(d[i]>a[cho[u-n]][i]){
							d[i]=a[cho[u-n]][i];
							q.push((node){i,d[i]});
						}
					}
			}
			if(rtn>ans) return;
		}
		ans=min(ans,rtn);
	}
}
inline void dfs(long long x){  //1024
	if(x==k+1){check(); return;}
	if(c[x]!=0){
		cho[++sum]=x;
		dfs(x+1);
		cho[sum--]=0;
		dfs(x+1);
	}
	else{
		cho[++sum]=x;
		dfs(x+1);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(register long long i=1,u,v,w;i<=m;++i){
		scanf("%lld%lld%lld",&u,&v,&w);
		es[u].push_back((edge){v,w});
		es[v].push_back((edge){u,w});
	}
	for(long long i=1;i<=k;++i){
		cin>>c[i];
		for(long long j=1;j<=n;++j) scanf("%lld",a[i]+j);
	}
	dfs(1);
	cout<<ans;
	return 0;
}
