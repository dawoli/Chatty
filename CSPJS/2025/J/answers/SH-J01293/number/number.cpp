#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
string s;
int A[1000005], n = 0;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			A[++n] = s[i] - '0';
	sort(A + 1, A + 1 + n);
	for (int i = n; i >= 1; i--)
		cout << A[i];
	cout << endl;
	return 0;
}
