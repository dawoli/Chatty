#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
using namespace std;
const int N = 1e5 + 5;
int n, m, l, v;
struct car
{
	int dis, startv, alpha;
};
inline double mv(int sv, int av, int sx)
{
	return sqrt(sv * sv + 2 * av * sx);
}
inline int mis(int sv, int av, int lv)
{
	return ceil(sqrt(lv * lv - sv * sv) / 2 / av);
}
bool cmp(car a, car b)
{
	if (!a.alpha) return 0;
	return (a.alpha ^ b.alpha ? a.alpha < b.alpha : a.dis > b.dis);
}
bool cmpp(pair<int, int> a, pair<int, int> b)
{
	return (a.x ^ b.x ? a.x < b.x : a.y < b.y);
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdin);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> l >> v;
		ll ans1 = 0, ans2 = 0, lc[4000] = {0}, cnt[N] = {0};
		vector<pair<int, int> > ans;
		car c[N];
		for (int i = 1; i <= n; i++) cin >> c[i].dis >> c[i].startv >> c[i].alpha;
		for (int i = 1; i <= m; i++) cin >> lc[i];
		sort(c + 1, c + 1 + n, cmp);
		for (int i = 1; i <= n; i++)
		{
			if (c[i].alpha < 0)
			{
				if (c[i].startv > v)
				{
					ll sx = c[i].dis + mis(v, -c[i].alpha, c[i].startv), l = 1, r = m, mid, pos, poss;
					while (l < r)
					{
						mid = l + r >> 1;
						if (l == r - 1)
						{
							pos = mid;
							break;
						}
						if (lc[mid] == c[i].dis)
						{
							pos = mid;
							break;
						}
						else if (lc[mid] > c[i].dis) r = mid;
						else if (lc[mid] < c[i].dis) l = mid;
					}
					l = 1, r = m;
					while (l < r)
					{
						mid = l + r >> 1;
						if (l == r - 1)
						{
							poss = r;
							break;
						}
						if (lc[mid] == sx)
						{
							poss = mid;
							break;
						}
						else if (lc[mid] > sx) r = mid;
						else if (lc[mid] < sx) l = mid;
					}
					ans.push_back(mp(pos, poss));
					if (mv(c[i].startv, c[i].alpha, lc[poss] - c[i].dis) > v) ans1++;
				}
			}
			else if (c[i].alpha > 0)
			{
				ll sx = mis(c[i].startv, c[i].alpha, v) + c[i].dis;
				if (sx > lc[m]) continue;
				else
				{
					ll l = 1, r = m, mid, pos, poss;
					while (l < r)
					{
						mid = l + r >> 1;
						if (l == r - 1)
						{
							pos = mid;
							break;
						}
						if (lc[mid] == sx)
						{
							pos = mid;
							break;
						}
						else if (lc[mid] < sx) l = mid;
						else if (lc[mid] > sx) r = mid;
					}
					l = 1, r = m;
					while (l < r)
					{
						mid = l + r >> 1;
						if (l == r - 1)
						{
							poss = mid;
							break;
						}
						if (lc[mid] == c[i].dis)
						{
							poss = mid;
							break;
						}
						else if (lc[mid] < c[i].dis) l = mid;
						else if (lc[mid] > c[i].dis) r = mid;
					}
					ans.push_back(mp(poss, pos));
					ans1++;
				}
			}
			else
			{
				if (c[i].startv > v && c[i].dis < lc[m])
				{
					ll pos, l = 1, r = m, mid;
					while (l < r)
					{
						mid = l + r >> 1;
						if (l == r - 1)
						{
							pos = mid;
							break;
						}
						if (lc[mid] == c[i].dis)
						{
							pos = mid;
							break;
						}
						else if (lc[mid] < c[i].dis) l = mid;
						else if (lc[mid] > c[i].dis) r = mid;
					}
					ans.push_back(mp(pos, m));
					ans1++;
				}
			}
		}
		sort(ans.begin(), ans.end(), cmpp);
		pair<int, int> qq = mp(-1, -1);
		for (auto i : ans)
		{
			if (qq.x = -1 && qq.y == -1)
			{
				qq = i;
			}
			else 
			{
				qq.x = max(qq.x, i.x);
				qq.y = min(qq.y, i.y);
				if (qq.x > qq.y) ans2++;
				qq = i;
			}
		}
		cout << ans1 << " " << m - ans2 << endl;
	}
	return 0;
}
