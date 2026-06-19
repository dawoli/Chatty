#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T,n,m,k,x0,y0,d0;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		for(int j=1;j<=n;j++)
		{
			for(int h=1;h<=m;h++)
			{
				cin>>a[j][h];
			}
		}
		if(k==1)
		{
			if(d0==0)
			{
				if(a[x0][y0+1]=='.')
				{
					cout<<"2";
				}
				else
				{
					cout<<"1";
				}
			}
			if(d0==1)
			{
				if(a[x0+1][y0]=='.')
				{
					cout<<"2";
				}
				else
				{
					cout<<"1";
				}
			}
			if(d0==2)
			{
				if(a[x0][y0-1]=='.')
				{
					cout<<"2";
				}
				else
				{
					cout<<"1";
				}
			}
			if(d0==3)
			{
				if(a[x0-1][y0]=='.')
				{
					cout<<"2";
				}
				else
				{
					cout<<"1";
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
