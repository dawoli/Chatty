#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf ((long long)(1e18))
#define pr pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define N 11000
#define M 1000020
#define K 11
int n,k,m,u,v,w,fa[N],sz[N],cnt,c[N],ans,now[N],sum;
struct node{
	int u,v,w;
}r[M],q[K][N];
inline int cmp(node x,node y){
	return x.w<y.w;
}
inline int find(int x){
	return (fa[x]==x)?(x):(fa[x]=find(fa[x]));
}
inline void merge(int x,int y){
	if(sz[find(x)]>sz[find(y)]){
		swap(x,y);
	}
	sz[find(y)]+=sz[find(x)];
	fa[find(x)]=find(y);
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
		sz[i]=1;
	}
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(r[i].u)!=find(r[i].v)){
			merge(r[i].u,r[i].v);
			cnt++;
			q[0][cnt]=r[i];
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			q[i][j].u=n+i;
			q[i][j].v=j;
			cin>>q[i][j].w;
		}
		sort(q[i]+1,q[i]+n+1,cmp);
	}
	ans=inf;
	for(int i=0;i<=(1LL<<k)-1;i++){
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
			sz[j]=1;
		}
		sum=0;
		for(int j=0;j<=k;j++){
			if((j>=1)&&(i&(1LL<<j-1))){
				sum+=c[j];
			}
			now[j]=1;
		}
		for(int l=1;l<=n-1+__builtin_popcount(i);l++){
			int pos=-1;
			for(int g=0;g<=k;g++){
				if((g==0)||(i&(1LL<<g-1))){
					while(q[g][now[g]].u&&(find(q[g][now[g]].u)==find(q[g][now[g]].v))){
						now[g]++;
					}
					if(q[g][now[g]].u&&((pos==-1)||(q[g][now[g]].w<=q[pos][now[pos]].w))){
						pos=g;
					}
				}
			}
			sum+=q[pos][now[pos]].w;
			if(sum>=ans){
				break;
			}
			merge(q[pos][now[pos]].u,q[pos][now[pos]].v);
			now[pos]++;
		}
		ans=min(ans,sum);
	}
	cout<<ans<<'\n';
	return 0;
}
