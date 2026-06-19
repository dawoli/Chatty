#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

string s; 
int a[1000006], len;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') 
			a[++len] = s[i] - '0';
	}
	sort(a + 1, a + len + 1, cmp);
	for (int i = 1; i <= len; i++)
		printf("%d", a[i]);
	return 0;
}
