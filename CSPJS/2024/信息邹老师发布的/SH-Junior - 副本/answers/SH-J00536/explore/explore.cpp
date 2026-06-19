#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T,i;
	cin>>T;
	for (i=1;i<=T;i++)
	{
		int n,m,k,x,y,g,h,d,e=0,j,l,f;
		cin>>n>>m>>k>>x>>y>>d;
		char a[1002][1002];
		bool b[1002][1002]={false};
		for (j=1;j<=n;j++)
			for (l=1;l<=m;l++)
				cin>>a[j][l];
		for (f=1;f<=k;f++)
		{
			b[x][y]=true;
			if (d==0) h=y+1,g=x;
			else if (d==1) h=y,g=x+1;
			else if (d==2) h=y-1,g=x;
			else h=y,g=x-1;
			if (g>=1&&g<=n&&h>=1&&h<=m&&a[g][h]!='x')
			{
				x=g;y=h;
			}
			else
				d=(d+1)%4;
			b[x][y]=true;
		}
		for (j=1;j<=n;j++)
		{
			for (l=1;l<=m;l++)
			{
				if (b[j][l]==true)
				{
					++e;
				}
			}
		}
		cout<<e<<endl;
	}
	return 0;
}
