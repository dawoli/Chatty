#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> num;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			num.push_back(s[i] - '0');
	sort(num.begin(), num.end());
	reverse(num.begin(), num.end());
	for (auto i : num)
	{
		cout << i;
	}
	return 0;
}
