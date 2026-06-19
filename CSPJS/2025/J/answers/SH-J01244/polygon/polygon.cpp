#include <bits/stdc++.h>
/*
有点强，绿了吧。
只会做暴力和特殊性质（a_i = 1）
注意到在特殊性质下选边是任意的，只用组合数一下就行了
*//*
luogu 782768 #define int long long
feropen froepen freopen
freopen("polygon.out", "r", stdin);
freopen("polygon.in", "w", stdin);
*//*
风把我不想知道的事情 告诉我
河把我不想忘记的故事 也带走
我摘下我的翅膀 他变成白鸟
白鸟我的白鸟 逆着风去吧
飞过河滩
挥一挥一去不回还
一去不回还
风起水急难靠岸
白鸟白鸟 不要回头啊
你要替我 飞去那地方
一去那地方 那是你我共同故乡
抓住和抓不住的照片 哪张更美
去过的没去过的地方 哪里更远
白鸟我的白鸟 你要飞得更高不要回来啊
若还想与我相见 就来我的梦里边
白鸟过河滩
挥一挥一去不回还
一去不回还
风气水急难靠岸
白鸟白鸟 不要回头啊
你要替我 飞去那地方
一去那地方 那是你我共同故乡
别回来啊
我终将顺流入大海
顺流入大海
海不问我从何处来
长风长风 飘在山海间
白鸟白鸟 一去入苍天
一去入苍天
苍天远在海对面
一去入苍天
苍天远比还更远
*/
using namespace std;
using ll = long long;
const int N = 5005;
const int MOD = 998244353;
struct node{
	int i, x;
	friend bool operator <(node a, node b){
		return a.x < b.x;
	}
} a[N]; int ret2;
int query1(int k){
	int ret = 0; ret2 = 0;
	for (int i = 1; i <= k; i ++){
		ret += a[i].x;
		ret2 = max(ret2, a[i].x);
	}
	return ret;
}
set <set <int> > st;
int fac(int x){
	int ret = 1;
	for (int i = 2; i <= x; i ++) ret = (ret * x) % MOD;
	return ret;
}
int C(int n, int m){
	return fac(m) / ((fac(m - n) * fac(n)));
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n; cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> a[i].x;
		a[i].i = i;
	}
	query1(n);
	if (ret2 == 1){
		int ans = 0;
		for (int i = 3; i <= n; i ++){
			ans += C(i, n);
		}
		cout << ans;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	int ans = 0;
	do{
		for (int k = 3; k <= n; k ++){
			set <int> tmp;
			for (int i = 1; i <= k; i ++){
				tmp.insert(a[i].i);
			}
			if (st.find(tmp) != st.end()) continue;
			if (query1(k) > ret2 * 2){
				st.insert(tmp);
				++ ans;
			}
		}
	} while (next_permutation(a + 1, a + 1 + n));
	cout << ans % 998244353;
}
