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

const int N = 100000 + 10;
const int T = 21;

int n, m, L;
int vm; // maximum velocity
int nt; // now t

int d[T][N], v[T][N], a[T][N];
int p[T][N];

typedef long long ll;

inline bool os(int i, int pos) // overspeed
{
	if (pos < d[nt][i])
		return false;
	return (v[nt][i] * v[nt][i] + 2 * a[nt][i] * (pos - d[nt][i])) > (vm * vm);
}

inline double mds(int i) // minimum dis
{
	return (double)(vm * vm - v[nt][i] * v[nt][i]) / (double)(2 * a[nt][i]);
}

//inline double speed(int i, int pos)
//{
//	if ( < 0)
//		return -1;
//	return sqrt((double)(v[nt][i] * v[nt][i] + 2 * a[nt][i] * pos));
//}

//bitset<N> bs[T];
vector<int> bs[T];
int lft[T][N], rgt[T][N];

int covs() // count of overspeed
{
	int cnt = 0;
	int pmax = p[nt][m - 1];
//	cerr << pmax << endl;
	for (int i = 0; i < n; ++i)
	{
		if (a[nt][i] >= 0)
		{
//			cerr << i << " " << v[nt][i] * v[nt][i] + 2 * a[nt][i] * (pmax - d[nt][i]) << endl;
			if (!os(i, pmax))
			{
//				debug("i=%d,os=F\n", i);
				continue;
			}
			cnt++;
//			bs[nt][i] = true;
			bs[nt].push_back(i);
			rgt[nt][i] = m - 1;
		}
		else if (a[nt][i] < 0)
		{
			int id = upper_bound(p[nt], p[nt] + m, d[nt][i]) - p[nt];
			if (id >= m)
				continue;
			if (os(i, p[nt][id]))
			{
				cnt++;
//				bs[nt][i] = true;
				bs[nt].push_back(i);
				lft[nt][i] = id;
			}
		}
		else {}
	}
	return cnt;
}

struct Node
{
	int l;
	int r;
	int pr;
	int nxt;
};
vector<Node> nd;

bitset<30> bt;
inline bool check()
{
	for (int i = 0; i < m; i++)
	{
		if (bt[i])
		{
			for (int j = 0; j < bs[nt].size(); j++)
			{
				int nw = bs[nt][j];
				if (lft[nt][nw] <= i && rgt[nt][nw] >= i)
					return false;
			}
		}
	}
	return true;
}

inline int stupid()
{
	int ans = 0;
	for (long long id = 0; id < (1LL << (m + 1)); id++)
	{
		int cnt = 0;
		for (int i = 0; i < m; i++)
		{
			bt[i] = ((id & (1LL << i)) != 0);
			cnt += bt[i];
		}
		if (ans >= cnt)
			continue;
		if (check())
			ans = max(ans, cnt);
	}
	return ans;
}

bool ok(int id)
{
	return true;
}

int mxrm() //maximum num of removing
{
	if (m <= 25)
		return stupid();

	for (int i = 0; i < bs[nt].size(); i++)
	{
		int id = bs[nt][i];
		if (a[nt][id] > 0)
		{
			int mpos = (int)ceil(mds(id)) + d[nt][id];
			int idp = upper_bound(p[nt], p[nt] + m, mpos) - p[nt];
			lft[nt][i] = idp;
		}
		else if (a[nt][id] < 0)
		{
			int mpos = (int)floor(mds(id)) + d[nt][id];
			int idp = lower_bound(p[nt], p[nt] + m, mpos) - p[nt];
			rgt[nt][i] = idp;
		}
		else
		{
			int idp = upper_bound(p[nt], p[nt] + m, d[nt][id]) - p[nt];
			lft[nt][i] = idp;
		}
	}
	
	int l = 0, r = m;
	int mid = 0;
	while(l <= r)
	{
		mid = l + (l - r) / 2;
		if (ok(mid))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	
	return l;
}

inline bool ftrA()
{
	for (int i = 0; i < n; ++i)
	{
		if (a[nt][i] != 0)
			return false;
	}
	return true;
}

inline bool ftrAB()
{
	for (int i = 0; i < n; ++i)
	{
		if (a[nt][i] < 0)
			return false;
	}
	return true;
}

void solve()
{
	cin >> n >> m >> L >> vm;
	for (int i = 0; i < n; ++i)
		scanf("%d%d%d", &d[nt][i], &v[nt][i], &a[nt][i]);
	for (int i = 0; i < m; ++i)
		scanf("%d", &p[nt][i]);
	sort(p[nt], p[nt] + m);
	int a1 = covs();
	cout << a1 << " ";
	if (a1 == 0 || ftrAB())
	{
//		cerr << nt << endl;
		if (a1 == 0)
			cout << m << endl;
		else
			cout << m - 1 << endl;
	}
	else
	{
		cout << 3 << endl;
//		cout << mxrm() << endl;
	}
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);

	int t = 0;
	
	cin >> t;
	for (nt = 0; nt < t; nt++)
	{
		solve();
	}

	return 0;
}

