#include<iostream>
#include<cstdio>
using namespace std;
int t,d1[4]={0,1,0,-1},d2[4]={1,0,-1,0};
char field[1003][1003];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n,m,k,x,y,d,ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) cin>>field[i][j];
		for(int i=1;i<=k;i++)
		{
			int a=x+d1[d],b=y+d2[d];
			if(a>n||a<1||b>m||b<1||field[a][b]=='x')
			{
				d=(d+1)%4;
				continue;
			}
			else x=a,y=b,ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
