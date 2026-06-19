#include <bits/stdc++.h>
using namespace std;

// all cards needed
// s[0] in {'D', 'C', 'H', 'S'}
// s[1] in {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'}

char first[] = {'D', 'C', 'H', 'S'};
char second[] =  {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	scanf("%d", &n);
	map<char, map<char, bool>> mp;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		mp[s[0]][s[1]] = true;
	}
	int ret = 52;
	for (const auto &i : first) {
		for (const auto &j : second) {
			if (mp[i][j]) ret--;
		}
	}
	printf("%d", ret);
	return 0;
}
