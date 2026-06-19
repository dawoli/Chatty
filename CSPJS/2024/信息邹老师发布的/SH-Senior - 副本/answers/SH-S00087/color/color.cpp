#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long sum = 0;
		for(int i = 1 ; i<=n ; i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
