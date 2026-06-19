#include <bits/stdc++.h>
using namespace std;
set<pair<char, char>> s;

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	scanf("%d", &n);
	while (n--) {
		char a[5];
		scanf("%s", a);
		s.insert(make_pair(a[0], a[1]));
	}
	printf("%d\n", 52 - s.size());
	return 0;
}
