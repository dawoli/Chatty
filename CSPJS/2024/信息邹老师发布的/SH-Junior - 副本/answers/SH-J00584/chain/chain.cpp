#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,r[100005],c[100005],s[100005][200005],l[100005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for (int p=1;p<=t;p++)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for (int j=1;j<=l[i];j++)
			{
				cin>>s[i][j];
			}
		}
		for (int i=1;i<=q;i++)
		{
			cin>>r[i]>>c[i];
			int flag=0;
			for (int j=1;j<=n;j++)
			{
				for (int o=1;o<=l[j];o++)
				{
					if (s[i][o]==c[i])
						flag=1;
				}
			}
			if (flag==0)
			{
				cout<<0<<endl;
			}
			else
			{
				cout<<1<<endl;
			}
		}
		
	}
	return 0;
}
