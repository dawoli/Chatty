// Problem URL: https://iai.sh.cn/problem/1223
// Finish Time: 2026/5/5 18:06:28 AC
// Finish Time: 2026/5/5 17:55:00 WA 40pts
// Finish Time: 2026/5/5 17:52:03 WA 40pts
// Finish Time: 2026/5/5 17:48:59 WA 30pts
// Finish Time: 2026/5/5 17:36:32 WA 30pts
// Start Time: 2026/5/5 16:56:18

#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,ans=0;
int a[200005],b[200005],sum[200005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>l;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	sort(b+1,b+m+1);
	for(int i=1;i<=m;i++)
		sum[i]=sum[i-1]+b[i];
	for(int i=1;i<=n;i++)
	{
		int p=upper_bound(b+1,b+m+1,l-a[i])-b-1;
		ans+=p*a[i]+sum[p]+l*(m-p);
	}
	cout<<ans;
	return 0;
}