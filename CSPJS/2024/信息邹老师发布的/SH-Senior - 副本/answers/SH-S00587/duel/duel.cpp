#include <bits/stdc++.h>
using namespace std;

//#define DEBUG

#ifdef DEBUG
#define debug(...) \
{\
	fprintf(stderr, "L%d, func:'%s', debug:", __LINE__, __func__); \
	fprintf(stderr, __VA_ARGS__); \
}
#else
#define debug(...) {}
#endif

const int MAX = 100000 + 10;

int n;
int r[MAX];

map<int, int> mp;

int pre[MAX];
int cnt[MAX];
int maxn;

//void pcnt()
//{
//	for (int i = 1; i <= maxn; i++)
//	{
//		debug("%d %d\n", i, cnt[i]);
//	}
//	cerr << endl;
//}

void dfs(int now)
{
//	int id = now;
	int fa = 0;
	for (int i = now; i > 0; i = pre[i])
	{
		cnt[i]--;
		if (cnt[i] == 0)
		{
			pre[fa] = pre[i];
			i = fa;
		}
		fa = i;
	}
//	pcnt();
}

typedef map<int, int>::iterator Itt;

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);

//	freopen("dbg.dbg", "w", stderr);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> r[i];
		cnt[r[i]]++;
		maxn = max(maxn, r[i]);
		mp[r[i]]++;
	}
	auto last = mp.rbegin();
	auto it = last;
	it--;
	for (; it != mp.rend(); last = it++)
	{
//		int t = last->first;
		pre[last->first] = (it)->first;
//		debug("%d %d\n", t, pre[t]);
	}
	
	int ans = 0;
	pre[0] = maxn;
	for (int i = pre[0]; i > 0; i = pre[0])
	{
		dfs(i);
		ans++;
	}
	cout << ans << endl;
	
	return 0;
}

