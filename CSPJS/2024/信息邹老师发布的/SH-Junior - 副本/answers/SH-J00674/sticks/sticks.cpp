#include<bits/stdc++.h>
using namespace std;
long long t, n;
void solve1()
{
	long long g = n / 7;
	for(int i = 1; i <= g; i++)
	{
		cout << 8;
	}
	cout << endl;
}
void solve2()
{
	if(n == 0)cout << -1 << endl;
	else if(n == 1) cout << -1 << endl;
	else if(n == 2) cout << 1 << endl;
	else if(n == 3) cout << 7 << endl;
	else if(n == 4) cout << 4 << endl;
	else if(n == 5) cout << 2 << endl;
	else if(n == 6) cout << 6 << endl;
	else if(n == 8) cout << 10 << endl;
	else if(n == 9) cout << 18 << endl;
	else if(n == 10) cout << 22 << endl;
	else if(n == 11) cout << 20 << endl;
	else if(n == 12) cout << 28 << endl;
	else if(n == 13) cout << 68 << endl;
	else if(n == 15) cout << 168 << endl;
	else if(n == 16) cout << 188 << endl;
	else if(n == 17) cout << 228 << endl;
	else if(n == 18) cout << 208 << endl;
	else if(n == 19) cout << 288 << endl;
	else if(n == 20) cout << 688 << endl;
	else if(n == 22) cout << 1688 << endl;
	else if(n == 23) cout << 1888 << endl;
	else if(n == 24) cout << 2288 << endl;
	else if(n == 25) cout << 2688 << endl;
	else if(n == 26) cout << 2888 << endl;
	else if(n == 27) cout << 6888 << endl;
	else if(n == 29) cout << 16888 << endl;
	else if(n == 30) cout << 18888 << endl;
	else if(n == 31) cout << 22888 << endl;
	else if(n == 32) cout << 26888 << endl;
	else if(n == 33) cout << 28888 << endl;
	else if(n == 34) cout << 68888 << endl;
	else if(n == 36) cout << 168888 << endl;
	else if(n == 37) cout << 188888 << endl;
}
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n % 7 == 0)
		{
			solve1();
		}
		else if(n <= 50)
		{
			solve2();
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
