#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];
int s[100010];
int maxa;
int ans;

int main()
{
	
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0); 
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s[a[i]]++;
		maxa = max(maxa, a[i]);
	}
	for (int i = 0; i <= maxa; i++)
	{
		ans = max(ans, s[i]);
	}
	cout << ans;
	return 0;
}
