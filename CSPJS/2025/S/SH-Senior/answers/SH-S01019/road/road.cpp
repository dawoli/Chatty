#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Edge{
	int to,w;
};

bool cmp(Edge a,Edge b){
	return a.w>b.w;
}

const int N=1e4+40,M=1e6+5,K=13;

int c[K], n, m, k, ans;
bool vis[N];

vector<Edge> a[N];

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int t1,t2,w;
		cin >> t1 >> t2 >> w;
		a[t1].push_back({t2,w});
		a[t2].push_back({t1,w});
	}
//	
//	for(int j=1;j<=k;j++){
//		int w;
//		cin >> w;
//		for(int i=1;i<=n;i++){
//			int w;
//			cin >> w;
//			a[j+n].push_back({i,w});
//			a[i].push_back({j+n,w}); 
//		}
//	}
//	
	for(int i=1;i<=n;i++){
		sort(a[i].begin(),a[i].end(),cmp);
	}
	
	queue<Edge> q;
	q.push({1,0});
	while(!q.empty()){
		Edge f=q.front();
		q.pop();
		if(vis[f.to]) continue;
		vis[f.to]=1;
		ans+=f.w;
		for(Edge it: a[f.to]){
			q.push(it);
		}
	}
	cout << ans;
}
