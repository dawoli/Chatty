#include <bits/stdc++.h>
using namespace std;
int n,a[100005],x,ans;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	x=1;
	for(int i=2;i<=n;i++)
	{
		if(a[x]<a[i])
		{
			ans++;
			x++;
		}
	}
	cout <<n-ans;
	return 0;
}
