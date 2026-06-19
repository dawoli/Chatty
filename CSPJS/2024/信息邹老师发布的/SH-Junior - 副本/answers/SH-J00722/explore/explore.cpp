#include<bits/stdc++.h>
using namespace std;

const int N=1e3+9;
char a[N][N];
bool f[N][N];
int T,n,m,k,x,y,d;
int dx[4]={0,1,0,-1} , dy[4]={1,0,-1,0};

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin >> a[i][j];
				f[i][j]=0;
			}

		f[x][y]=1;
		while(k--)
		{
			int xx = x+dx[d] , yy = y+dy[d];
			
			if(a[xx][yy]=='.')
			{
				f[xx][yy]=1;
				x=xx, y=yy;
			}
			else d=(d+1)%4;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(f[i][j]==1) ans++;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
