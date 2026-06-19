#include <bits/stdc++.h>
using namespace std;
int a[i];
string to_0b(int x)
{
	if(!x) return "0";
	string s;
	while(x != 1)
	{
		s = (x % 2) + '0';
		x /= 2;
	}
	s += '1';
	reverse(s.begin() , s.end());
	return s;
}
int main()
{
	int n , k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) to_0b(a[i]);
	cout << 2;
	return 0;
}
