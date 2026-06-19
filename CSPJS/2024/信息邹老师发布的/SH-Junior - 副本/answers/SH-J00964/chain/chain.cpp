#include<bits/stdc++.h>
using namespace std;
long long s[20005][10005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			int l;
			cin>>l;
			for(int j=1;j<=l;j++)
			{
				cin>>s[i][j];
			}
		}
		for(int i=1;i<=q;i++)
		{
			int r,c;
			cin>>r>>c;
			if(r*2==c and r%2==0)
			{
				cout<<1;
				continue;
			}
			if(r==c and r%2==1)
			{
				cout<<0;
				continue;
			}
			if(r==c and r%2==0)
			{
				cout<<1;
				continue;
			}
			if(c%r!=2)
			{
				cout<<0;
				continue;
			}
		}
	}
}
