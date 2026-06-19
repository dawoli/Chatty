#include<iostream>
#include<cstring>
using namespace std;
int t,n,m,k,x,y,f,ans;
int zx[4]={0,1,0,-1};
int zy[4]={1,0,-1,0};
bool a[1001][1001],flag[1001][1001];
bool in(int x,int y)
{
	return(1<=x&&x<=n&&1<=y&&y<=m);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>f;
		ans=1;
		memset(flag,0,sizeof(flag));
		flag[x][y]=true;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char tmp;
				cin>>tmp;
				a[i][j]=(tmp=='.');
			}
		}
		while(k--)
		{
			if(k<0)break;
			int dx=x+zx[f],dy=y+zy[f];
			if(in(dx,dy)&&a[dx][dy])
			{
				x=dx;
				y=dy;
				if(!flag[x][y])
				{
					flag[x][y]=true;
					ans++;
				}
			}
			else
			{
				f=(f+1)%4;
			}
		//	cout<<x<<" "<<y<<" "<<f<<endl;
		}
		cout<<ans<<endl;
	}
}
