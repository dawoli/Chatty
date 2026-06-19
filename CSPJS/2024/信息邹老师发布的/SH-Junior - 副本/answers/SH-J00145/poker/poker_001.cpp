#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
char s[60][2], x;
bool b[20][4];

int huase(char c) {
	if (c == 'D')
		return 0;
	if (c == 'C')
		return 1;
	if (c == 'H')
		return 2;
	return 3;
}

inline void dianshu(char c, char d) {
	int y = huase(c);
	if (d == 'A')
		b[1][y] = true;
	else if (d == 'T')
		b[10][y] = true;
	else if (d == 'J')
		b[11][y] = true;
	else if (d == 'Q')
		b[12][y] = true;
	else if (d == 'K')
		b[13][y] = true;
	else
		b[d - '0'][y] = true;
}

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	scanf("%d%c", &n, &x);
	memset(b, false, sizeof(b));
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i]);
		dianshu(s[i][0], s[i][1]);
	}
	for (int i = 1; i <= 13; i++)
		for (int j = 0; j < 4; j++)
			if (!b[i][j])
				++ans;
	printf("%d\n", ans);
	return 0;
}
