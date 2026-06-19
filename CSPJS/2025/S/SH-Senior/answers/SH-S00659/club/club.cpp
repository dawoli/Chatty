#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
ll t, n, ans;
struct Stu {
	ll a[4], maxn, id, minn;
} stu[N];
bool cmp (ll u, ll v) {
	return stu[u].minn < stu[v].minn;
}
void find_minus(ll x) {
	ll id1 = stu[x].id, minm=1e9;
	for (int i = 1; i <= 3; i++) {
		if (i != id1) {
			minm=min(minm, stu[x].maxn-stu[x].a[i]);
		}
	}
	stu[x].minn = minm;
	return;
} 
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		ll cnt[4] = {0,0,0,0};
		vector <ll> ch1;
		vector <ll> ch2;
		vector <ll> ch3; // choose
		cin >> n;
		for (int i=1;i<=n;i++) {
			cin >> stu[i].a[1] >> stu[i].a[2] >> stu[i].a[3];
			
			stu[i].maxn = max(stu[i].a[1], max(stu[i].a[2], stu[i].a[3]));
			if (stu[i].maxn == stu[i].a[1]) stu[i].id=1;
			else if (stu[i].maxn == stu[i].a[2]) stu[i].id=2;
			else stu[i].id=3; 

			ans += stu[i].maxn;
			cnt[stu[i].id]++;
			//ch[stu[i].id].push_back(i);
			if (stu[i].id == 1) ch1.push_back(i);
			if (stu[i].id == 2) ch2.push_back(i);
			if (stu[i].id == 3) ch3.push_back(i);
		}
		for (int i = 1; i <= 3; i++) {
			if (cnt[i] > n/2) {
				if (i == 1) {
					for (int i: ch1) find_minus(i);
					sort(ch1.begin(), ch1.end(), cmp);
					for (int j = 0; j < cnt[1]-n/2; j++) {
						ans -= stu[ch1[j]].minn;
					}
					break;
				}
				else if (i == 2) {
					for (int i: ch2) find_minus(i);
					sort(ch2.begin(), ch2.end(), cmp);
					for (int j = 0; j < cnt[2]-n/2; j++) {
						ans -= stu[ch2[j]].minn;
					}
					break;
				}
				else {
					for (int i: ch3) find_minus(i);
					sort(ch3.begin(), ch3.end(), cmp);
					for (int j = 0; j < cnt[3]-n/2; j++) {
						ans -= stu[ch3[j]].minn;
					}
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
//先都取max，然后挑最小最小差的出去
/*
1499392690
1500160377
1499846353
1499268379
1500579370
*/ 
