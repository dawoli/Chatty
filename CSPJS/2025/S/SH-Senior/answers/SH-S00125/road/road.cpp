#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> c[10005];
int n,m,k,u,v,w,ans=1e6;
bool book[10005];
bool check(){
	for(int i=1;i<=n;i++){
		if(book[i]==0) return 0;
	}
	return 1;
}
void dfsa(int col,int now,int cost){
	//cout<<now<<' '<<cost<<endl;
	if(col>=n and check()){
		ans=min(ans,cost);
		//cout<<"$^&*"<<' '<<cost<<endl<<endl;
		return;
	}
	
	for(int i=1;i<=n+k;i++){
		if(book[i]) continue;
		book[i]=1;
		for(auto f:c[i]){
			
			if(book[f.first]) continue;
			//cout<<f.first<<'%'<<f.second<<endl;
			book[f.first]=1;
			dfsa(col+1,f.first,cost+f.second);
			
			book[f.first]=0;
		}
		book[i]=0;
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		c[u].push_back({v,w});
		c[v].push_back({u,w});
	}
	
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			
			cin>>w;
			if(j==0) continue;
			c[i+n].push_back({j,w});
			c[j].push_back({i+n,w});
		}
	}
	book[u]=1;
	dfsa(1,u,0);
	cout<<ans;
	return 0;
}
