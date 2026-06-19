// number

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 10;
int gA[N];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	string s;
	cin >> s;
	
	int len = s.length(), m = 0;
	for (int i = 0; i < len; i++)
		if ('0' <= s[i] && s[i] <= '9') gA[++m] = s[i] - '0';
	
	sort(gA + 1, gA + m + 1, greater<int>());
	
	for (int i = 1; i <= m; i++) cout << gA[i];
	cout << endl;
	
	return 0;
} 
