#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> >a[10005];
int fa[10005];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int n,m,k;
void dfs(int x,int cnt,int value){
	int noww=0;
	int maxx=2147483647;
	int idx=0;
	if(cnt==n){
		cout<<value;
		exit(0);
	}
	for(auto i:a[x]){
		if(find(i.first)!=find(x)){
			if(maxx>i.second){
				maxx=i.second;
				idx=noww;
			}
		}
		noww++;
	}
	dfs(a[x][idx].first,cnt+1,value+maxx);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w}); 
	}
	dfs(1,1,0);
	cout<<0;
	return 0;
}

