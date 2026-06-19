#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 2e5 + 5, M = 5e6 + 5;
int n, q, ans;
string s[N][2], t[N][2];
ull hs[N][2], ht[M][2], a[N], p = 29;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	a[0] = 1; 
	for (int i = 1; i <= max(n, q); i++)
		a[i] = a[i - 1] * p;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][1] >> s[i][2];
		for (int j = 0; j < s[i][1].size(); j++)
		{
			hs[i][1] = hs[i][1] * p + (s[i][1][j] - 'a');
		}
		for (int j = 0; j < s[i][2].size(); j++)
		{
			hs[i][2] = hs[i][2] * p + (s[i][2][j] - 'a');
		}
//		cout << hs[i][1] << " " << hs[i][2] << endl;
	}
	for (int i = 1; i <= q; i++)
	{
		ans = 0;
		cin >> t[i][1] >> t[i][2];
		for (int j = 1; j <= t[i][1].size(); j++)
		{
			ht[j][1] = ht[j - 1][1] * p + (t[i][1][j - 1] - 'a');
			ht[j][2] = ht[j - 1][2] * p + (t[i][2][j - 1] - 'a');
		}
//		for (int j = 1; j <= 2; j++)
//		{
//			for (int k = 1; k <= t[i][1].size(); k++)
//				cout << ht[k][j];
//			cout << endl;
//		}
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k + s[j][1].size() - 1 <= t[i][1].size(); k++)
			{
				int l = k + s[j][1].size() - 1;
				if (ht[l][1] - ht[k - 1][1] * a[s[j][1].size()] == hs[j][1])
				{
//					cout << "{" << endl;
					if (ht[k - 1][1] * a[t[i][1].size() - k + 1]+ a[t[i][1].size() - l] * hs[j][2] + ht[t[i][1].size()][1] - ht[l][1] * a[t[i][1].size() - l] == ht[t[i][1].size()][2])
					{
//						cout << ht[k - 1][1] * a[t[i][1].size() - k + 1] << " " << a[t[i][1].size() - l] * hs[j][2] << " " << ht[t[i][1].size()][1] << " " << ht[l][1] * a[t[i][1].size() - l] << endl;
//						cout << l << " " << k << endl;
//						cout << "}" << endl;
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
}
/*
1 3
a b
bab bbb
*/
