#include <bits/stdc++.h>
using namespace std;
int T,n,k,q,last,ct,m;
int s1[10005][20005],s2[10005][20005],l[10005],r[10005],c[10005],ans[10005]={0};
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
			{
				cin>>s1[i][j];
				s2[i][j]=s1[i][j];
			}
		}
		for(int j=1;j<=q;j++)
		{
			cin>>r[j]>>c[j];
			if(c[j]==1) ans[j]=0;
		}
		for(int i=1;i<=q;i++)
		{
			for(int j=1;j<=r[i];j++)
			{
				if(r[i]==1)
				{
					int p;
					for(int k=1;k<=n;k++)
					{
						int b=true;
						sort(s1[k]+1,s1[k]+l[k]+1);
						ct=1;
						for(int u=1;u<=l[k];u++)
						{
							if(s1[k][u]=s1[k][u-1]&&u!=1)
								--ct;
							if(s1[k][u]!=ct&&ct<=c[i])
								b=false;
							++ct;
						}
						if(b)
						{
							m=true;
						}
					}
					if(m)
					cout<<1<<"\n";
					else cout<<0<<"\n";
					for(int k=1;k<=n;k++)
					{
						for(int u=1;u<=l[k];u++)
						{
							s1[k][u]=s2[k][u];
						}
					}
				}
				else
				{
					
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
