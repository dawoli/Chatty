# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
set <string> S; 

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		S.insert(s);
	}
	printf("%lld\n", 52 - S.size());
	return 0;
}
