#include <bits/stdc++.h>
using namespace std;
int n,ans,r[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	sort(r+1,r+1+n);
	int j=2;
	for (int i=1;i<=n&&j<=n;)
	{
		if (r[i]<r[j])
		{
			ans++;
			j++;
			i++;
		}
		else
		{
			j++;
		}
	}
	cout<<n-ans;
	return 0;
}
