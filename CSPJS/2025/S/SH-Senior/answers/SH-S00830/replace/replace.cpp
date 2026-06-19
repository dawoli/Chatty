#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn=200010;
int q,n,ans,ma;
map<int,int> qz[5000010];
string s[Maxn][3],t[Maxn][3];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
		int c1=0;
		for(int j=0;j<s[i][1].size();j++)
		{
			if(s[i][1][j]=='b')
			{
				c1=j;
			}
		}
		int c2=0;
		for(int j=0;j<s[i][2].size();j++)
		{
			if(s[i][2][j]=='b')
			{
				c2=j;
			}
		}
		qz[c1][c1-c2]++;
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>t[i][1]>>t[i][2];
		if(t[i][1].size()!=t[i][2].size())
		{
			cout<<"0\n";
			continue;
		}
		int c1=0;
		for(int j=0;j<t[i][1].size();j++)
		{
			if(t[i][1][j]=='b')
			{
				c1=j;
			}
		}
		int c2=0;
		for(int j=0;j<t[i][2].size();j++)
		{
			if(t[i][2][j]=='b')
			{
				c2=j;
			}
		}
		for(int i=0;i<=c1;i++)
		{
			ans+=qz[i][c2-c1];
		}
		cout<<ans<<endl;
	}
	return 0;
}
