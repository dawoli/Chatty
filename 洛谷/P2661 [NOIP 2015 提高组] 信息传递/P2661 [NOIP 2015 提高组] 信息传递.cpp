// Problem URL: https://www.luogu.com.cn/P2661
// Finish Time: 2026/4/25 20:54:58 AC
// Finish Time: 2026/4/25 20:40:11 TLE 70pts
// Start Time: 2026/4/25 20:23:44

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,t[200005],p[200005],vis[200005],ans=INT_MAX;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>t[i];
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		for(int j=i,k=0;;k++,j=t[j])
		{
			if(vis[j])
			{
				if(vis[j]==i)
					ans=min(ans,k-p[j]);
				break;
			}
			vis[j]=i;
			p[j]=k;
		}
	}
	cout<<ans;
	return 0;
}
