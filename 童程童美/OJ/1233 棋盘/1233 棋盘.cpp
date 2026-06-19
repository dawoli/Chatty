#include<bits/stdc++.h>
using namespace std;
int m,n;
int mp[1001][1001],b[1001][1001];
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
struct node
{
	int x,y,c,mf,w;
};
queue<node> q;
void bfs()
{
node a={1,1,mp[1][1],1,0};q.push(a);b[1][1]=0;
while (q.empty()!=1){
node f=q.front();
for (int i=0;i<4;i++){
		int nx=f.x+dx[i],ny=f.y+dy[i],nw1=f.w+abs(f.c-mp[nx][ny]),nw2=f.w+2;
if (nx>0&&nx<=m&&ny>0&&ny<=m&&mp[nx][ny]!=-1&&nw1<b[nx][ny])
	{b[nx][ny]=nw1;a={nx,ny,mp[nx][ny],1,nw1};q.push(a);}
if (nx>0&&nx<=m&&ny>0&&ny<=m&&mp[nx][ny]==-1&&nw2<b[nx][ny]&&f.mf==1)
{b[nx][ny]=nw2;a={nx,ny,f.c,0,nw2};q.push(a);
}
}q.pop();
}
}

int main()
{
    cin>>m>>n;
    if(m==1){
		cout<<0;
		return 0;
    }
    memset(mp,-1,sizeof(mp));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			b[i][j]=10000;
		}
	}
    b[1][1]=0;
	for(int i=1;i<=n;i++)
	{
		int nowx,nowy,nowc;
		cin>>nowx>>nowy>>nowc;
		mp[nowx][nowy]=nowc;
	}
	int s=b[m][m];
	bfs();
	if(b[m][m]==s)b[m][m]=-1;
	cout<<b[m][m];
	return 0;
}