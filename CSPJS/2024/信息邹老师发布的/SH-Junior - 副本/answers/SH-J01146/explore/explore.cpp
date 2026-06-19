#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		char a[n][m];
		int x,y,d;
		cin>>x>>y>>d;
		for(int w=1;w<=n;w++)
		{
			cin>>a[w];
		}
		for(int s=1;s<=n;s++)
		{
			for(int e=1;e<=m;e++)
			{
				cin>>a[e][s];
			}
		}
		int sum;
		while(k--)
		{
			if (d==0)
			{
				if(a[x][y+1]=='.')
				{
					sum++;
					y++;
					continue;
				}
				else
				{
					d++;
					continue;
				}
			}
			if (d==1)
			{
				if(a[x+1][y]=='.')
				{
					sum++;
					x++;
					continue;
				}
				else
				{
					d++;
					continue;
				}
			}
			if (d==3)
			{
				if(a[x][y-1]=='.')
				{
					sum++;
					y--;
					continue;
				}
				else
				{
					d++;
					continue;
				}
			}
			if (d==3)
			{
				if(a[x-1][y]=='.')
				{
					sum++;
					x--;
					continue;
				}
				else
				{
					d=0;
					continue;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
