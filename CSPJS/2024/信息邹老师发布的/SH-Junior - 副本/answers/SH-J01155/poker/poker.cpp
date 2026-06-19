#include <bits/stdc++.h>
using namespace std;

int n;
bool vis[6][15];
char s[2];

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= 4; i ++)
		for (int j = 1; j <= 13; j ++)
			vis[i][j] = false;
	for (int i = 1; i <= n; i ++) {
		scanf("%s", s);
//		printf("%c %c\n", s[0], s[1]);
		int a, b;
		if (s[0] == 'D') a = 1;
		if (s[0] == 'C') a = 2;
		if (s[0] == 'H') a = 3;
		if (s[0] == 'S') a = 4;
		if (s[1] >= '2' && s[1] <= '9') b = s[1] - '0';
		if (s[1] == 'A') b = 1;
		if (s[1] == 'T') b = 10;
		if (s[1] == 'J') b = 11;
		if (s[1] == 'Q') b = 12;
		if (s[1] == 'K') b = 13;
		vis[a][b] = true;
//		printf("%d %d\n", a, b);
	}
	int ans = 0;
	for (int i = 1; i <= 4; i ++)
		for (int j = 1; j <= 13; j ++)
			if (!vis[i][j]) ans ++;
	printf("%d\n", ans);
	return 0;
} 
