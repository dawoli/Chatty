#include<bits/stdc++.h>
using namespace std;
int qwer,n,m,k,x,y,d;
char a[1005][1005];
int vis[1005][1005];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int tmp;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d", &tmp);
	while(tmp--){
		int num=1;
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d", &n,&m,&k);
		scanf("%d%d%d", &x,&y,&d);
		for(int i=1;i<=n;i++){
			cin>>a[i]+1;
		}
		vis[x][y]=1;
		for(int i=1;i<=k;i++){
			int xx=x+dir[d][0],yy=y+dir[d][1];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.'){
				x=xx;
				y=yy;
			}else{
				d=(d+1)%4;
			}
			if(vis[x][y]==0){
				num++;
			}
			vis[x][y]=1;
		}
		printf("%d\n", num); 
	}
	return 0;
} 
