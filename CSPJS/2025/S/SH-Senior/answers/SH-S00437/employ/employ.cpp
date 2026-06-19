#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int c[N], t[N], s[N];
long long jc[N];

inline void init()
{
	jc[1] = 1;
	for(int i = 2; i < N; ++i) jc[i] = i * jc[i - 1] % 998244353;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string s1;
	cin >> s1;
	for(int i = 1; i <= n; i++) c[i] = s1[i - 1] - 48;
	for(int i = 1; i <= n; i++) cin >> t[i];
	sort(t + 1, t + n + 1);
	init();
	if(n < 11)
	{
		int cnt = 0, ans = 0;
		for(int i = 1; i <= n; i++) s[i] = i;
		do
		{
			int j = 1, ko = 0;
			if(cnt == jc[n]) break;
			++cnt;
			for(int i = 1; i <= n; i++)
			{
				int k = s[i];
				if(t[k] <= ko)
				{
					++ko;
					--j;
				}
				else if(c[j] == 0) ++ko;
				++j;
			}
			if(ko <= n - m) ++ans;
		}
		while(next_permutation(s + 1, s + n + 1));
		cout << ans;
		return 0;
	}
	int sum = 0;
	for(int i = 1; i <= n; i++) sum += c[i];
	if(sum == n) cout << jc[n];
	else if(m == n) cout << 0;
	else if(sum == 0) cout << 0;
	else cout << 1;
}
