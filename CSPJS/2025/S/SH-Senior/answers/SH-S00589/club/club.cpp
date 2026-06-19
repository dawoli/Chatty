#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
const int N = 100010;
int n, a[N][3], ans, cnt[3], pos[N], k;
vector<int> e;

void solve(){
	scanf("%d", &n);
	ans = 0;
	rep(i, 0, 2) cnt[i] = 0;
	rep(i, 1, n){
		int id = 0;
		rep(j, 0, 2) scanf("%d", &a[i][j]);
		rep(j, 1, 2) if(a[i][j] > a[i][id]) id = j;
		cnt[id]++, ans += a[i][id]; pos[i] = id;
	}
	if(max({cnt[0], cnt[1], cnt[2]}) <= (n>>1)){
		printf("%d\n", ans); return;
	}
	k = 0;
	if(cnt[1] > (n>>1)) k = 1;
	if(cnt[2] > (n>>1)) k = 2;
	e.clear();
	rep(i, 1, n) if(pos[i] == k){
		int t = 0;
		rep(j, 0, 2) if(j != k) t = max(t, a[i][j]);
		e.push_back(t-a[i][k]);
	}
	sort(e.begin(), e.end(), greater<> ());
	rep(i, 0, (cnt[k]-(n>>1))-1) ans += e[i];
	printf("%d\n", ans);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; scanf("%d", &T); while(T--) solve();
	return 0;
}
// g++ -std=c++14 -O2 -Wall -Wextra -Wno-unused-result -fsanitize=undefined club.cpp -o club && ./club
// cp club5.in club.in && time ./club && diff club.out club5.ans -b