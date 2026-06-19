#include<iostream>
#include<string>
using namespace std;
char map[1145][1145];
bool vis[1145][1145];
int nx=0,ny=0,face0=0,n,m,k;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				vis[i][j]=0;
				map[i][j]=0;
			}	
		}
		scanf("%d %d %d",&n,&m,&k);
		scanf("%d %d %d",&nx,&ny,&face0);
		for(int i=1;i<=n;i++)
		{
			string in;
			cin>>in;
			for(int j=1;j<=m;j++)
			{
				map[i][j]=in[j-1];
			}	
		}		
		for(int step=0;step<k;step++)
		{
			int tx=nx,ty=ny;
			if(face0==0){ty++;}
			else if(face0==1){tx++;}
			else if(face0==2){ty--;}
			else if(face0==3){tx--;}
			if(tx<=n && ty<=m &&tx>=1 && ty>=1 && map[tx][ty]=='.')
			{
				nx=tx,ny=ty;
				vis[nx][ny]=1;
			}
			else face0=(face0+1)%4;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j])cnt++;
			}	
		}
		cout<<cnt+1<<endl;
	}
	return 0;
}
