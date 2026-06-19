#include <bits/stdc++.h>
using namespace std;
int n, r[100005], cnt[100005];
int main ()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	memset(cnt,0,sizeof(cnt));
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &r[i]);
		cnt[r[i]]++;
	}
	int ans = 0;
	for (int i = 1; i <= 100000; i++)
	{
		if (cnt[i]>ans)
		{
			ans=cnt[i];
		}
	}
	cout << ans;
	return 0;
}
