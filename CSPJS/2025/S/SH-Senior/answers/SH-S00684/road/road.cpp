#include<bits/stdc++.h>
using namespace std;
const int N=120005;
const int M=1e6+5;
const int K=10+2;
int n,m,k;
struct node{
	int u,v,w;
	node(int au=0,int av=0,int aw=0){
		u=au;
		v=av;
		w=aw;
	}
}x[M],y[N];
int cnt;
int c[K];
int a[N][K],a2[N][K];
int fa[N];
int vis[N],tot;
int val[M],cnt2;
int w2[N];
vector<int>G[N];
int size[N];
int find(int x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x[i].u>>x[i].v>>x[i].w; 
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j][i];
			val[++cnt2]=a[i][j]; 
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	long long ans=0;
	sort(x+1,x+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=find(x[i].u),v=find(x[i].v);
		if(u!=v){
			fa[u]=v;
			ans+=x[i].w;
			y[++cnt]=x[i];
		}
	}
	for(int i=1;i<=cnt;i++){
		val[++cnt2]=y[i].w;
	}
	sort(val+1,val+cnt2+1);
	cnt2=unique(val+1,val+cnt2+1)-val;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			a2[i][j]=lower_bound(val+1,val+cnt2+1,a[i][j])-val;
		}
	}
	for(int i=1;i<=cnt;i++){
		w2[i]=lower_bound(val+1,val+cnt2+1,y[i].w)-val;
	}
	int u,v;
	long long nowans=0;
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				vis[j]=1;
				tot++;
			}
			else{
				vis[j]=0;
			}
		}
		for(int i=1;i<=cnt;i++){
			G[w2[i]].push_back(i);
		}
		for(int j=1;j<=k;j++){
			if(vis[j]){
				for(int z=1;z<=n;z++){
					y[++cnt]=node(n+j,z,a[z][j]);
					G[a2[z][j]].push_back(cnt);
				}
			}
		}
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
			size[j]=1;
		}
		nowans=0;
		for(int j=1;j<=cnt2;j++){
			for(int z:G[j]){
				u=find(y[z].u),v=find(y[z].v);
				if(u!=v){
					if(size[u]<size[v])	fa[u]=v;
					else	fa[v]=u;
					nowans+=y[z].w;
					if(nowans>ans)	break;
				}
			}
			if(nowans>ans)	break;
		} 
		for(int j=1;j<=cnt2;j++){
			G[j].clear();
		}
		cnt=n-1;
		for(int j=1;j<=k;j++){
			if(vis[j]==1){
				nowans+=c[j];
			}
		}
		tot=0;
		ans=min(ans,nowans);
	}
	cout<<ans;
	return 0;
} 
