#include <bits/stdc++.h>
#define For(i, a, b) for (int i = (a); i <= (b); i ++)
#define foR(i, a, b) for (int i = (a); i >= (b); i --)
#define int long long
using namespace std;
int T;
//f_i：1 ~ i 染色，最小代价
/*
结论1：？？？？？？？
那么
3 1 2 3 1 2 3 1 3？


a[i] 对答案做贡献： 
假设某个数染成蓝对

1 染成蓝 3 然成红

两个相同的颜色

w_l_r  若 l r 同色且与 l + 1 r - 1 都异色，则获得 w_l_r 值。

a[l, r] 把 [l, r] 都染成同色，所得到的

一定只能用最后面那个吗？？？

考虑反证，如果用前面的某一个，那么一定是为了让第 r - 1 个和 r - 2 配对，若 r - 1 和 r - 3。

中间插一个异色不影响答案！！！！

同色区间越小越划算，如果想让 r - 1 和 r - 2 配对，这已经考虑过了

如果让 r - 1 和 r - 3 配对，不如改掉中间 r - 2 更划算（对）

证毕

结论 2：同数字染成同色？？？

考虑两个大数区间（必须要）

小数区间（需要考虑的）若只与一个相交，则没有影响。
若与两个都相交，则左边染成蓝，右边染成红


18 1 18 46 18 46 18 46 1 46

18 染成红，46 染成蓝

左 1 染成 蓝
右 1 染成 红

最优。所以这个结论错误



a[i] 不对答案做贡献，则染成红或蓝，与前面一个是否相同不管，但是与前一个 a[i] 是否相同不需要管

你想染成啥就是啥，如果对答案贡献了就算到上一种情况里了，不可能更大。

如果对答案没有贡献那么是正确的

solve
*/
int n, ans;
int a[200005], lst[1000005];
int mx[800005], tag[800005];
void pushdown (int l, int r, int k) {
	if (tag[k]) {
		mx[k << 1] += tag[k];
		mx[k << 1 | 1] += tag[k];
		tag[k << 1] += tag[k];
		tag[k << 1 | 1] += tag[k];
		tag[k] = 0;
	}
}
int query (int l, int r, int k, int x, int y) {
	if (x > y) return 0;
	if (x <= l && y >= r) return mx[k];
	pushdown (l, r, k);
	int mid = l + r >> 1, res = 0;
	if (x <= mid) res = query (l, mid, k << 1, x, y);
	if (y > mid) res = max (res, query (mid + 1, r, k << 1 | 1, x, y) );
	return res;
}
int query2 (int l, int r, int k, int x) {
	if (x == 0) return 0;
	if (l == r) return mx[k];
	pushdown (l, r, k);
	int mid = l + r >> 1;
	if (x <= mid) return query2 (l, mid, k << 1, x);
	return query2 (mid + 1, r, k << 1 | 1, x);
}
void update (int l, int r, int k, int x, int y, int v) {
	if (x > y) return;
	if (x <= l && y >= r) {
		tag[k] += v;
		mx[k] += v;
		return;
	}
	int mid = l + r >> 1;
	if (x <= mid) update (l, mid, k << 1, x, y, v);
	if (y > mid) update (mid + 1, r, k << 1 | 1, x, y, v);
	mx[k] = max (mx[k << 1], mx[k << 1 | 1]);
}
void update2 (int l, int r, int k, int x, int v) {//单点修，修成固定值
	if (x == 0) return;
	if (l == r) {
		mx[k] = max (mx[k], v);
		return;
	}
	pushdown (l, r, k);
	int mid = l + r >> 1;
	if (x <= mid) update2 (l, mid, k << 1, x, v);
	else update2 (mid + 1, r, k << 1 | 1, x, v);
	mx[k] = max (mx[k << 1], mx[k << 1 | 1]);
}
void print (int l, int r, int k) {
	if (l == r) {
		cout << mx[k] << ' ';
		return;
	}
	pushdown (l, r, k);
	int mid = l + r >> 1;
	print (l, mid, k << 1);
	print (mid + 1, r, k << 1 | 1);
}
void solve () {
	scanf ("%lld", &n);
	For (i, 1, 4 * n) mx[i] = tag[i] = 0;
	For (i, 1, 1000000) lst[i] = 0;
	For (i, 1, n) scanf ("%lld", &a[i]);
	ans = 0;
	lst[a[1] ] = 1;
	For (i, 2, n) {
		int vtmp = query (1, n, 1, 1, i - 2), vtmp2 = query2 (1, n, 1, lst[a[i] ]);
		//选择与上一个一样的颜色
		if (a[i] == a[i - 1]) {
			update (1, n, 1, 1, i - 2, a[i]);
		}//如果不相等，一样也没什么用，不需要改
		//选择与上一个不一样的颜色
		//不这么干
		update2 (1, n, 1, i - 1, vtmp);
		//这么干，要求 lst[a[i] ] != i - 1 
		if (lst[a[i] ] && lst[a[i] ] != i - 1) update2 (1, n, 1, i - 1, vtmp2 + a[i]);
		lst[a[i] ] = i;
//		For (j, 1, i - 1) {
//			mx (f[i][j], f[i - 1][j] + (a[i] == a[i - 1]) * a[i]);//一样
//			mx (f[i][i - 1], f[i - 1][j] + (a[i] == a[j]) * a[i]);//不一样
			
			//a[i] == a[j] 仅有可能在 j = lst[a[i] ] 成立
			/*
			case1：选择与上一个一样的颜色
			如果 a[i] != a[i - 1]，不需要更新。
			对于所有 f[i][j]，都加上 a[i]。(j ∈ [1, i - 2])
			case2：选择与上一个不一样颜色
			则为 f[i][i - 1]，它等于 f[i - 1][lst[a[i] ] + a[i]
			如果不这么干，那么选择 max (f[i - 1][j], j ∈ [1, i - 2])
			*/
			//此时套用结论，如果颜色相等，那么一定是与上一个相等
	}
	printf ("%lld", mx[1]);
}
signed main () {
	freopen ("color.in", "r", stdin);
	freopen ("color.out", "w", stdout);
	cin >> T;
	while (T --) {
		solve ();
		cout << '\n';
	}
	return 0;
}
