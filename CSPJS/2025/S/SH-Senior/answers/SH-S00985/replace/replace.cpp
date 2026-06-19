#include<bits/stdc++.h>
using namespace std;
int n,q,l[200010],r[200010],le,ri,flag,ans;
string a[200010],b[200010],num[200010],sum[200010],x,y,c,d;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(q--)
	{
		cin>>x>>y;
		if(x.length()!=y.length())
		{
			cout<<0<<'\n';
			continue;
		}
		ans=0;
		for(int k=1;k<=n;k++)
		{
			if(x.length()>=a[k].length())
			{
				for(int i=0;i<=x.length()-a[k].length();i++)
				{
					flag=1;
					for(int j=0;j<a[k].length();j++)
					{
						if(a[k][j]!=x[i+j]||b[k][j]!=y[i+j])
						{
							flag=0;
							break;
						}
					}
					if(!flag) continue;
					for(int j=0;j<i;j++)
					{
						if(x[j]!=y[j])
						{
							flag=0;
							break;
						}
					}
					if(!flag) continue;
					for(int j=a[k].length()+i;j<x.length();j++)
					{
						if(x[j]!=y[j])
						{
							flag=0;
							break;
						}
					}
					if(flag)
					{
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
}
