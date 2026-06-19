#include<bits/stdc++.h>
using namespace std;
int n,a,b,ans;
bool vis[5][20];
string s;
int main()
{
	cin.tie(0);
	cout.tie(0);
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		if (s[0]=='D')
		{
			a=1;
		}
		else if (s[0]=='C')
		{
			a=2;
		}
		else if (s[0]=='H')
		{
			a=3;
		}
		else if (s[0]=='S')
		{
			a=4;
		}
		if (s[1]=='A')
		{
			b=1;
		}
		else if (s[1]=='T')
		{
			b=10;
		}
		else if (s[1]=='J')
		{
			b=11;
		}
		else if (s[1]=='Q')
		{
			b=12;
		}
		else if (s[1]=='K')
		{
			b=13;
		}
		else
		{
			b=s[1]-'0';
		}
		vis[a][b]=1;
	}
	for (int i=1;i<=4;i++)
	{
		for (int j=1;j<=13;j++)
		{
			if (vis[i][j]==0)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
