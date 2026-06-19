#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+14;
int n, cnt, ans;
int a[N], dp[N], sum[N];
void query(int tar, int now, int num, int vis){
	//cout << vis << ' ';
	if(vis >= tar){
		if(now > a[tar] && num >= 2){
			cnt ++;
			//cout << "r" <<'\n';
		}
		//cout << "s" << '\n';
		return;
	}
	query(tar, now+a[vis], num+1, vis+1);
	query(tar, now, num, vis+1);
	return;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i ++){
		sum[i] = sum[i-1] + a[i];
	}
	for(int i = 3; i <= n; i ++){
		cnt = 0;
		query(i, 0, 0, 1);
		ans += cnt;
	}
	cout << ans << '\n';
	return 0;
}
