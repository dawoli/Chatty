#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long n,m,k;
long long u,v,w; // useless
bool visited[10005];
long long rebuild_c[11];
long long c[11][10005];
long long ans;


struct child{
	long long e;
	long long w;
};

bool operator <(child a,child b){
	return a.w>b.w;
}
vector<child> son[10005];
priority_queue<child> q;



int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n>> m >> k;
	int minw=1000000005, minw_u;
	for(int i=1;i<=m;i++){
		cin >> u >> v >> w;
		son[u].push_back({v,w});
		son[v].push_back({u,w});
		if(w<minw){
			minw=w;
			minw_u=u;
		}
	}
	for(int i=1;i<=k;i++){
		cin >> rebuild_c[i];
		bool z=0;
		int zj=0;
		for(int j=1;j<=n;j++){
			cin >> c[i][j];
			if(c[i][j]==0){
				z=1;
				zj=j;
			}
		}
		if(z){
			for(int j=1;j<=n;j++){
				son[zj].push_back({j,c[i][j]});
				if(c[i][j]<minw){
					minw=c[i][j];
					minw_u=zj;
				}
			}
		}
	}
	for(auto x:son[minw_u]){
		q.push({x.e,x.w});
	}
	visited[minw_u]=1;
	while(!q.empty()){
		int y=q.top().e;
		int z=q.top().w;
		q.pop();
		if(visited[y]==0){
			ans+=z;
			for(auto xy:son[y]){
				q.push({xy.e,xy.w});
			}
			visited[y]=1;
		}
	}
	cout << ans;
	
	
	
	return 0;
}


