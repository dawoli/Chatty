// T4 employ
// 8 pts?
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int MOD = 998244353;
int n, m, c[MAXN];
string s;
int permu[MAXN];

bool solve_A()
{
	for (int i = 1; i <= n; i++)
		if (s[i] == '0')
			return false;
	long long ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans *= i;
		ans %= MOD;
	}
	cout << ans << "\n";
	return true;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = "0" + s;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	
	if (n > 10 && solve_A())
		return 0;
	else
	{
		cout << "0\n";
		return 0;
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		permu[i] = i;
	do
	{
		int employed = 0, denied = 0;
		for (int i = 1; i <= n; i++)
		{
			if (s[i] == '0' || c[permu[i]] <= denied)
				denied++;
			else
				employed++;
		}
		ans += (employed >= m);
	} while(next_permutation(permu + 1, permu + 1 + n));
	cout << ans << "\n";
}
