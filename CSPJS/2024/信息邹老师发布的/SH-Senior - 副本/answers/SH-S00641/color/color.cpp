#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define mp(a, b) make_pair(a, b)
#define x first
#define y second
using namespace std;
const int N = 2e5 + 5;
int n;
ll ans = 0;
pair<int, int> a[N];
set<pair<int, int>> red, blue;
inline bool cmp(pair<int, int> t1, pair<int, int> t2)
{
	return (t1.y ^ t2.y ? t1.y < t2.y : t1.x < t2.x);
}
bool jr(int l, int r)
{
	for (auto i : red)
	{
		if ((i.x <= l && i.y >= l) || (i.x <= r && i.y >= r)) return 0;
	}
	return 1;
}
bool jb(int l, int r)
{
	for (auto i : blue)
	{
		if ((i.x <= l && i.y >= l) || (i.x <= r && i.y >= r)) return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		ans = 0;
		int lr = -1, lb = -1;
		red = blue = set<pair<int, int>>();
		cin >> n;
		for (int i = 1; i <= n; i++) 
		{
			int temp;
			cin >> temp;
			a[i] = mp(i, temp);
		}
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= n; i++)
		{
			if (a[i].y == a[i + 1].y)
			{
				if (red.empty() || jr(a[i].x, a[i + 1].x))
				{
					ans += (a[i].y == lr ? 2 : 1) * a[i].y;
					lr = a[i].y;
					red.insert(mp(a[i].x, a[i + 1].x));
				}
				else if(blue.empty() || jb(a[i].x, a[i + 1].x))
				{
					ans += (a[i].y == lb ? 2 : 1) * a[i].y;
					lb = a[i].y;
					blue.insert(mp(a[i].x, a[i + 1].x));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
