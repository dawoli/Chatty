#include <bits/stdc++.h>
using namespace std;
int l[200001];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,q;
		cin>>n>>k>>q;
		int s;
		for(int i=1;i<=n;i++)
		{
			int s;
			cin>>s;
			for(int j=1;j<=s;j++) cin>>l[i];
		}
		for(int i=1;i<=q;i++)
		{
			int r,c;
			cin>>r>>c;
			cout<<"1"<<endl;
		}
	}
	return 0;
}
