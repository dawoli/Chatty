#include <bits/stdc++.h>
using namespace std;
#define N 1005
struct Pos
{
	int x,y;
};
int mp[N][N];
bool isVisit[N][N];
Pos nextPos(int x,int y,int d)
{
	Pos pre;
	pre.x=x;
	pre.y=y;
	if(d==0)
		pre.y++;
	else if(d==1)
		pre.x++;
	else if(d==2)
		pre.y--;
	else if(d==3)
		pre.x--;
	return pre;
}
int t,n,m,k,x,y,d,ans;
char jd;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin>>t;
	Pos np;
	while(t--)
	{
		memset(mp,sizeof(mp),0);
		memset(isVisit,sizeof(isVisit),false);
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin>>jd;
				if(jd=='x')
					mp[i][j]=1;
				else
					mp[i][j]=0;
			}
		isVisit[x][y]=true;
		while(k--)
		{
			np=nextPos(x,y,d);
			if(np.x>0&&np.y>0&&np.x<=n&&np.y<=m&&mp[np.x][np.y]==0)
			{
				x=np.x;
				y=np.y;
				isVisit[x][y]=true;
			}
			else
				d=(d+1)%4;
		}
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(isVisit[i][j])
					ans++;
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
