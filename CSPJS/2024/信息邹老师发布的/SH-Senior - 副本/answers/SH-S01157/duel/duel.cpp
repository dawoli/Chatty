#include<bits/stdc++.h>
using namespace std;
int n, cnt[100005], i, batk = 1e9, maxa, ans, t, l, st;
bool flag=true;
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int r;
		cin >> r;
		cnt[r]++;
		batk = min(r, batk);
		maxa = max(maxa, r);
	}
	st = batk +1;
	for(int i = st; i <= maxa; i++)
	{
		if(cnt[i] != 0)
		{
			for(int j = batk; j < i; j++)
			{
				t += cnt[j];
			}
			batk = i;
			if(t > cnt[i])
			{
				t -= cnt[i];
			}
			else
				t = 0;
		}
	}
	cout << t + cnt[maxa];
	return 0;
}
