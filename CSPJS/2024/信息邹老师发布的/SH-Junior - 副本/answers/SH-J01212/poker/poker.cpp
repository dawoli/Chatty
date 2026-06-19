#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;
bool poker[5][14];
int to_colour(char c) {
	if (c == 'D') return 1;
	else if (c == 'C') return 2;
	else if (c == 'H') return 3;
	else if (c == 'S') return 4;
}
int to_digit(char c) {
	if (isdigit(c)) return c-'0';
	else if (c == 'T') return 10;
	else if (c == 'A') return 1;
	else if (c == 'J') return 11;
	else if (c == 'Q') return 12;
	else return 13;
}
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		cin >> s;
		poker[to_colour(s[0])][to_digit(s[1])] = 1;
	}
	for (int i = 1; i <= 4; i++) for (int j = 1; j <= 13; j++)
		if (!poker[i][j]) ans++;
	printf("%d\n",ans);
	return 0;
}
