#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int j=2;
	for(int i=1;i<=n;i++)
	{
		while(a[j]<=a[i]&&j<=n)j++;
		if(j<=n)
		{
			ans--;
		}
		j++;
	}
	cout<<ans;
	return 0;
}
