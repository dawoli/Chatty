#include<bits/stdc++.h>
using namespace std;
struct cg
{
	string a,b;
	int sn;
}s[200005];
bool cmp(cg x,cg y)
{
	return x.sn<y.sn;
}
int dp[200005][2];//[1]»»¹ý,[0]Ã»»»¹ý 
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b;
		s[i].sn=s[i].a.length();
	}
	sort(s+1,s+n+1,cmp);
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		int xn=x.length();
		dp[0][0]=1;dp[0][1]=0;
		if(x.length()!=y.length())
		{
			cout<<0<<endl;
			continue;
		}
		for(int k=1;k<=xn;k++)
		{
			dp[k][0]=dp[k][1]=0;
			if(x[k-1]==y[k-1])
				dp[k][1]=dp[k-1][1],dp[k][0]=dp[k-1][0];
			for(int i=1;i<=n;i++)
			{
				if(k<s[i].sn)
					break;
				bool tmp=true;
				for(int j=0;j<s[i].sn;j++)
				{
					if(x[k-1-j]!=s[i].a[s[i].sn-j-1]||y[k-1-j]!=s[i].b[s[i].sn-j-1])
					{
						tmp=false;
						break;
					}
				}
				if(tmp)
				{
					dp[k][1]+=dp[k-s[i].sn][0];
				}
			}		
		}	
		cout<<dp[xn][0]+dp[xn][1]<<endl;
	}
	return 0;
}
