// Problem URL: https://www.luogu.com.cn/contest/311135
// Finish Time: 2026/9/6 14:06:57 AC
// Start Time: 2026/9/6 13:57:20

#include <bits/stdc++.h>
#define int ull
#define endl '\n'
using namespace std;
typedef unsigned long long ull;
const int				   MAXA = 5e8;

int n;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	if (n > MAXA)
		cout << "O(1)" << endl;
	else if (n > sqrt(MAXA))
		cout << "O(n)" << endl;
	else
		cout << "O(n^2)" << endl;
	return 0;
}

// Deep in the dark, I don't need the light
// There's a ghost inside me
// It all belongs to the other side
// We live, we love, we lie