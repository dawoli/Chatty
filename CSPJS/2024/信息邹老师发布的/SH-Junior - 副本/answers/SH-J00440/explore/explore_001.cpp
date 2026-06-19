#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
int nxt[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				char c;
				cin>>c;
				if(c=='x')vis[j][l]=2;
			}
		}
		vis[x][y]=1;
		int cnt=1;
		while(k){
			int nx=x+nxt[d][0];
			int ny=y+nxt[d][1];
			if((nx>=1&&nx<=n&&ny>=1&&ny<=m)&&vis[nx][ny]!=2){//´ËÂ·Í¨ 
				x=nx;
				y=ny;
				if(vis[x][y]==0)cnt++;
				vis[x][y]=1;
				k--;
				continue;
			}
			k--;
			d=(d+1)%4;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
