#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int max_n=1003;
bool map[max_n][max_n],vis[max_n][max_n];
int mx[4]={0,1,0,-1},my[4]={1,0,-1,0};
void init()
{
	memset(map,false,sizeof(map));
	memset(vis,false,sizeof(vis));
	return ;
}
int move(int &x,int &y,int &d,const int n,const int m)
{
	int nx=x+mx[d],ny=y+my[d];
	if(nx<1||nx>n||ny<1||ny>m||(!map[nx][ny]))
	{
		d=(d+1)%4;
		return 0;
	}
	else
	{
		x=nx,y=ny;
		if(!vis[x][y])
		{
			vis[x][y]=true;
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	scanf("%d",&T);	
	while(T--)
	{
		int n,m,k;
		init();
		int input_x,input_y,input_d;
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&input_x,&input_y,&input_d);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				char c;
				cin>>c;
				map[i][j]=(c=='.') ? true : false;
			}
		int ans=1;
		vis[input_x][input_y]=true;
		for (int i=0;i<k;i++)
			ans+= move(input_x,input_y,input_d,n,m);
		printf("%d\n",ans);
	}
	return 0;
}
