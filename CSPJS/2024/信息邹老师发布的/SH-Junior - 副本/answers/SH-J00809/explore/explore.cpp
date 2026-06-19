#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3;
int T,n,m,k,x,y,d,ans;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool vis[MAXN+5][MAXN+5];
string s[MAXN+5];
bool check(int x,int y)
{
	if (x<1||x>n||y<1||y>m||s[x][y]=='x')
	{
		return 0;
	}
	return 1;
}
int main()
{
//	std::syns_with_stdin(false);
	cin.tie(0);
	cout.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
//	cin>>T;
	scanf("%d",&T);
	while (T--)
	{
//		cin>>n>>m>>k;
		scanf("%d%d%d",&n,&m,&k);
//		cin>>x>>y>>d;
		scanf("%d%d%d",&x,&y,&d);
		for (int i=1;i<=n;i++)
		{
			cin>>s[i];
			s[i]=" "+s[i];
		}
		memset(vis,0,sizeof(vis));
		ans=1;
		vis[x][y]=1;
		for (int i=1;i<=k;i++)
		{
			if (check(x+dx[d],y+dy[d])==1)
			{
				x+=dx[d];
				y+=dy[d];
				if (vis[x][y]==0)
				{
					ans++;
					vis[x][y]=1;
				}
			}
			else
			{
				d=(d+1)%4;
			}
		}
//		cout<<ans<<endl;
		printf("%d\n",ans);
	}
	return 0;
}
