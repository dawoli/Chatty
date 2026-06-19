#include<iostream>
using namespace std;
int listx[4]={0,1,0,-1};
int listy[4]={1,0,-1,0};
bool check[1010][1010];
bool road[1010][1010];
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	int x,y,d;
	cin>>x>>y>>d;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char t;
			cin>>t;
			road[i][j]=0;
			if(t=='.')	check[i][j]=1;
			else check[i][j]=0;
		}
	}
	for(int i=1;i<=m+1;i++)
	{
		check[n+1][i]=0;
		check[0][i]=0;
	}
	for(int i=1;i<=n+1;i++)
	{
		check[i][m+1]=0;
		check[i][0]=0;
	}
	road[x][y]=1;
	for(int i=1;i<=k;i++)
	{
		
		int xt=x+listx[d],yt=y+listy[d];
		if(!check[xt][yt])
		{
			d=d+1;
			d%=4;
		}
		else
		{
			road[xt][yt]=1;
			x=xt,y=yt;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(road[i][j])	ans++;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
 } 
