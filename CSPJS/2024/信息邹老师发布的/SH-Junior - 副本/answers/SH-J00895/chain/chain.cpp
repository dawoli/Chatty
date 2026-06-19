#include<bits/stdc++.h>
using namespace std;
int l[1050],s[1050][2050];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k,q;
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&l[i]);
			for(int j=1;j<=l[i];j++)
			{
				scanf("%d",&s[i][j]);
			}
		}
		for(int i=1;i<=q;i++)
		{
			int r,c;
			bool f=0;
			scanf("%d%d",&r,&c);
			for(int j=1;j<=n;j++)
			{
				int ind;
				for(int h=1;h<=l[j];h++)
				{
					if(s[j][h]==1) ind=h;
				}
				for(int h=ind;h<ind+k;h++)
				{
					if(s[j][h]==c) f=1;
				}
			}
			cout<<f<<endl;
		}
	}
	return 0;
}