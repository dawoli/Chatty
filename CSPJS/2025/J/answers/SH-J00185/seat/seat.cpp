#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 205;
int a, b; // 我只关心小A的分数和其他人的分数这两种情况 
int rk = 1; // 维护小A的排名，默认开始时小A的排名为1 
int n, m;

signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	
	cin >> a; // 先输入小A的分数 
	for (int i = 2; i <= n*m; i++)
	{
		cin >> b;
		rk += (b > a ? 1 : 0); // 如果有人分数比小A大，那么小A掉下去一名 
	}
	
	// 计算小A的座位
	int c = ceil(rk * 1.0 / n); // 保留列数 
	int tmp = (rk % n ? rk % n : n); // 保留行数
	int r = (c % 2 ? tmp : n - tmp + 1); // 计算行数 
	
	cout << c << ' ' << r << '\n';
	
}
