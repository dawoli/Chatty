#include <iostream>

std::string s;
int cnt[20];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	std::cin >> s;
	for (int i = 0; i < s.length(); ++i)
		cnt[s[i] - '0']++;
	for (int i = 9; i >= 0; --i)
		for (int j = 0; j < cnt[i]; ++j)
			putchar((char)(i + '0'));
	return 0;
}

