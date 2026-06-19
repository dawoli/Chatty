#include <bits/stdc++.h>
using namespace std;
int n, ans;
bool cards[14][4];
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n; cin.ignore();
	for (int i = 0; i < n; ++i) {
		char a = getchar(), b = getchar();
		cin.ignore();
		int color, num;
		if (a == 'D') color = 0;
		else if (a == 'C') color = 1;
		else if (a == 'H') color = 2;
		else if (a == 'S') color = 3;
		if (b == 'A') num = 1;
		else if (b == 'T') num = 10;
		else if (b == 'J') num = 11;
		else if (b == 'Q') num = 12;
		else if (b == 'K') num = 13;
		else num = b - '0';
		cards[num][color] = 1;
	}
	for (int i = 1; i <= 13; ++i)
		for (int j = 0; j < 4; ++j)
			if (!cards[i][j]) ++ans;
	cout << ans << endl;
	return 0;
}

