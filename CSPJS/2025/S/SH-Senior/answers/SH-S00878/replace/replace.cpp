#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5,MOD=0;
int n,q,ans;
string s[MAXN+5][2],t[MAXN+5][2];
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
int main()
{
	init();
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	for (int i=1;i<=q;i++)
	{
		ans=0;
		cin>>t[i][0]>>t[i][1];
		int tl=1e9,tr=0;
		for (int j=0;j<t[i][0].length();j++)
		{
			if (t[i][0][j]!=t[i][1][j])
			{
				tl=min(tl,j);
				tr=max(tr,j);
			}
		}
		for (int j=1;j<=n;j++)
		{
			for (int t2=0;t2<t[i][0].length()-s[j][0].length()+1;t2++)
			{
				if (t2<=tl&&t2+s[j][0].length()-1>=tr)
				{
					bool flag=1;
					for (int k=t2;k<t2+s[j][0].length();k++)
					{
						if (t[i][0][k]!=s[j][0][k-t2]||t[i][1][k]!=s[j][1][k-t2])
						{
							flag=0;
							break;
						}
					}
					if (flag)
					{
						ans+=flag;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
