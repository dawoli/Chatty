#include <bits/stdc++.h>

using namespace std;
using ll = long long;
char ch[2000010];


int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	scanf("%s", ch);
	s = ch;
	string ns;
	for (auto c: s) {
		if (isdigit(c)) ns += c;
	}
	sort(ns.begin(), ns.end(), greater<char>());
	printf("%s\n",ns.c_str());
	return 0;
}
