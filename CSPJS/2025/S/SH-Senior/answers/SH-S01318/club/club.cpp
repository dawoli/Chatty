#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

const int N = 1e5 + 5;
int a[N][5],n,spea[N],dp[N];
LL ans = 0;
bool flaga = false;

void dfs(int step,LL sum1,LL sum2,LL sum3,int cnt1,int cnt2,int cnt3) {
	if (cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2) return ;
	if (step > n) {
		ans = max(sum1 + sum2 + sum3,ans);
		return ;
	}
	dfs(step + 1,sum1 + a[step][1],sum2,sum3,cnt1 + 1,cnt2,cnt3);
	dfs(step + 1,sum1,sum2 + a[step][2],sum3,cnt1,cnt2 + 1,cnt3);
	dfs(step + 1,sum1,sum2,sum3 + a[step][3],cnt1,cnt2,cnt3 + 1);
	return ;
}

void specialA() {
	for (int i = 1;i <= n;i++) spea[i] = a[i][1];
	sort(spea + 1,spea + n + 1);
	int ans = 0;
	for (int i = n;i > n / 2;i--) ans += spea[i];
	return ;
}

void solve() {
	ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		flaga &= (a[i][2] == 0 && a[i][3] == 0);
	}
	if (flaga) specialA();
	else dfs(1,0,0,0,0,0,0);
	cout << ans << endl;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
