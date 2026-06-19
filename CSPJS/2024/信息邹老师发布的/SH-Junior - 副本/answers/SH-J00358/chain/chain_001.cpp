#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;
int s[N];
int main()
{
	freopen("chain2.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n, k, q, l;
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++)
		{
			int l;
			cin>>l;
			for(int m=1;m<l;m++)
			{
				cin>>s[m];
			}
		}
		for(int j=1;j<=q;j++)
		{
			int r, c;
			cin>>r>>c;
			for(int m=1;m<=l;m++)
			{
				if(s[i]==c)	
				{
					cout<<1<<endl;
					break;
				}
			}
			cout<<0<<endl;
		}
	}
	return 0;
}

