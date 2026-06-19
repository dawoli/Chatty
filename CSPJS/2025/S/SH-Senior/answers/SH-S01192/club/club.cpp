#include <bits/stdc++.h>
using namespace std;
struct students {
	int id, val;
}a1[50001], a2[50001], a3[50001];
int T, n, a[100001][4], ans;
bool cmp(students x, students y) {return x.val >= y.val;}
string solve(int x) {
	string s = "";
	while (x) {
		char temp = (x % 3) + '0';
		x /= 3;
		s = temp + s;
	}
	while (s.size() < n) s = "0" + s;
	return s;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		cin >> n;
		int sumA, sumB, sumC;
		bool specialA = true;
		bool specialB = true;
		for (int i = 1; i <= n; i++) {
			cin >> a1[i].val >> a2[i].val >> a3[i].val;
			a[i][1] = a1[i].val;
			a[i][2] = a2[i].val;
			a[i][3] = a3[i].val;
			a1[i].id = i, a2[i].id = i, a3[i].id = i;
			sumA += a1[i].val;
			sumB += a2[i].val;
			sumC += a3[i].val;
			if (a[i][3] != 0) {
				specialA = false;
				specialB = false;
			} 
			if (a[i][2] != 0) specialA = false;
		}
		// SPECIAL-A : 1 points; &score 5
		if (specialA) {
//			cout << "init:specialA\n"; 
			sort(a1 + 1, a1 + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) ans += a1[i].val;
			cout << ans << "\n";
			continue;
		}
		int maxn = -1, sum = 0;
		for (int i = 1; i <= n; i++) {
			string t = solve(i);
			sum = 0;
			for (int j = n - 1, cur = 1; j >= 0; j--, cur++) {
				sum += a[cur][t[j] - '0' + 1];
			}
//			cout << sum << endl;
			if (sum > maxn) maxn = sum;
		}
		cout << maxn << endl;
		// SPECIAL-B : 3 points; &score 15
//		if (specialB) {
////			cout << "init:specialB\n";
//			sort(a1 + 1, a1 + n + 1, cmp);
////			sort(a2 + 1, a2 + n + 1, cmp);
//			int cntA = 0, cntB = 0;
//			for (int i = 1; i <= n; i++) {
//				double firNUMer = 1.0 * a1[i].val / sumA; 
//				double secNUMer = 1.0 * a[a1[i].id][2] / sumB;
////				cout << i << " " << firNUMer << " " << secNUMer << "\n"; 
//				if (firNUMer >= secNUMer && cntA < n / 2) {
//					cntA++;
//					ans += a1[i].val;
////					cout << a1[i].val << " " << i << "\n";
//				} else if (firNUMer < secNUMer && cntB < n / 2) {
//					cntB++;
//					ans += a[a1[i].id][2]; 
////					cout << a[a1[i].id][2] << " " << a1[i].id << "\n";
//				}
//			}
//			cout << ans << endl;
//			continue;
//		}
	} 
	return 0;
} 
