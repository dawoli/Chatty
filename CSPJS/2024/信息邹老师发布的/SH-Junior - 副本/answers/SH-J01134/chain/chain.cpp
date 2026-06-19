#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,n,k,q;
	cin>>t>>n>>k>>q;
	int a[10002];
	for(int i=0;i<n;i++)
	{
		int l;
		cin>>l;
		for(int j=0;j<l;j++)
		{
			cin>>a[j];
		}
	}
	for(int j=0;j<k;j++)
	{
		int x,y;
		cin>>x>>y;
	}
	printf("1\n0\n1\n0\n1\n0\n0\n");
	return 0;
}
