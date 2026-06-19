#include<cstdio>
#include<iostream>
#include<algorithm>
#define rep(i, x, y) for (int i = (x); i <= (y); i++)
using std::cin; using std::cout;
const int maxN = 100007, LG = 27;
int a[maxN], c[maxN], d[LG][maxN], x[10], tmp[maxN], lst[maxN];
int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	rep(i, 1, n)
		cin >> a[i];
	rep(i, 1, m)
		cin >> c[i];
	int k = 31 - __builtin_clz(n);
	if (n != (1 << k))
		k++;
	rep(i, 1, k)
		rep(j, 1, 1 << (k - i)) {
			char ch; cin >> ch;
			while (ch != '0' && ch != '1')
				cin >> ch;
			d[i][j] = ch - '0';
		}
	int T;
	cin >> T;
	while (T--) {
		rep(i, 0, 3)
			cin >> x[i];
		rep(i, 1, n)
			a[i] ^= x[i%4];
		int ans = 0;
		rep(t, 1, m) {
			rep(j, 1, c[t])
				lst[j] = j;
			int cur = std::__lg(c[t]);
			rep(i, 1, cur)
				rep(j, 1, 1 << (cur - i)) {
					if (d[i][j])
						std::swap(lst[2*j-1], lst[2*j]);
					if (a[lst[2*j-1]] < i)
						tmp[j] = lst[2*j];
					else
						tmp[j] = lst[2*j-1];
					lst[j] = tmp[j];
				}
			ans ^= (t * lst[1]);
		}
		cout << ans << "\n";
	}
	return 0;
}
// Luogu 670677
// qwq
// 我要上迷惑行为大赏
// orz Withers openwld Line_12 lgvc
/*
银临/河图 是风动
 
若非万种飞烟都过眼
怎会迷恋巫山的那一片
若非海枯石烂想看两相厌
怎又会弱水涨桑田

以为衔泥归来旧堂前
是我似曾相识的那一面
以为积雪成川有孤鸿不知疲倦
印下你岁月的足尖

聚似飞霜不肯融
散若尘埃各西东
痴人说着梦
都道情之所钟
求不得就偏宠
心猿意马就相拥
是风动 还是幡动
轮回难道就不同

你是我身外
化白云任去来
推开孤城万里
吹渡春风几千载
我是你途中
有青山撞入怀
不动声色见你如是才自在

难道逆水行舟的执念
是你刻在船舷的那一剑
难道临渊而羡又纷纷得鱼忘筌
也值我缘木求此愿

 
聚似飞霜不肯融
散若尘埃各西东
痴人说着梦
都道情之所钟
求不得就偏宠
心猿意马就相拥
是风动 还是幡动
轮回难道就不同

你是我身外
化白云任去来
推开孤城万里
吹渡春风几千载
我是你途中
有青山装入怀
不动声色见你如是才自在

你在我身畔
听竹林正摇曳
侵如野火纷然
震如千军雷声绽
我在你此岸
立风雨安如山
不动于心见你如是才自在
*/
