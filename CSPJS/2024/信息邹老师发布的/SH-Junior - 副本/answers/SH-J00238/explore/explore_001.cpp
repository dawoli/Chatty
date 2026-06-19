#include<bits/stdc++.h>
using namespace std;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int T,n,m,k,x,y,d,ans;
int i,j,p,q,x_,y_;
string s;
char jug[1001][1001];
bool vis[1001][1001];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(i=1;i<=T;i++)
	{
		ans=0;
		memset(vis,false,sizeof(vis));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(p=1;p<=n;p++)
		{
			cin>>s;
			for(q=1;q<=m;q++)
				jug[p][q]=s[q-1];
		}
		vis[x][y]=true;
		ans++;
		for(j=1;j<=k;j++)
		{
			x_=x+dx[d];
			y_=y+dy[d];
			if(x_>=1&&x_<=n&&y_>=1&&y_<=m)
			{
				if(jug[x_][y_]=='.')
				{
					x=x_;
					y=y_;
					if(!vis[x][y])
					{
				 		ans++;
					 	vis[x][y]=true;
					}
				}
				else d=(d+1)%4;
			}
			else d=(d+1)%4;
		}
		cout<<ans<<endl;
	}
	return 0;
}
