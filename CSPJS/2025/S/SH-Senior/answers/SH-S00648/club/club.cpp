#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
ll T, n, a[N][5], ans;
ll f[N], s[N], t[N];
int lf, ls, lt;  //第 1，2，3 部门的理论最大人数 (不是最终答案的人数)

void init() {
//	memset(f, 0, sizeof(f));
//	memset(s, 0, sizeof(f));
//	memset(t, 0, sizeof(f));
	lf = ls = lt = 0;
	ans = 0;
}

void getsec(int i) {  // 按理论的最大满意度进行人员分配 
// 注意每次不等式中的等号，带上等号不会影响最终的答案，但如果不加
// 那碰到 a[i][1] = a[i][2] = a[i][3] 的情况，会将这个人跳过，不计入答案中 
	if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {  // 部门1
		ans += a[i][1];
		f[++ lf] = min(a[i][1] - a[i][2], a[i][1] - a[i][3]);
	}
	else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {  // 部门2
		ans += a[i][2];
		s[++ ls] = min(a[i][2] - a[i][1], a[i][2] - a[i][3]);
	}
	else if (a[i][3] >= a[i][1] && a[i][3] >= a[i][2]) {  // 部门3
		ans += a[i][3];
		t[++ lt] = min(a[i][3] - a[i][1], a[i][3] - a[i][2]);
	}
}

void reget(int op) {
	int i = 0;
	switch(op) {
		case 1:{
			sort(f + 1, f + lf + 1);
			while (lf - i > n / 2) {
				i ++;
				ans -= f[i];
			}
			break;
		}
		case 2:{
			sort(s + 1, s + ls + 1);
			while (ls - i > n / 2) {
				i ++;
				ans -= s[i];
			}
			break;
		}
		case 3:{
			sort(t + 1, t + lt + 1);
			while (lt - i > n / 2) {
				i ++;
				ans -= t[i];
			}
			break;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%lld", &T);
	while (T --) {
		init();
		scanf("%lld", &n);
		for (int i = 1; i <= n; ++ i) {
			scanf("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
			getsec(i);
		}
		// 调试 
//		cout << "f: ";
//		for (int i = 1; i <= lf; ++ i) cout << f[i] << " ";
//		cout << "\n";
//		cout << "s: ";
//		for (int i = 1; i <= ls; ++ i) cout << s[i] << " ";
//		cout << "\n";
//		cout << "t: ";
//		for (int i = 1; i <= lt; ++ i) cout << t[i] << " ";
//		cout << "\n\n";
		// 调试 
		if (lf > n / 2) reget(1);
		if (ls > n / 2) reget(2);
		if (lt > n / 2) reget(3);
		printf("%lld\n", ans);
	}
	return 0;
} 
