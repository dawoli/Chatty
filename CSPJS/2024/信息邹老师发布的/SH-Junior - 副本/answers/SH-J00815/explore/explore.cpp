#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int a;
	cin>>a;
	while(a)
	{
		char s[1010][1010];
		int w[10][2]={{0,1},{1,0},{0,-1},{-1,0}};
		int m,n,cnt,x,y,d,ans=0;
		cin>>m>>n>>cnt>>x>>y>>d;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				cin>>s[i][j];
		s[x][y]='*';
		for(int i=1;i<=cnt;i++)
		{
			if(s[x+w[d][0]][y+w[d][1]]!='x'&&x+w[d][0]>=1&&y+w[d][1]>=1&&x+w[d][0]<=m&&y+w[d][1]<=n)
				x+=w[d][0],y+=w[d][1],s[x][y]='*';
			else
				d=(d+1)%4;
		}
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				if(s[i][j]=='*')
					ans++;
		cout<<ans<<endl;
		a--;
	}
	
	return 0;
}
