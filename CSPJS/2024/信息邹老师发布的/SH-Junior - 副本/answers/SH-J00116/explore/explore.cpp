#include<bits/stdc++.h>
using namespace std;
char a[10001][10001];
bool er[10001][10001];
int num,n,m,k;//其中 n,m 表示地图的行数和列数，k 表示机器人执行操作的次数
int x,y,d,sum;//位置为 (x,y),朝向为d  
void tu(int xx,int yy,int dd,int kk)
{
	if(er[xx][yy]!=1) 
	{
		er[xx][yy]=1;
		sum++;
	}
	if(k==0) cout<<sum;	
	if(dd==0&&yy+1<n&&yy+1!='x') tu(xx,yy+1,dd,kk-1);
	else if(dd==1&&xx+1<m&&xx+1!='x') tu(xx+1,yy,dd,kk-1);
	else if(dd==2&&yy-1>0&&yy-1!='x') tu(xx,yy-1,dd,kk-1);
	else if(dd==3&&xx-1>0&&xx-1!='x') tu(xx-1,yy,dd,kk-1);
	else tu(xx,yy,(dd+1)%4,kk);
}
int main()
{
	int num; 
	cin>>num;
	for (int i=0;i<=num;i++)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=0;j<n;j++)
		{
			for(int k=0;i<m;k++) cin>>a[j][k];
		} 
		tu(x,y,d,k);
	}
	return 0;
}
