#include <bits/stdc++.h>
using namespace std;

int t,n,m,k,x,y,d,nx,ny,vis[1010][1010];
char c[1010][1010];
int dx[]={1,0,-1,0},
    dy[]={0,1,0,-1};
int search(int ans){
	vis[y][x]=1;
	for (int i=0;i<k;i++){
		nx=x+dx[d],ny=y+dy[d];
		//cout<<x<<" "<<y<<" "<<d<<"\n";
		if (nx<=0 || nx>m || ny<=0 || ny>n || c[ny][nx]=='x'){
			d++;
			if (d==4)  d=0;
			continue;
		}
		x=nx,y=ny;
		vis[y][x]=1;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			//cout<<vis[i][j]<<" ";
			if (vis[i][j])  ans++;
		}
		//cout<<"\n";
	}
	return ans;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while (t--){
		cin>>n>>m>>k;
		cin>>y>>x>>d;
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) cin>>c[i][j];
		}
		cout<<search(0)<<"\n";
//		for (int i=0;i<=1000;i++){
//			for (int j=0;j<=1000;j++) c[i][j]='\0';
//		}
	}
	return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
