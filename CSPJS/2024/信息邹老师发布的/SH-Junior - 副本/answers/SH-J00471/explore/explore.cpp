#include<bits/stdc++.h>
using namespace std;

constexpr int N=1007;

int n,m,k,x,y,d;
char grid[N][N];

map<pair<int,int>,bool> vis;

void deal(){
	int _x=x,_y=y;
	if(d==0)++_y;
	else if(d==1)++_x;
	else if(d==2)--_y;
	else --_x;
	if(1<=_x&&_x<=n&&1<=_y&&_y<=m&&grid[_x][_y]=='.'){
		x=_x,y=_y;
		vis[make_pair(x,y)]=1;
	}
	else{
		d=(d+1)%4;
	}
}

void solve(){
	cin>>n>>m>>k>>x>>y>>d;
	vis.clear();
	vis[make_pair(x,y)]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>grid[i][j];
		}
	}
	while(k--)deal();
	cout<<vis.size()<<'\n';
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int tc;cin>>tc;
	while(tc--){
		solve();
	}
}
