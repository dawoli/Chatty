#include <cstdio>
#include <set>

typedef long long ll;
const int N = 5e5 + 10;

ll n, k;
ll a[N], x[N];

std::set<ll> st;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld %lld", &n, &k);
	for (int i = 1; i <= n; ++i)
	{
		int tmp;
		scanf("%lld", &tmp);
		x[i] = x[i - 1] ^ tmp;
	}
	ll cnt = 0;
	st.insert(x[0]);
	for (int i = 1; i <= n; ++i)
	{
		if (st.find(k ^ x[i]) != st.end())
		{
			cnt++;
			st.clear();
		}
		st.insert(x[i]);
	}
	printf("%lld", cnt);
	return 0;
}

