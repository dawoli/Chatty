#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
unordered_set<int> az;
const int MAXN = 100005;
int ans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
struct stu {
	int s[3], num;
	double per[3];
}a[MAXN], a1[MAXN], a2[MAXN], a3[MAXN];
bool cmp(stu x, stu y) {
	if(x.s[0] >= (x.s[0] + x.s[1] + x.s[2]) / 2 && y.s[0] < (y.s[0] + y.s[1] + y.s[2]) / 2) return 1;
	if(x.s[0] < (x.s[0] + x.s[1] + x.s[2]) / 2 && y.s[0] >= (y.s[0] + y.s[1] + y.s[2]) / 2) return 0;
	return x.s[0] + x.s[1] + x.s[2] > y.s[0] + y.s[1] + y.s[2];
}
int main() {
	freopen("club1.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--) {
		ans = 0;
		cnt1 = 0, cnt2 = 0, cnt3 = 0;
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i].s[0] >> a[i].s[1] >> a[i].s[2];
		}
		sort(a, a + n, cmp);
		for(int i = 0; i < n; i++) {
			int  am = -1;
			stu x = a[i];
			if(x.s[0] >= (x.s[0] + x.s[1] + x.s[2]) / 2 && cnt1 < n / 2)	am = 0;
			else if(x.s[1] >= (x.s[0] + x.s[1] + x.s[2]) / 2 && cnt2 < n / 2)	am = 1;
			else if(x.s[2] >= (x.s[0] + x.s[1] + x.s[2]) / 2 && cnt3 < n / 2)	am = 2;
			else {
				int a1 = x.s[1], a2 = x.s[2], a3 = x.s[3];
				if(a1 > a2 && a1 > a3 && cnt1 < n / 2)	am = 0;
				else if((a2 > a1 && a2 > a3 && cnt2 < n / 2) || (cnt1 > n / 2 && a2 > a3))	am = 1;
				else if((a3 > a1 && a3 > a2 && cnt3 < n / 2) || (cnt2 > n / 2 && a3 > a2))	am = 2;
				else  {
					ans += max(a1, max(a2, a3));
					continue;
				}
				ans += x.s[am];
				if(am == 0)	cnt1++;
				if(am== 1)	cnt2++;
				if(am == 2)	cnt3++;
			}
		}
		cout << ans << endl;
	}
}
