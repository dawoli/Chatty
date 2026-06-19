#include<bits/stdc++.h>//错的 
using namespace std;
typedef pair<int,int> pii;
int n,m,k,ans; 
vector<pii>tu[10002],bei;//second表示费用
vector<int>nod;
bool vis[10002];
void Prim(){
	priority_queue<pii,vector<pii>,greater<pii> >pq;//first表示权值 
	pq.push({0,1});
	while(pq.size()){
		int t=pq.top().second,ww=pq.top().first;
		pq.pop();
		if(vis[t])continue;
		vis[t]=1;
		ans+=ww;
		//cout<<t<<" "<<ww<<endl;
		for(int i=0;i<tu[t].size();i++){
			int to=tu[t][i].first,w=tu[t][i].second;
			if(!vis[to]){
				pq.push({w,to});
			}
		}
	}
	cout<<ans<<endl;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		tu[u].push_back({v,w});
		tu[v].push_back({u,w});
	}
	for(int i=1,c;i<=k;i++){//奔着特殊性质A去的 
		cin>>c;
		for(int j=1,x;j<=n;j++){
			cin>>x;
			bei.push_back({j,x});
			if(x==0)nod.push_back(j);
		}
		for(int j=0;j<nod.size();j++){
			for(int k=0;k<n;k++)tu[nod[j]].push_back(bei[k]);
		}
		nod.clear();
		bei.clear();
	}
//	for(int i=1;i<=n;i++){
//		cout<<"第"<<i<<"个点:"<<endl;
//		for(int j=0;j<tu[i].size();j++){
//			cout<<tu[i][j].first<<" "<<tu[i][j].second<<endl;
//		}
//	}
	Prim();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
