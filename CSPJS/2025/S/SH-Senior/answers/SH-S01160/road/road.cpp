#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int tto[1000020];
int ttoid=1;
struct line{
	int to;
	int val;
};
int a[15][10010];
int c[15];
bool flag[1000011];
vector<line> l[1000011];
int dfs(int x,int y,int pn){
	if(x==y) return pn;
	while(!l[x].empty()){
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		l[u].push_back({v,w});
		l[v].push_back({u,w});
		tto[ttoid]=w;
		ttoid++;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int b;
			cin>>b;
			l[1000000+i].push_back({j,b});
			l[j].push_back({1000000+i,b});
			tto[ttoid]=b+c[i];
			ttoid++;
		}
	}
	sort(tto+1,tto+ttoid+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(tto[i]!=0) ans+=tto[i];
	}
	cout<<ans<<endl;
	return 0;
} 
