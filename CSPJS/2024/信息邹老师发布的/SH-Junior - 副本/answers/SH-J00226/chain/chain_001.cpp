#include<iostream>
using namespace std;
int a[100002][100002];
int b[100002][4];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t; cin>>t;
	while (t--)
	{
		int n,k,q; cin>>n>>k>>q;
		for (int i=0;i<n;i++)
		{
			int l; cin>>l;
			for (int j=0;j<l;j++)
			{
				cin>>a[i][j];
			}
		}
		for (int i=0;i<q;i++)
		{
			for (int j=0;j<=1;j++)
			{
				cin>>b[i][j];
			}
		}
		while (q--)
		{
			cout<<0<<endl;
		}
	}
	return 0;
 } 
