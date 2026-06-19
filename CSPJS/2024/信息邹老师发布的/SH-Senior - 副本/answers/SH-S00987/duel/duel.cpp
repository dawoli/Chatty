#include<bits/stdc++.h>
using namespace std;
#define int long long

int cnt[100005];

signed main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	int n;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}
	
	int ans=0;
	for (int i=1;i<=100000;i++)
	{
		ans=max(0ll,ans-cnt[i]);
		ans+=cnt[i];
	}
	cout << ans << endl;
	
	return 0;
}
