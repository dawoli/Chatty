#include <bits/stdc++.h>
using namespace std;
int C(int x, int y)
{
	int ans1 = 1, ans2 = 1, ans3 = 1;
	int p = x - y;
	while(x--) ans1 *= x; //x!
	while(y--) ans2 *= y; //y!
	while(p--) ans3 *= p; //(x-y)!
	return ans1 / (ans2 * ans3);
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	string s; cin >> s;
	while (n--) 
	{
		int k;
		cin >> k;
	}
	//如果每个人得到的试题难度均为1，那么每个人均能做出，不再需要考虑耐心值
	//此时录取前 m 个人，也就是 n 个人当中任选 m 人 
	cout << C(n, m) << endl;
	return 0;
}
