#include<bits/stdc++.h>
using namespace std;
char E[1100][1100];
bool v[1100][1100];
int t;
int n,m,k;
int x,y,d;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen("explore5.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>E[i][j];
			}
		}
		v[x][y]=1;
		for(int i=1;i<=k;i++){
			int tx=x+dir[d][0];
			int ty=y+dir[d][1];
			if(tx>=1 && tx<=n && ty<=m && ty>=1 && E[tx][ty]=='.'){
				x=tx;
				y=ty;
				v[x][y]=1;
			}
			else{
				d=(d+1)%4;
			}
		}
		int num=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(v[i][j]==1){
					num++;
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
