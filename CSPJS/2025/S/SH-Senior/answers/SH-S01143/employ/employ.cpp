/*100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1000 + 10;
const long long modd =998244353;
long long n, m, ans = 1;
long long c[N];
string s;
int main()
{
	//freopen("employ.in", "r", stdin);
	//freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	long long tmp = n;
	for(int i =1; i <= n; ++i)
	{
		cin >> c[i];
	}
	while(tmp!=0)
	{
		ans *= tmp;
		ans %= modd;
		tmp--;
	}
	cout << ans % modd;
	return 0;
}
