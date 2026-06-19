#include<bits/stdc++.h>
using namespace std;
int n;	string s;
int T;
int ans[14286];
int a[100000];
int k,d,q;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>k>>q;
		for(int i=0;i<n;i++)
		{
			int len,x;
			cin>>len;
			for(int j=0;j<len;j++)
			{
				cin>>x;
				a[x]++;
			}
		}
		for(int i=0;i<q;i++)
		{
			int x,y;
			cin>>x>>y;
			if(a[y]==0) cout<<0<<endl;
			else cout<<1<<endl;
		}
		
	}
	return 0;
}
