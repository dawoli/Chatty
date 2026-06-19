#include <bits/stdc++.h>
#define int long long
#define endl \n
using namespace std;
typedef pair<int,int> PI;
vector<PI> v[10015];
int n,m,k,u,v1,w,c[15],vis[10015],dist[10005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dist,0x3f,sizeof(dist));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u>>v1>>w;
		v[u].push_back({v1,w});
		v[v1].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>w;
			v[i].push_back({j,w});
			v[j].push_back({i,w});
		}
	}
	queue<PI> q;
	q.push({1,0});
	dist[1]=0;
	while(q.size()){
		PI t=q.front();
		int t1=t.first,t2=t.second;
		q.pop();
		for(PI o:v[t1]){
			int i=o.first,j=o.second;
			if(vis[i]) continue;
			vis[i]=1;
			if(i>n) q.push({i,t2+j+c[i-n]});
			else{
				q.push({i,t2+j});
				dist[i]=min(dist[i],dist[t1]+t2+j);
			}
		}
	}
	cout<<dist[n];
	return 0;
}
