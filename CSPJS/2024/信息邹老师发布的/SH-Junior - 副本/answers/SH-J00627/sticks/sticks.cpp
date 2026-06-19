#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		for(int i=1;i<=x/7;i++)
		{
			cout<<8;
		}
		cout<<endl;
	}
	return 0;
}
