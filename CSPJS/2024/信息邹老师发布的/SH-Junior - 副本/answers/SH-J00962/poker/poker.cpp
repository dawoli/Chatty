#include<bits/stdc++.h>
using namespace std;
int d[14];
int c[14];
int h[14];
int ss[14];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,y,ans=0;
	char s;
	char x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>x;
		if('0'<=x&&'9'>=x) y=x-'0';
		else
		{
			if(x=='A') y=1;
			else if(x=='T') y=10;
			else if(x=='J') y=11;
			else if(x=='Q') y=12;
			else y=13;
		}
		if(s=='D')
		{
			d[y]++;
		}
		if(s=='C')
		{
			c[y]++;
		}
		if(s=='H')
		{
			h[y]++;
		}
		if(s=='S')
		{
			ss[y]++;
		}
	}
	for(int i=1;i<=13;i++)
	{
		if(d[i]==0) ans++;
	}
	for(int i=1;i<=13;i++)
	{
		if(c[i]==0) ans++;
	}
	for(int i=1;i<=13;i++)
	{
		if(h[i]==0) ans++;
	}
	for(int i=1;i<=13;i++)
	{
		if(ss[i]==0) ans++;
	}
	cout<<ans;
	return 0;
}
