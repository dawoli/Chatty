#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, a[N][3];
struct PPL
{
	int d2, d3; // 分别代表此人从社团1转到2、3社团所增加的满意度（可以为负） 
	const bool operator<(const PPL& A) const {
		return max(d2, d3) > max(A.d2, A.d3); 
	}
} b[N];
void solve()
{
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		ans += a[i][0];
		b[i].d2 = a[i][1] - a[i][0];
		b[i].d3 = a[i][2] - a[i][0];
	}
	sort(b + 1, b + n + 1);
	int half = n / 2;
	int sec = 0, third = 0; // 2、3社团目前人数 
	for (int i = 1; i <= n; ++i) { // 第i个人从1社团转移到2、3社团 
		// 先特判： 
		// 若两者转移皆减小ans且可以停止转移，停止转移
		if (i > half) {
			if ((b[i].d2 < 0 || sec == half) && (b[i].d3 < 0 || third == half)) break; 
		}
		if (b[i].d2 >= b[i].d3 && sec < half) { // 可转移到2社团 
			ans += b[i].d2;
			++sec;
		}
		else { // 转移到3社团 
			ans += b[i].d3;
			++third;
		}
	}
	cout << ans << '\n';
}
int main()
{
	// 诈骗寻找迷惑行为大赏的人类：
	// freopen("blub.in", "r", stdin);
	// // freopen("club.in", "r", stdin);
	// 哦对了如果你是迷惑行为大赏欢迎观看我其他代码awa 
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
/*
Never gonna give you up
never gonna let you down~
never gonna turn~
around~
and dessert you~
Fucky fucky CCF~
They are all money coll-
ectors~
China↑
Collecting←
Found→
ation↓ 
*/
