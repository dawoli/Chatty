#include<bits/stdc++.h>
using namespace std;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
char mp[1003][1003];
bool vis[1003][1003];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,x,y,d;
	scanf("%d",&t);
	while(t--){
		memset(vis,false,sizeof(vis));
		int n,m,k,cnt=1;
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		vis[x][y]=true;
		for(int i=1;i<=k;i++){
			int nx=x+dir[d][0],ny=y+dir[d][1];
			if(nx>=1 && nx<=n && ny>=1 && ny<=m && mp[nx][ny]=='.'){
				x=nx;
				y=ny;
				if(!vis[nx][ny]){
					cnt++;
					vis[nx][ny]=true;
				}
			}else{
				d++;
				d%=4;
			}
		}
		printf("%d\n",cnt);
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
