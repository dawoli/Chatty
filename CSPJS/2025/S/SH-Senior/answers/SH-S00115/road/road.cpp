#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[12][10005],u,v,w,c[12],cc[10005];
vector<pair<int,int>> e[10005];
long long c;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++)
			cin >> a[i][j];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			
		}
	}
	return 0;
}
//本人和省二真是一对苦命鸳鸯啊 
