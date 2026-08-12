// Problem URL: https://www.luogu.com.cn/problem/T710248?contestId=297106
// Start Time: 2026/7/11 17:13:35

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string ans[21] = {"0", "2", "12", "56", "240", "992", "4032", "16256", "65280", "261632", "1047552", "4192256", "16773120", "67100672", "268419072", "1073709056", "4294901760", "17179738112", "68719214592", "274877382656", "1099510579200"};
int	   n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	cout << ans[n / 2];
	return 0;
}