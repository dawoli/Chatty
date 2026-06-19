#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
char ch;
bool mp[1010][1010],vis[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>ch;
				if(ch=='x')mp[i][j]=1;
			}
		while(k--){
			if(!vis[x][y])vis[x][y]=1,ans++;
			int nx,ny;
			if(d==0)nx=x,ny=y+1;
			else if(d==1)nx=x+1,ny=y;
			else if(d==2)nx=x,ny=y-1;
			else if(d==3)nx=x-1,ny=y;
			if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny])d=(d+1)%4;
			else{
				x=nx,y=ny;
				if(!vis[nx][ny])vis[nx][ny]=1,ans++;
			}
		}
		printf("%d\n",ans);
		ans=0;
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
