#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
char s[N];
int a[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	for (int i = 1; s[i]; ++i)
		if (isdigit(s[i])) ++a[s[i] - '0'];
	for (int i = 9; i >= 0; --i)
		for (int j = 1; j <= a[i]; ++j) putchar(i + '0');
	puts("");
	return 0;
}
