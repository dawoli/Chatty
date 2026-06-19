#include<iostream>
#include<string>
using namespace std;
string map1[1005];
int visit[1001][1001];
int dir_x[4]={0,1,0,-1};
int dir_y[4]={1,0,-1,0};
int sum=0,t;
int n,m,k;
int sx,sy,sdir;
int dfs(int now_x,int now_y,int d,int now_s)
{
	if(now_s==k)
		return sum;
	int xx=now_x+dir_x[d];
	int yy=now_y+dir_y[d];
	if((xx>=1 && xx<=n && yy>=1 && yy<=m)&&(map1[xx][yy]!='x'))
	{
		if(visit[xx][yy]==0)
			sum++;
		visit[xx][yy]=1;	
		dfs(xx,yy,d,now_s+1);
	}
	else
	{
		d=(d+1)%4;
		dfs(now_x,now_y,d,now_s+1);
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int s=1;s<=t;s++)
	{
		cin>>n>>m>>k;
		cin>>sx>>sy>>sdir;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>map1[i][j];			
		cout<<dfs(sx,sy,sdir,0)+1<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;		
}
