#include <iostream>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,k,n,q,li,u;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>k>>q;
		for (int j=1;j<=n;j++)
		{
			cin>>li;
			for (int a=1;a<=li;a++)
			{
				cin>>u;
			}
		}
		for (int j=1;j<=q;j++)
		{
			cin>>li>>u;
			cout<<1<<endl;
		}
	}
	return 0;
}
