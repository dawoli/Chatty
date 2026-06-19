#include <bits/stdc++.h>
using namespace std;
bool cmp(unsigned short a, unsigned short b)
{
	return a > b;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector <unsigned short> numbers;
	for (char i : s)
		if ('0' <= i && i <= '9')
			numbers.push_back(i - '0');
	string ans = "";
	sort(numbers.begin(), numbers.end(), cmp);
	for (unsigned short i : numbers)
		ans += ('0' + i);
	cout << ans;
	return 0;
}
