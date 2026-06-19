#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
unordered_set <string> s;
string t;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	while (n--)
	{
		cin >> t;
		s.insert(t);
	}
	cout << 52 - s.size();
} 
