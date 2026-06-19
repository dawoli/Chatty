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

const int N = 200000 + 10;

int n;
int a[N];

int pre[32];

inline int calc(long long id)
{
	int lo = -1, lz = -1;
	for (int i = 0; i < n; i++)
	{
		if ((id & (1LL << i)) != 0)
			pre[i] = lo, lo = i;
		else
			pre[i] = lz, lz = i;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
//		cerr << i << " " << pre[i] << endl;
		if (pre[i] != -1)
		{
			if (a[i] == a[pre[i]])
				ans += a[i];
		}
	}
//	cerr << "-----" << endl;
//	cerr << id << " " << ans << endl;
	
	return ans;
}

void stupid()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mc = 0;
	for (long long i = 0; i < (1LL << (n + 1)); i++)
		mc = max(mc, calc(i));
	cout << mc << endl;
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);

	int t = 0;
	
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		stupid();
	}

	return 0;
}

