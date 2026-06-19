#include <bits/stdc++.h>
using namespace std;
struct way{
	int to=-1,pay=-1;
};
map <int,vector<way>> ways;
priority_queue<int,vector<int>,greater<int>> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int c=0;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		way now;
		now.to=v;
		now.pay=w;
		ways[u].push_back(now);
		c+=w;
	}
	cout<<c<<endl;
	return 0;
}
