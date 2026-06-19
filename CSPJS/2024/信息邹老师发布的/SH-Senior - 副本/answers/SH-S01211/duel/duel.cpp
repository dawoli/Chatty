#include <bits/stdc++.h>
using namespace std;
int n, a[100010], m[100010];
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		m[a[i]]++;
	}
	cout << *max_element(m + 1, m + 100010);
	return 0;
}
