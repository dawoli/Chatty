#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 998244353;
int n, m, c[510];
char s[510];
long long ans;
bool allone = true;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		if (s[i] == '0')
		{
			allone = false;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	sort(c + 1, c + n + 1);
	if (n <= 10)
	{
		do
		{
			for (int i = 1; i <= n; i++)
			{
				cout << c[i] << " ";
			}
			int cnt = 0, qual = 0;
			for (int i = 1; i <= n; i++)
			{
				if (s[i] == '0' || cnt >= c[i])
				{
					cnt++;
				}
				else
				{
					qual++;
				}
			}
			if (qual >= m)
			{
				ans++;
			}
			//cout << ans << endl; 
		}
		while (next_permutation(c + 1, c + n + 1));
		cout << ans << endl;
	}
	if (allone)
	{
		int temp = n;
		for (int i = 1; i <= n; i++)
		{
			if (c[i] == 0)
			{
				temp--;
			}
		}
		n = temp;
		ans = 1;
		for (int i = 1; i <= temp; i++)
		{
			ans *= i;
			ans %= MOD;
		}
		/*for (int i = 1; i <= m; i++)
		{
			ans *= (n - i + 1);
			if (ans % i)
			{
				cout << "??";
			}
			ans /= i;
			ans %= MOD;
		}*/
		cout << ans << endl;
	}//为什么这么难。救命 
	return 0;
}
