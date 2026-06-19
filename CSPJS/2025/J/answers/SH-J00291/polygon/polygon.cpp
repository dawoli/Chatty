#include <bits/stdc++.h>
#define int long long
#define mod 998244353
#define maxn 100010
using namespace std;

int n, ans, a[maxn];
void solve() {
	for (int i = 1; i <= 291; i++) {
		cout << "2025 CSP-J/S SH-J00291sunqiwen rp++" << endl;
	}
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	solve();
	return 0;
}




























/*
2025 CSP-J SH-J00291 游记
洛谷用户编号：1646989（sunqiwen）
2025 CSP-J/S RP++
T1 number
我去，CCF第一题竟然这么简单？!
10分钟后敲出一份代码，跑了一下大样例，全过了，应该有100分（三等奖）保底了。
总耗时约20分钟。
T2 seat
怎么看着像数学题？
调了20分钟也没调出来，先吃点脆脆鲨压压惊。（带了4根脆脆鲨）
9:19 终于写出了 O(n^2*m^2) 的代码，1 <= n, m <= 10，所以应该是 O(10^4) 不会T掉。
9:46 过了前两个样例，但第三个挂了。调了快1个小时了/ll。
9:52 过了第一个和第三个样例，第二个却挂了。
10:04 感觉问题一直在第二个和第三个样例中，开启手动模拟找错。
10:31 B题调不出来，摆了
10:58 回来看 B了
11:33 我靠，我好像过所有样例了！/bx
11:35 用 fc 测了一下全过了！
T3 xor
先吃口巧克力平复一下心情。
10:42 骗了特殊性质A的分，后面不会了。/ll
T4 polygon
摆。
估分：[100, 100] + [60, 100] + [0, 5] + [0, 0] = [160, 205]
猜测几等：三等or二等，具体要看B题挂的分数或A题可能会T。
本次 CSP-J 预估难度：红-红/橙-黄-绿/蓝
*/
