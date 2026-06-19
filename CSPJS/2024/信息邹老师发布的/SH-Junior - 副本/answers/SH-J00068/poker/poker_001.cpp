#include<bits/stdc++.h>
using namespace std;
int d[14],c[14],h[14],s[14];
int pk(char zl)
{
	if(zl=='A')
	{
		return 1;
	}
	else if(zl=='T')
	{
		return 10;
	}
	else if(zl=='J')
	{
		return 11;
	}
	else if(zl=='Q')
	{
		return 12;
	}
	else if(zl=='K')
	{
		return 13;
	}
	else
	{
		return zl-'0';
	}
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","W",stdout);
	int n;
	cin>>n;
	char hs;
	char zl;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cin>>hs>>zl;
		int x=pk(zl);
		if(hs=='D')
		{
			if(d[x]==0)
			{
				cnt++;
			}
			d[x]=1;
		}
		else if(hs=='C')
		{
			if(c[x]==0)
			{
				cnt++;
			}
			c[x]=1;
		}
		else if(hs=='H')
		{
			if(h[x]==0)
			{
				cnt++;
			}
			h[x]=1;
		}
		else
		{
			if(s[x]==0)
			{
				cnt++;
			}
			s[x]=1;
		}
	}
	cout<<52-cnt;
	return 0;
}
