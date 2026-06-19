#include <bits/stdc++.h>
using namespace std;
long long t,n,k,q,l,v,c,r,ans;
vector<int>a[200005];
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		bool flag=0,k=0;
		ans=0;
		for(auto u:a[i])
		{
			if(flag)
			{
				ans++;
			} 
			if(u==1)
			{
				flag=1;
				ans++;
			}
			if(u==c && flag==1 && ans+1<=k)
			{
				cout <<1 <<endl;
			}
		}
	}
	cout <<0 <<endl;
	return;
}
int mian()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >>t;
	while(t--)
	{
		cin >>n >>k >>q;
		for(int i=1;i<=n;i++)
		{
			cin >>l;
			for(int j=1;j<=l;j++)
			{
				cin >>v;
				a[j].push_back(v);
			}
			
		}
		for(int i=1;i<=q;i++)
		{
			cin >>r >>c;
			if(r==1)
			{
				solve1();
			}
		}
	}
	return 0;
}
