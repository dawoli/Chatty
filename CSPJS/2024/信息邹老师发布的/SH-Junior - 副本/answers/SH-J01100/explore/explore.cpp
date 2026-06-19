#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int N=1007;
int t;
int n,m,k;
int x,y,d,vis[N][N];
char a[N][N];
int dx[4]={0,1,0,-1},
	dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				vis[i][j]=0;
		scanf("%d%d%d",&x,&y,&d);
		for(int i=1;i<=n;i++)
			scanf("%s",a[i]+1);
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=m+1;j++)
				if(i<1||i>n||j<1||j>m)
					a[i][j]='x';
		vis[x][y]=1;
		for(int i=1;i<=k;i++){
			int nx=x+dx[d],ny=y+dy[d];
			if(a[nx][ny]=='x')
				d++,d%=4,
				nx=x+dx[d],
				ny=y+dy[d];
			else
				vis[nx][ny]=1,
				x=nx,
				y=ny;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans+=vis[i][j];
		printf("%d\n",ans);
	}
} 
/*

*/
