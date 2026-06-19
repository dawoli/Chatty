#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 10;

int n, q;
string str[MAX_N][2];
string fr, to;

bool cmp(int st, int ed, string s) {
	if (ed >= fr.size()) return false;
	for (int i = st, j = 0; i <= ed; i++, j++)
		if (fr[i] != s[j]) return false;
	return true;
}

bool check(int st, int ed, string s) {
	for (int i = 0; i < st; i++)
		if (fr[i] != to[i]) return false;
	for (int i = st, j = 0; i <= ed; i++, j++)
		if (s[j] != to[i]) return false;
	int len = fr.size();
	for (int i = ed + 1; i < len; i++)
		if (fr[i] != to[i]) return false;
	return true;
}

int get(int id) {
	string s1 = str[id][0], s2 = str[id][1];
	int len = fr.size(), siz = s1.size(), cnt = 0;
	for (int i = 0; i < len; i++) {
		if (!cmp(i, i + siz - 1, s1)) continue;
		cnt += check(i, i + siz - 1, s2);
	}
	return cnt;
}

void solve() {
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += get(i);
	printf("%d\n", cnt);
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		cin >> str[i][0] >> str[i][1];
	for (int i = 1; i <= q; i++) {
		cin >> fr >> to;
		solve();
	}
	return 0;
} 
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/ 
