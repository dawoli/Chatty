#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int dis[1005][1005];
char s[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		memset(dis,0,sizeof dis) ;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf(" %c",&s[i][j]);
		//for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)printf(" %c",s[i][j]);
		dis[x][y]=1;
		for(int j=1;j<=k;j++){
			int nx=x+dx[d],ny=y+dy[d];
			if(nx<=0||nx>n||ny<=0||ny>m||s[nx][ny]=='x'){
				d=(d+1)%4;
				//cout<<d<<endl;
			}
			else {
				x=nx,y=ny;
				dis[x][y]=1;
			//	cout<<x<<" "<<y<<endl;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) 
		if(dis[i][j]) cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
