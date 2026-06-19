#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;

const int N=1e6+30;
const int mxN=1e4+10;

int n, m, k, fa[N], a[11][mxN], c[11], vis[11];
int G[1001][1001], tmpt[1001][1001];
struct node{
	int u, v, w;
}e[N];
int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
priority_queue<pii, vector<pii>, greater<pii> >q;
priority_queue<pair<int, pii>, vector<pair<int, pii> >, greater<pair<int, pii> > >Q;
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		int ans=0;
		for(int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
			q.push({e[i].w, i});
		}
		for(int i=1;i<=n;i++)fa[i]=i;
		while(!q.empty()){
			int id=q.top().sec;q.pop();
			int u=e[id].u, v=e[id].v;
			if(find(u)==find(v))continue;
			fa[find(u)]=find(v);
			ans+=e[id].w;
		}
		cout<<ans<<endl;
		return 0;
	}
	else{
		for(int i=1;i<=m;i++){
			int u, v, w;
			cin>>u>>v>>w;
			Q.push({w, {u, v}});
			if(u<=1000&&v<=1000){
				G[u][v]=G[v][u]=w;
			}
		}
		bool flag=0;
		for(int i=1;i<=k;i++){
			cin>>c[i];
			int st=-1;
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
				if(a[i][j]==0)st=j;
			}
			if(st!=-1){
				flag=1;
				for(int j=1;j<=n;j++){
					Q.push({a[i][j], {st, j}});
				}
			}
		}
		if(flag==0){
			int ans=1e16, tot=0;
			for(int S=0;S<(1<<k);S++){
				while(!Q.empty())Q.pop();
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(G[i][j]!=0)
							tmpt[i][j]=G[i][j];
						else tmpt[i][j]=1e16;
					}
				}
				int sum=0;
				for(int j=0;j<k;j++){
					if((S&(1<<j))>0){
						sum+=c[j+1];
					}
				}
				for(int j=0;j<k;j++){
					if((S&(1<<j))>0){
						for(int u=1;u<=n;u++){
							for(int v=u+1;v<=n;v++){
								if(u==v)continue;
								if(tmpt[u][v]>a[j+1][u]+a[j+1][v]){
									tmpt[u][v]=a[j+1][u]+a[j+1][v];
								}
							}
						}
					}
				}
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(tmpt[i][j]!=1e16)Q.push({tmpt[i][j], {i, j}});
					}
				}
				if(sum<0)ans=min(ans, ans-sum);
				for(int i=1;i<=n;i++)fa[i]=i;
				while(!Q.empty()){
					int u=Q.top().sec.sec, v=Q.top().sec.fir, w=Q.top().fir;
					Q.pop();
					if(find(u)==find(v))continue;
					tot++;
					fa[find(u)]=find(v);
					sum+=w;
				}
//				cout<<sum<<endl;
				ans=min(ans, sum);
			}
			cout<<ans<<endl;
		}
		else{//A
			int ans=0;
			for(int i=1;i<=n;i++)fa[i]=i;
			while(!Q.empty()){
				int u=Q.top().sec.sec, v=Q.top().sec.fir, w=Q.top().fir;
				Q.pop();
				if(find(u)==find(v))continue;
				fa[find(u)]=find(v);
				ans+=w;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
