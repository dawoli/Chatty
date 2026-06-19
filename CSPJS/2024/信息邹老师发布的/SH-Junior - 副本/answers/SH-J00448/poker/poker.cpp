#include <bits/stdc++.h>
using namespace std;

int n, ans;
bool flag[6][21];

int col(char ch) {
	//D C H S
	//1 2 3 4
	if (ch == 'D')
		return 1;
	if (ch == 'C')
		return 2;
	if (ch == 'H')
		return 3;
	if (ch == 'S')
		return 4;
	return 0;
}

int num(char ch) {
	//A 2 3 4 5 6 7 8 9 T  J  Q  K
	//1 2 3 4 5 6 7 8 9 10 11 12 13
	if (ch == 'A')
		return 1;
	if (ch == 'T')
		return 10;
	if (ch == 'J')
		return 11;
	if (ch == 'Q')
		return 12;
	if (ch == 'K')
		return 13;
	return ch - '0';
}

int main() {
	freopen("poker.in.txt", "r", stdin);
	freopen("poker.out.txt", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= 4; i++)
		memset(flag[i], false, sizeof(flag[i]));
	for (int i = 1; i <= n; i++) {
		char s[11]; scanf ("%s", s + 1);
		flag[col(s[1])][num(s[2])] = true;
	}
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 13; j++)
			if (!flag[i][j]) ans++;
	printf ("%d\n", ans);
	//printf ("Time : %d", clock());
	return 0;
}
