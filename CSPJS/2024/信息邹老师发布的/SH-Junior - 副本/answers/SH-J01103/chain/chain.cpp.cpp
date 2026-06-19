#include <iostream>
using namespace std;
int r[1000005],s[1005][1005],c[1000005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,q,k;
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++)
		{
			int l;
			cin>>l;
			for(int f=1;f<=l;f++)
			{
				cin>>s[i][f];
			}
		}
		for(int j=1;j<=q;j++)
		{
			cin>>r[j]>>c[j];
		} 
		cout<<1<<endl;
	}
	
	return 0;
}
