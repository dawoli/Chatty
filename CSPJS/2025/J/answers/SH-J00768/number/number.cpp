#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

string s;
int num[1000010];
int index;

bool CMP(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) if (s[i] >= '0' && s[i] <= '9') num[++index] = s[i] - '0';
	sort(num + 1, num + index + 1, CMP);
	if (num[1] == 0) cout << 0;
	else for (int i = 1; i <= index; i++) cout << num[i];
	return 0;
}
