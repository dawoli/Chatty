#include<bits/stdc++.h>
using namespace std;
int t;
int flag=0;
int n,p,q;
int a[1001][2001];
int r[2001];
int c[2001];
int l[1001];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>p>>q;
		for(int j=1;j<=n;j++)
		{
			cin>>l[j];
			for(int k=1;k<=l[j];k++)
			{
				cin>>a[j][k];
			}
		}
		for(int j=1;j<=q;j++)
		{
			cin>>r[j]>>c[j];
			for(int k=1;k<=n;k++)
			{
				for(int h=1;h<=l[j];j++)
				{
					if(a[k][h]!=1)
						break;
					else
					{
						for(int g=h+1;g<=l[j];g++)
						{
							if(l[j]-g+1>p)
							{
								break;
							}
							else
							{
								if(a[k][g]==c[j])
								{
									cout<<"1"<<endl;
									flag=1;
									break;
								}
							}
						}
					}
					if(flag=1)
					{
						break;
					}
				}
				if(flag=1)
				{
					flag=0;
					break;
				}
			}
		}
	}
	return 0;
}
