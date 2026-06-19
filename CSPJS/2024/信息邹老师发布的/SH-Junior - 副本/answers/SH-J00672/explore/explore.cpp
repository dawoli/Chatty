#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x0,y0,d0; 
char jung[1003][1003];
bool vis[1003][1003];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct pos
{
	int x;
	int y;
	int d;
};
pos robot;
void turn_right()
{
//	cout<<"9"<<endl;
	robot.d=(robot.d+1)%4;
//	cout<<robot.d<<"tr"<<endl; 
}
void forward()
{
//	cout<<"8"<<endl;
	int dir=robot.d;
	robot.x+=dx[dir];
	robot.y+=dy[dir];
	vis[robot.x][robot.y]=true;
}
void next_pos()
{
	int dir=robot.d;
	int tx=robot.x,ty=robot.y;
	ty=ty+dy[dir];
	tx=tx+dx[dir];
//	cout<<"correct"<<robot.x+dx[dir]<<endl;
//	cout<<"correct"<<robot.y+dy[dir]<<endl;
//	cout<<robot.x<<"+"<<dx[dir]<<"="<<tx<<endl;
//	cout<<robot.y<<"+"<<dy[dir]<<"="<<ty<<endl;
	if(jung[tx][ty]=='x' || tx>n || ty>m || tx<1 || ty<1)
	{
//		cout<<"99"<<endl;
		turn_right();
	}
	else
	{
//		cout<<"88"<<endl;
		forward();
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int a=0;a<t;a++)
	{
		int ans=0;
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		robot.d=d0;
		robot.x=x0;
		robot.y=y0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				vis[i][j]=false;
				cin>>jung[i][j];
			}
		}
		vis[x0][y0]=true;
		for(int i=0;i<k;i++)
		{
			next_pos();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j])
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}
