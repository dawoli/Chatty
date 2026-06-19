#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>> >,greater<pair<int,pair<int,int>> > > pq;
vector<vector<pair<int,int>>> e;
int ne[N],nc[N],pa[N];
int find(int x){
	return (pa[x]==x) ? x : pa[x]=find(pa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
		pa[x]=y;
	}
}
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	e.resize(n+1);
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		pq.push({w,{u,v}});
	}
	for(int i=1;i<=n;++i){
		ne[i]=INT_MAX;
		pa[i]=i;
	}
	int c,x; 
	for(int i=1;i<=k;++i){
		cin>>c;
		for(int i=1;i<=n;++i){
			cin>>x;
			if(x+c<ne[i]){
				ne[i]=x+c;
				nc[i]=c;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(nc[i]!=nc[j]){
				pq.push({ne[i]+ne[j],{i,j}});
			}else{
				pq.push({ne[i]+ne[j]-nc[i],{i,j}});
			}
			
		}
	}
	int cnt=0;
	while(!pq.empty()){
		if(cnt>=n){
			break;
		}
		auto o=pq.top();
		pq.pop();
		int val=o.first;
		auto edge=o.second;
		int u=edge.first,v=edge.second;
		if(find(u)==find(v))	continue;
		merge(u,v);
		cnt++;
		ans+=val;
	}
	cout<<ans<<endl;
	return 0;
}
