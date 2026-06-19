#include <cstdio>
#include <iostream>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
const int N=1e3+5;
int n,m,k,x,y,d;
char MAP[N][N];
bool vis[N][N];
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t; cin>>t;
	while(t--) {
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) {
			cin>>MAP[i][j];
			vis[i][j]=false;
		}
		int cnt=1; vis[x][y]=true;
		while(k--) {
			int tx=x+dx[d],ty=y+dy[d];
			if(tx<1 or n<tx
			or ty<1 or m<ty
			or MAP[tx][ty]=='x') d=(d+1)%4;
			else x=tx,y=ty;
			cnt+=!vis[x][y];
			vis[x][y]=true;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
