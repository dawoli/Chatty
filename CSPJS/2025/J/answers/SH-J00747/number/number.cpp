#include <iostream>
#include <algorithm>
using namespace std;
string s;
int cur, a[1000001];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			a[++cur] = s[i] - '0';
	}
	sort(a + 1, a + cur + 1);
	for (int i = cur; i >= 1; i--) cout << a[i];
	return 0;;
}
/*
uid 1020835
CSPrp++
*/
