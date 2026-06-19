#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("color.in","r",stdin);
	freopen ("color.out","w",stdout);
	int t;
	cin >>t;
	for (int i=0;i<t;++i)
	{
		int n,ans=0;cin >>n;int a[n];
		for (int j=1;j<n;++j)
		{
			cin >>a[j];
			if (j%2==0) ans+=a[j];
		}
		cout <<ans<<endl;
	}
	return 0;
}
