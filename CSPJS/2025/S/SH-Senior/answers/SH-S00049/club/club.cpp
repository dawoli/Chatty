#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


struct News
{
	int a[5], maxt, maxp, mint, minp, midt, midp, dis1;
	void read()
	{
		cin >> a[1] >> a[2] >> a[3];
		maxt = max(a[1], max(a[2], a[3]));
		if (maxt == a[1])
			maxp = 1;
		if (maxt == a[2])
			maxp = 2;
		if (maxt == a[3])
			maxp = 3;
		
		mint = min(a[1], min(a[2], a[3]));
		if (mint == a[1])
			minp = 1;
		if (mint == a[2])
			minp = 2;
		if (mint == a[3])
			minp = 3;
			
		midt = a[1] + a[2] + a[3] - maxt - mint;
		midp = 6 - maxp - minp;
		dis1 = maxt - midt;
	}	
};
News a[100005];

bool cmp(News x, News y)
{
	return x.dis1 < y.dis1;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	while (t--)
	{
		int n, cnt[5] = {0, 0, 0, 0};
		long long sum = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			a[i].read();
			cnt[a[i].maxp]++;
			sum += a[i].maxt;
		}
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; ++i)
		{
			if (cnt[a[i].maxp] > n / 2)
			{
				sum -= a[i].dis1;
				cnt[a[i].maxp]--;
				cnt[a[i].midp]++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
