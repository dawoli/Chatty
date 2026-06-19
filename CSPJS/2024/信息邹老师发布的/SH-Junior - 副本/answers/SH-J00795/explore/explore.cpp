#include <bits/stdc++.h>
using namespace std;
char mp[1009][1009];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n,m,k,x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[i][j];
		mp[x][y]='@';
		while(k--){
			int nx=x+dx[d],ny=y+dy[d];
			if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='x'){
				d=(d+1)%4;
				continue;
			}x=nx,y=ny;
			mp[x][y]='@';
		}
		int area=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(mp[i][j]=='@') area++;
		cout<<area<<endl;
	}
	return 0;
}
