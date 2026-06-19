#include<bits/stdc++.h>
using namespace std;
int a[10000];
struct People
{
	int s[20000];
};People p[10000];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,q,cnt=0;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			int l;
			cin>>l;
			for(int j=1;j<=l;j++)
			{
				cin>>p[i].s[j];
				a[cnt++]=p[i].s[j];
			}
		}
		while(q--)
		{
			int r,c;
			cin>>r>>c;
			bool flag=0;
			for(int i=0;i<cnt;i++)
			{
				if(a[i]==c) flag=1;
			}
			if(!flag||r==1) cout<<'0'<<endl;
			else cout<<'1'<<endl;
		}
	}
	return 0;
}
